#include <Definitions.h>
#include "ApplicationLayer.h"
#include "PhysicalLayer.h"

int main();
{
    std::string input;
    std::getline (std::cin,input);
    ApplicationLayer appLayer(input);
    
    std::vector<std::bitset<BYTE_LENGTH>> teste;
    std::vector<std::bitset<BYTE_LENGTH>>::iterator it;

    for (size_t i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << " ";
        teste.push_back((std::bitset<BYTE_LENGTH>) input[i]);
    }
    
    for (size_t i = 0; i < teste.size(); i++)
    {
        std::cout << "\n" << teste[i] << "\n";
    }
    std::cout << "\nSTRING\n";
    std::string output;
    for (size_t i = 0; i < teste.size(); i++)
    {
        output += (char) teste[i].to_ulong();
        std::cout << (char) teste[i].to_ulong() << "\n"; // A linguagem sabe transformar u long int para char, por isso fazemos assim
    }
    
    std::cout << "\nTA BELEZA\n" << output;

    return 0;
}
