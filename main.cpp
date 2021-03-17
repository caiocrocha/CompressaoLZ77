#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "include/LZ77Tuple.hpp"
#include "include/LZ77Encoder.hpp"

#define MAXBUFFER 4
#define MAXDICT 6

int main(int argc, char *argv[])
{
    const char *progname = *argv;

    if (argc < 2)
    {
        std::cerr << progname << ": nenhum arquivo fornecido\n";
        exit(1);
    }

    while (--argc)
    {
        std::string filename = *++argv;
        std::ifstream file(filename);

        if (!file)
        {
            std::cerr << progname << ": falha ao abrir o arquivo `" << *argv << "`\n";
            exit(2);
        }

        size_t buffSize, dictSize;
        std::cout << "Digite o tamanho do buffer: ";
        std::cin >> buffSize;
        std::cout << "Digite o tamanho do dicionario: ";
        std::cin >> dictSize;
    
        //LZ77Encoder encoder(MAXBUFFER, MAXDICT);
        LZ77Encoder encoder(buffSize, dictSize);

        std::string s;
        std::getline(file, s, (char) EOF);
        file.close();
        encoder.encode(s);

        std::string raw_name = filename.substr(0, filename.find_last_of("."));
        std::ofstream outfile(raw_name + "_compressed.txt");
        if(!outfile)
        {
            std::cerr << progname << ": falha ao abrir o arquivo `" << raw_name << "_compressed.txt`\n";
            exit(3);
        }

        std::vector<LZ77Tuple> keys = encoder.keys();
        for(size_t i = 0; i < keys.size() - 1; i++)
            outfile << keys[i] << " ";
        outfile << keys[keys.size()-1];
        outfile.close();
        std::cout << "Arquivo codificado salvo em `" << raw_name << "_compressed.txt`\n";

        std::string s1 = encoder.decode(keys);
        //std::cout << "String original: " << encoder.text() << std::endl;
        //std::cout << "String decodificada: " << s1 << std::endl;
        std::cout << "As strings são " << (s == s1 ? "iguais" : "diferentes") << std::endl;
    }
    
    return 0;
}
