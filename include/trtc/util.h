
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

struct String_Builder_Block
{
    char *data = nullptr;
    int64_t used = -1;
    int64_t capacity = -1;

    String_Builder_Block *next_block = nullptr;
};

struct String_Builder
{
    String_Builder_Block *first_block = nullptr;
    String_Builder_Block *current_block = nullptr;
};

String string_ref(const char *cstr);
void string_free(String *str);

void string_builder_init(String_Builder *sb, int64_t block_size);
void string_builder_free(String_Builder *sb);
String string_builder_to_string(String_Builder *sb);

void string_builder_append(String_Builder *sb, const String &str);
void string_builder_append(String_Builder *sb, const char *cstr, int length);
void string_builder_appendf(String_Builder *sb, const char *format, ...);
