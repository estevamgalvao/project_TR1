#include "PhysicalLayer.h"

void PhysicalLayer::PrintEncodedTable() {
    for (size_t i = 0; i < encoded_table_.size()-1; i++)
    {
        std::cout << encoded_table_[i] << " ";
    }
    std::cout << encoded_table_[encoded_table_.size()-1] << "\n";
}

void PhysicalLayer::PrintDecodedTable() {
    for (size_t i = 0; i < decoded_table_.size()-1; i++)
    {
        std::cout << decoded_table_[i] << " ";
    }
    std::cout << decoded_table_[decoded_table_.size()-1] << "\n";
}

BITSET_VECTOR PhysicalLayer::GetEncodedTable() {
    return encoded_table_;
};

BITSET_VECTOR PhysicalLayer::GetDecodedTable() {
    return decoded_table_;
};

BinaryCodification::BinaryCodification() {}

void BinaryCodification::Encode(BITSET_VECTOR table) {
    encoded_table_ = table;
    std::cout << "Binary encoding: \n";
}

void BinaryCodification::Decode(BITSET_VECTOR table) {
    decoded_table_ = table;
    std::cout << "Binary decoding: \n";
}

ManchesterCodification::ManchesterCodification() {};

void ManchesterCodification::Encode(BITSET_VECTOR table) {
    BITSET_VECTOR aux_bitset_vector;
    std::bitset<BYTE_LENGTH> aux_bitset;
    for (size_t i = 0; i < table.size(); i++)
    {
        aux_bitset.reset();
        // std::cout << "BITSTREAM[" << i << "]: " << table[i] << "\n";
        u1 offset = 0;
        for (size_t j = BYTE_LENGTH; j > BYTE_LENGTH/2; j--)
        {
            int index;
            index = (j-1)-offset;
            // std::cout << "BIT[" << j-1 << "]: " << table[i][j-1] << "\n";
            if(table[i][j-1]) {
                /* Se encontrei um 1, escrevo 10 */
                aux_bitset.set(index);
                aux_bitset.set(index-1, 0);
            }
            else {
                /* Se encontrei um 0, escrevo 01 */
                aux_bitset.set(index, 0);
                aux_bitset.set(index-1);
            }
            offset++;
        }

        aux_bitset_vector.push_back(aux_bitset);
        aux_bitset.reset();

        for (size_t j = BYTE_LENGTH/2; j > 0; j--)
        {
            int index;
            index = ((j-1)*2);
            // std::cout << "BIT[" << j-1 << "]: " << table[i][j-1] << "\n";
            if(table[i][j-1]) {
                /* Se encontrei um 1, escrevo 10 */
                aux_bitset.set(index + 1);
                aux_bitset.set(index, 0);
            }
            else {
                /* Se encontrei um 0, escrevo 01 */
                aux_bitset.set(index + 1, 0);
                aux_bitset.set(index);
            }
            // std::cout << aux_bitset << "\n";
        }
        aux_bitset_vector.push_back(aux_bitset);        
    }
    
    encoded_table_ = aux_bitset_vector;
};

void ManchesterCodification::Decode(BITSET_VECTOR table){
    BITSET_VECTOR aux_bitset_vector;
    std::bitset<BYTE_LENGTH> aux_bitset;

    for (size_t i = 0; i < table.size(); i += 2)
    {
        int index = 7;

        for (int j = BYTE_LENGTH-1; j >= 0; j -= 2)
        {
            if (table[i][j] == 0 and table[i][j-1] == 1) {
                aux_bitset.set(index, 0);
            }
            else if (table[i][j] == 1 and table[i][j-1] == 0) {
                aux_bitset.set(index);
            }
            index--;
        }

        for (int j = BYTE_LENGTH-1; j >= 0; j -= 2)
        {
            if (table[i+1][j] == 0 and table[i+1][j-1] == 1) {
                aux_bitset.set(index, 0);
            }
            else if (table[i+1][j] == 1 and table[i+1][j-1] == 0) {
                aux_bitset.set(index);
            }
            index--;
        }

        aux_bitset_vector.push_back(aux_bitset);
        aux_bitset.reset();
    }
    
    decoded_table_ = aux_bitset_vector;

};
