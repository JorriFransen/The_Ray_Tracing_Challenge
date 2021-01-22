
#include "util.h"

#include <assert.h>
#include <bits/types/FILE.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace RayTracer
{

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

float ceil(float f)
{
   // https://stackoverflow.com/questions/8377412/ceil-function-how-can-we-implement-it-ourselves

    unsigned input;
    memcpy(&input, &f, 4);
    int exponent = ((input >> 23) & 255) - 127;
    if (exponent < 0) return (f > 0);
    // small numbers get rounded to 0 or 1, depending on their sign

    int fractional_bits = 23 - exponent;
    if (fractional_bits <= 0) return f;
    // numbers without fractional bits are mapped to themselves

    unsigned integral_mask = 0xffffffff << fractional_bits;
    unsigned output = input & integral_mask;
    // round the number down by masking out the fractional bits

    memcpy(&f, &output, 4);
    if (f > 0 && output != input) ++f;
    // positive numbers need to be rounded up, not down

    return f;
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

String string_copy(Allocator *allocator, const char *cstr, int length)
{
    String result;
    result.length = length;
    result.data = alloc_array<char>(allocator, length + 1);

    memcpy(result.data, cstr, length);
    result.data[length] = '\0';

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

String uint_to_string(Allocator *allocator, uint64_t x)
{
    assert(x >= 0);

    const auto buf_size = 32;
    char buf[buf_size];
    buf[buf_size - 1] = '\0';

    int64_t length = 0;

    if (x != 0)
    {
        while (x > 0)
        {
            auto d = x % 10;
            buf[buf_size - 2 - length] = d + '0';
            x /= 10;
            length++;
        }
    }
    else
    {
        buf[buf_size - 2] = '0';
        length = 1;
    }

    return string_copy(allocator, &buf[buf_size - 1 - length], length);
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

void write_file(const char *file_path, const String &file_data)
{
    write_file(string_ref(file_path), file_data);
}

void write_file(const String &file_path, const String &file_data)
{
    FILE *f = fopen(file_path.data, "w");

    fprintf(f, "%.*s", (int)file_data.length, file_data.data);

    fclose(f);
}

}


