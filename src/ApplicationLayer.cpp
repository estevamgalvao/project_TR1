#include "ApplicationLayer.h"
#include "PhysicalLayer.h"

ApplicationLayer::ApplicationLayer() {
    std::cout << "Application layer initiated";
};

BITSET_VECTOR ApplicationLayer::GetBitStream() {
    return bit_stream_;
};

void ApplicationLayer::PrintBitStream() {
    for (size_t i = 0; i < bit_stream_.size()-1; i++)
    {
        std::cout << bit_stream_[i] << " ";
    }
    std::cout << bit_stream_[bit_stream_.size()-1] << "\n";
};

void ApplicationLayer::Receive() {
    message_.clear();
    for (size_t i = 0; i < bit_stream_.size(); i++)
    {
        /* A linguagem sabe transformar u long int para char,
        por isso fazemos assim */
        message_ += (char) bit_stream_[i].to_ulong();
    }
};

void ApplicationLayer::SetBitStream() {
    std::cout << "Enter the desired message: ";
    std::getline (std::cin,message_);

    for (size_t i = 0; i < message_.size(); i++)
    {
        bit_stream_.push_back((std::bitset<BYTE_LENGTH>) message_[i]);
    }
}