#include <iostream>
#include <string>
#include <vector>

#include "include/LZ77Tuple.hpp"
#include "include/LZ77Encoder.hpp"

std::string randomString(size_t size)
{
    static const char alphanum[] =
        // "0123456789"
        // "!@#$%^&* "
        // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcde" // "fghijk" "lmnopq" "rstuv" "wxyz"
        ;
    
    std::string s;
    for(size_t i = 0; i < size; i++)
        s.push_back(alphanum[std::rand() % (sizeof(alphanum) - 1)]);
    
    return s;
}

int main()
{
    LZ77Encoder encoder(4, 6);

    std::string s;
    std::cout << "Digite uma string: ";
    std::cin >> s;

    //std::string s("aacaacabcabaaac");
    //std::string s("ababcbababaa");
    //std::string s("bananabanabofana");

    //srand(time(NULL));
    //std::string s(randomString(std::rand() % 100));
    std::cout << "String de entrada: " << s << std::endl;

    encoder.encode(s);

    std::cout << "String codificada:\n";
    std::cout << "p\tl\tc\n";
    std::vector<LZ77Tuple> keys = encoder.keys();
    for(size_t i = 0; i < keys.size(); i++)
        std::cout << keys[i].p << "\t" << keys[i].l << "\t" << keys[i].c << std::endl;
    
    std::string s1 = encoder.decode(keys);
    std::cout << "String original: " << s << std::endl;
    std::cout << "String decodificada: " << s1 << std::endl;
    std::cout << "As string são " << (s == s1 ? "iguais" : "diferentes") << std::endl;

    return 0;
}
