#include <iostream>
#include <string>
#include <vector>

#include "include/LZ77Tuple.hpp"

int main()
{
    //std::string s("ababcbababaa");
    //std::string s("aacaacabcabaaac");
    std::string s("bananabanabofana");
    
    size_t buffer = 4;
    size_t dict = 6;
    std::vector<LZ77Tuple> keys;

    size_t i = 0;
    while(i < s.size()) {
        size_t l = 1;
        size_t lL = 0;
        size_t lP = 0;

        while(l <= dict && l <= i) {
            size_t count = 0;
            size_t prev = i-l;
            size_t next = i;
            while(buffer >= next - i + 1 && s[prev] == s[next]) {
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
            l++;
        }

        i += lL + 1;

        if(i > s.size())
            keys.push_back(LZ77Tuple(lP, lL, '\0'));
        else
            keys.push_back(LZ77Tuple(lP, lL, s[i-1]));
    }

    for(size_t i = 0; i < keys.size(); i++)
        std::cout << keys[i].p << "\t" << keys[i].l << "\t" << keys[i].c << std::endl;

    return 0;
}
