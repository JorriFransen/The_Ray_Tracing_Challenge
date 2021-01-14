#pragma once

#include "array.h"

#include <inttypes.h>

const float EPSILON = 0.00001f;

float abs_f(float x);
bool float_eq(float lhs, float rhs);

struct String
{
    char *data = nullptr;
    int64_t length = -1;

    char& operator[](int index)
    {
        assert(index < length);
        return data[index];
    }

    const char& operator[](int index) const
    {
        assert(index < length);
        return data[index];
    }

    bool operator==(const String &rhs) const
    {
        return data == rhs.data && length == rhs.length;
    }
};

String string_ref(const char *cstr);
String string_ref(const char *cstr, int length);
void string_free(String *str);

bool string_eq(const String &a, const char *b);
bool string_eq(const String &a, const String &b);

Array<String> string_split_ref(Allocator *allocator, const String &str, char split_on);
