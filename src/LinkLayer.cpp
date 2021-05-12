#include "LinkLayer.h"

LinkLayer::LinkLayer() {};

void LinkLayer::PrintHeaderTable() {
    for (size_t i = 0; i < header_table_.size()-1; i++)
    {
        std::cout << header_table_[i] << " ";
    }
    std::cout << header_table_[header_table_.size()-1] << "\n";
}

void LinkLayer::PrintNoHeaderTable() {
    for (size_t i = 0; i < noheader_table_.size()-1; i++)
    {
        std::cout << noheader_table_[i] << " ";
    }
    std::cout << noheader_table_[noheader_table_.size()-1] << "\n";
}

void LinkLayer::SetHeaderTable(BITSET_VECTOR table) {
    header_table_ = table;
}

BITSET_VECTOR LinkLayer::GetHeaderTable() {
    return header_table_;
}

void LinkLayer::SetNoHeaderTable(BITSET_VECTOR table) {
    noheader_table_ = table;
}

BITSET_VECTOR LinkLayer::GetNoHeaderTable() {
    return noheader_table_;
}

void LinkLayer::CharacterCount(BITSET_VECTOR table) {
    std::bitset<BYTE_LENGTH> table_size;
    table_size = table.size();

    table.insert(table.begin(), table_size);

    header_table_ = table;
}

void LinkLayer::DecodeCharacterCount() {
    BITSET_VECTOR aux_table = header_table_;
    
    aux_table.erase(aux_table.begin());
    noheader_table_ = aux_table;
}

void LinkLayer::ByteInsertion(BITSET_VECTOR table) {

    for (size_t i = 0; i < table.size(); i++)
    {
        if (table[i] == BYTE_FLAG or table[i] == BYTE_ESC) {
            table.insert(table.begin()+i, BYTE_ESC);
            i++;
        }
    }

    /* Inserting FLAG bytes at the table's end and begin */
    table.insert(table.begin(), BYTE_FLAG);
    table.insert(table.end(), BYTE_FLAG);

    header_table_ = table;

};

void LinkLayer::DecodeByteInsertion() {
    BITSET_VECTOR aux_table = header_table_;

    /* Inserting FLAG bytes at the table's end and begin */
    aux_table.erase(aux_table.begin());
    aux_table.pop_back();
    // aux_table.erase(aux_table.end());

    for (size_t i = 0; i < aux_table.size()-1; i++)
    {
        if (aux_table[i] == BYTE_ESC) {
            if (aux_table[i+1] == BYTE_FLAG or aux_table[i+1] == BYTE_ESC) {
                aux_table.erase(aux_table.begin()+i);
            }
        }
    }

    noheader_table_ = aux_table;

}



