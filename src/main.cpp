#include <Definitions.h>
#include "ApplicationLayer.h"
#include "PhysicalLayer.h"

int main(int argc, char const *argv[])
{
    std::string input;
    std::cin >> input;

    ApplicationLayer appLayer;
    
    std::vector<std::bitset<BYTE_LENGTH>> teste;
    std::vector<std::bitset<BYTE_LENGTH>>::iterator it;
    std::bitset<BYTE_LENGTH> b1('A');
    
    for (size_t i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << " ";
        teste.push_back((std::bitset<BYTE_LENGTH>) input[i]);
    }
    
    teste.push_back(b1);


    
    for (size_t i = 0; i < teste.size(); i++)
    {
        std::cout << "\n" << teste[i] << "\n";
    }
    


    return 0;
}
