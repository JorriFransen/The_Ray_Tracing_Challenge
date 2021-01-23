#pragma once

#include "color.h"

namespace RayTracer {

struct Material
{
    Color color = color_create(1, 1, 1);
    float ambient = 0.1f;
    float diffuse = 0.9f;
    float specular = 0.9f;
    float shininess = 200.0f;
};

Material material_create();
Material material_create(Color color, float ambient, float diffuse, float specular,
                         float shininess);

bool material_eq(const Material &lhs, const Material &rhs);

}
