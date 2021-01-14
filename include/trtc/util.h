
#pragma once

#include <inttypes.h>

const float EPSILON = 0.00001f;

float abs_f(float x);
bool float_eq(float lhs, float rhs);

struct String
{
    char *data = nullptr;
    int64_t length = -1;
};

String string_ref(const char *cstr);
String string_ref(const char *cstr, int length);
void string_free(String *str);

