#include "ApplicationLayer.h"
#include "PhysicalLayer.h"

ApplicationLayer::ApplicationLayer(std::string m) {
    message_ = m;
    for (size_t i = 0; i < m.size(); i++)
    {
        bitstream_.push_back((std::bitset<BYTE_LENGTH>) m[i]);
    }
};