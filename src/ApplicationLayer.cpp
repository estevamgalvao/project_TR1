#include "ApplicationLayer.h"
#include "PhysicalLayer.h"

ApplicationLayer::ApplicationLayer() {
    // std::cout << "Application layer initiated.\n";
};

void ApplicationLayer::SetBitStream(std::string message) {
    for (size_t i = 0; i < message.size(); i++)
    {
        bit_stream_.push_back((std::bitset<BYTE_LENGTH>) message[i]);
    }
}

BITSET_VECTOR ApplicationLayer::GetBitStream() {
    return bit_stream_;
};

std::string ApplicationLayer::GetMessage() {
    return message_;
}

void ApplicationLayer::PrintBitStream() {
    for (size_t i = 0; i < bit_stream_.size()-1; i++)
    {
        std::cout << bit_stream_[i] << " ";
    }
    std::cout << bit_stream_[bit_stream_.size()-1] << "\n";
};

void ApplicationLayer::Translate(BITSET_VECTOR bit_stream) {
    message_.clear();
    for (size_t i = 0; i < bit_stream.size(); i++)
    {
        /* A linguagem sabe transformar u long int para char,
        por isso fazemos assim */
        message_ += (char) bit_stream[i].to_ulong();
    }
};

