#include "light.h"
#include <math.h>

namespace RayTracer {

Point_Light point_light(Point position, Color intensity)
{
    return { position, intensity };
}

Color lighting(const Material &material, const Point_Light &light, const Point &position,
               const Vector &eye, const Vector &normal)
{
    Color effective_color = color_hadamard(material.color, light.intensity);
    // Color effective_color = material.color * light.intensity;

    Vector light_dir = vector_normalized(point_sub(light.position, position));
    // Vector light_dir = vector_normalized(light.position - position);

    Color ambient = color_mul(effective_color, material.ambient);
    // Color ambient = effective_color * material.ambient;

    Color diffuse;
    Color specular;

    float light_dot_normal = vector_dot(light_dir, normal);
    if (light_dot_normal < 0.0f) {
        diffuse = color_create(0, 0, 0);
        specular = color_create(0, 0, 0);
    } else {
        diffuse = color_mul(effective_color, material.diffuse * light_dot_normal);
        // diffuse = effective_color * material.diffuse * light_dot_normal;

        Vector reflect_dir = vector_reflect(vector_neg(light_dir), normal);
        // Vector reflect_dir = vector_reflect(-light_dir, eye);

        float reflect_dot_eye = vector_dot(reflect_dir, eye);

        if (reflect_dot_eye <= 0.0f) {
            specular = color_create(0, 0, 0);
        } else {
            float factor = (float)pow(reflect_dot_eye, material.shininess);
            specular = color_mul(light.intensity, material.specular * factor);
            // specular = light.intensity * material.specular * factor;
        }
    }

    return color_add(ambient, color_add(diffuse, specular));
    // return ambient + diffuse + specular;
}

}

