#include <iostream>
#include <string>
#include <vector>

#include "../include/LZ77Tuple.hpp"
#include "../include/LZ77Encoder.hpp"

std::ostream& operator<<(std::ostream& out, const LZ77Tuple& tuple)
{
    return out << "(" << tuple.p << "," << tuple.l << "," << tuple.c << ")";
}

LZ77Encoder::LZ77Encoder(size_t buffSize, size_t dictSize)
{
    this->_buffSize = buffSize;
    this->_dictSize = dictSize;
}

std::vector<LZ77Tuple> LZ77Encoder::keys()
{
    return this->_keys;
}

std::string LZ77Encoder::text()
{
    return this->_text;
}

const size_t& LZ77Encoder::buffSize()
{
    return this->_buffSize;
}

const size_t& LZ77Encoder::dictSize()
{
    return this->_dictSize;
}

void LZ77Encoder::encode(std::string s)
{
    this->_text = s;

    for(size_t i = 0; i < s.size(); ) {
        size_t lL = 0, lP = 0;

        for(size_t l = 1; l <= this->_dictSize && l <= i; l++) {
            size_t count = 0, prev = i-l, next = i;

            while(this->_buffSize >= next - i + 1 && s[prev] == s[next]) {
                if(next == s.size())
                    break;
                prev++;
                next++;
                count++;
            }
            if(count > lL) {
                lL = count;
                lP = l;
            }
        }

        i += lL + 1;

        if(i > s.size())
            this->_keys.push_back(LZ77Tuple(lP, lL, '\0'));
        else
            this->_keys.push_back(LZ77Tuple(lP, lL, s[i-1]));
    }
}

std::string LZ77Encoder::decode(std::vector<LZ77Tuple>& keys)
{
    std::string s;
    for(size_t i = 0; i < keys.size(); i++) {
        size_t p = s.size() - keys[i].p;
        for(size_t l = 0; l < keys[i].l; l++) {
            s.push_back(s[p]);
            p++;
        }
        if(keys[i].c != '\0')
            s.push_back(keys[i].c);
    }
    return s;
}