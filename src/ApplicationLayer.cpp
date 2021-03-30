#include "ApplicationLayer.h"

ApplicationLayer::ApplicationLayer(){};

void ApplicationLayer::start(int flag, std::string m) {

    for (size_t i = 0; i < m.size(); i++)
    {
        std::cout << m[i] << " ";
        bitstream_.push_back((std::bitset<BYTE_LENGTH>) m[i]);
    }
};