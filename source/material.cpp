#include "material.h"

namespace RayTracer {


Material material_create()
{
    Material m;
    return m;
}

Material material_create(Color color, float ambient, float diffuse, float specular,
                         float shininess)
{
    return { color, ambient, diffuse, specular, shininess };
}

bool material_eq(const Material &lhs, const Material &rhs)
{
    if (!color_eq(lhs.color, rhs.color)) return false;
    if (lhs.ambient != rhs.ambient) return false;
    if (lhs.diffuse != rhs.diffuse) return false;
    if (lhs.specular != rhs.specular) return false;
    if (lhs.shininess != rhs.shininess) return false;
    return true;
}

}
