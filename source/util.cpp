
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

bool string_eq(const String &a, const char *b)
{
    return string_eq(a, string_ref(b));
}

bool string_eq(const String &a, const String &b)
{
    if (a == b) return true;
    if (a.length != b.length) return false;

    for (int64_t i = 0; i < a.length; i++)
    {
        if (a[i] != b[i]) return false;
    }

    return true;
}

Array<String> string_split_ref(Allocator *allocator, const String &str, char split_on)
{
    Array<String> result = array_create<String>(allocator, 4);

    String current_ref;
    current_ref.data = str.data;
    current_ref.length = 0;

    int64_t i = 0;

    while (i < str.length) {
        if (str[i] == split_on) {
            array_append(&result, current_ref);
            current_ref.data = &str.data[i] + 1;
            current_ref.length = 0;
        } else {
            current_ref.length += 1;
        }

        i += 1;
    }

    return result;
}

