#ifndef LZ77ENCODER_HPP
#define LZ77ENCODER_HPP

#include <iostream>
#include <vector>

#include "LZ77Tuple.hpp"

class LZ77Encoder 
{
    std::vector<LZ77Tuple> _keys;
    std::string _text;
    size_t _buffSize;
    size_t _dictSize;

public:
    LZ77Encoder(size_t, size_t);

    std::vector<LZ77Tuple> keys();
    std::string text();
    const size_t& buffSize();
    const size_t& dictSize();

    void encode(std::string);
    std::string decode(std::vector<LZ77Tuple>&);
};

#endif /* LZ77ENCODER_HPP */