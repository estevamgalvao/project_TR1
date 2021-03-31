#include "ApplicationLayer.h"
#include "PhysicalLayer.h"

ApplicationLayer::ApplicationLayer() {
    std::cout << "Write down a message: ";
    std::getline (std::cin,message_);

    for (size_t i = 0; i < message_.size(); i++)
    {
        bit_stream_.push_back((std::bitset<BYTE_LENGTH>) message_[i]);
    }
};

BITSET_VECTOR ApplicationLayer::GetBitStream() {
    return bit_stream_;
};