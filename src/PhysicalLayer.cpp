#include "PhysicalLayer.h"

BinaryCodification::BinaryCodification() {

}

void BinaryCodification::Encode(BITSET_VECTOR table) {
    encoded_table_ = table;
    std::cout << "Binary encoding: \n";
    PrintEncodedTable();
}

void BinaryCodification::Decode(BITSET_VECTOR table) {
    decoded_table_ = table;
    std::cout << "Binary decoding: \n";
    PrintDecodedTable();
}


void BinaryCodification::PrintEncodedTable() {
    for (size_t i = 0; i < encoded_table_.size()-1; i++)
    {
        std::cout << encoded_table_[i] << " ";
    }
    std::cout << encoded_table_[encoded_table_.size()-1] << "\n";
}

void BinaryCodification::PrintDecodedTable() {
    for (size_t i = 0; i < decoded_table_.size()-1; i++)
    {
        std::cout << decoded_table_[i] << " ";
    }
    std::cout << decoded_table_[decoded_table_.size()-1] << "\n";
}

BITSET_VECTOR BinaryCodification::GetEncodedTable() {
    return encoded_table_;
};

BITSET_VECTOR BinaryCodification::GetDecodedTable() {
    return decoded_table_;
};