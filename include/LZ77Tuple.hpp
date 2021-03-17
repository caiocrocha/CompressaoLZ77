#ifndef LZ77TUPLE_HPP
#define LZ77TUPLE_HPP

#include <iostream>

typedef struct LZ77Tuple {
    size_t p, l;
    char c;

    LZ77Tuple(size_t, size_t, char);

} LZ77Tuple;

#endif /* LZ77TUPLE_HPP */