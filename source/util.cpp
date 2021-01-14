
#include "util.h"
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
    String result;
    result.data = (char *)cstr;
    result.length = strlen(cstr);
    return result;
}

void string_builder_init(String_Builder *sb, int64_t block_size);
void string_builder_free(String_Builder *sb);
String string_builder_to_string(String_Builder *sb);

void string_builder_append(String_Builder *sb, const String &str);
void string_builder_append(String_Builder *sb, const char *cstr, int length);
void string_builder_appendf(String_Builder *sb, const char *format, ...);
