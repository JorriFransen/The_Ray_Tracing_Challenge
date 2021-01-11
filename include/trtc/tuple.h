#pragma once

struct Tuple
{
    float x;
    float y;
    float z;
    float w;
};

void tuple_init(Tuple *tuple, float x, float y, float z, float w);
Tuple tuple(float x, float y, float z, float w);

bool tuple_eq(Tuple *lhs, Tuple *rhs);
bool tuple_eq(const Tuple lhs, const Tuple rhs);

Tuple tuple_add(const Tuple &lhs, const Tuple &rhs);
Tuple tuple_sub(const Tuple &lhs, const Tuple &rhs);
Tuple tuple_neg(const Tuple &t);
Tuple tuple_scale(const Tuple &t, float scale);
Tuple tuple_div(const Tuple &t, float divisor);

bool tuple_is_point(Tuple *tuple);
bool tuple_is_vector(Tuple *tuple);
