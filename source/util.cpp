
#include "util.h"

#include <assert.h>
#include <cstdlib>
#include <cstring>

float abs_f(float x)
{
    if (x < 0.0f)
        x *= -1;

    return x;
}

bool float_eq(float lhs, float rhs)
{
    return abs_f(lhs - rhs) < EPSILON;
}

String string_ref(const char *cstr)
{
    return string_ref(cstr, strlen(cstr));
}

String string_ref(const char *cstr, int length)
{
    String result;
    result.data = (char *)cstr;
    result.length = length;
    return result;
}

void string_free(String *str)
{
    free(str->data);
    str->data = nullptr;
    str->length = 0;
}

