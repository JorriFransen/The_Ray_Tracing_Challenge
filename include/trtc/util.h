#pragma once

#include "array.h"

#include <inttypes.h>

namespace RayTracer
{

const float EPSILON = 0.00001f;

float abs_f(float x);
bool float_eq(float lhs, float rhs);
float ceil(float f);

template <typename BOUND_TYPE, typename IN_TYPE, typename OUT_TYPE=IN_TYPE>
OUT_TYPE clamp(BOUND_TYPE min, BOUND_TYPE max, IN_TYPE x)
{
    if (x < min) return (OUT_TYPE)min;
    if (x > max) return (OUT_TYPE)max;

//#pragma warning(disable:4244)
    return (OUT_TYPE)x;
//#pragma warning(default:4244)
}

struct String
{
    char *data = nullptr;
    int64_t length = -1;

    char& operator[](int64_t index)
    {
        assert(index < length);
        return data[index];
    }

    const char& operator[](int64_t index) const
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
String string_ref(const char *cstr, int64_t length);
String string_copy(Allocator *allocator, const char *cstr, int64_t length);

void string_free(String *str);

bool string_eq(const String &a, const char *b);
bool string_eq(const String &a, const String &b);

String uint_to_string(Allocator *allocator, uint64_t x);

Array<String> string_split_ref(Allocator *allocator, const String &str, char split_on);

void write_file(const char *file_path, const String &file_data);
void write_file(const String &file_path, const String &file_data);
}
