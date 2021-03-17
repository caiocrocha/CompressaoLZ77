#ifndef LZ77TUPLE_HPP
#define LZ77TUPLE_HPP

#include <iostream>

struct LZ77Tuple {
    size_t p, l;
    char c;

    LZ77Tuple(size_t, size_t, char);

};

std::ostream& operator<<(std::ostream& out, const LZ77Tuple& tuple);

#endif /* LZ77TUPLE_HPP */