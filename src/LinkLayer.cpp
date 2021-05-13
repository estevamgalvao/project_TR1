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

void LinkLayer::PrintErrorTable() {
    for (size_t i = 0; i < error_table_.size()-1; i++)
    {
        std::cout << error_table_[i] << " ";
    }
    std::cout << error_table_[error_table_.size()-1] << "\n";
}

void LinkLayer::PrintNoErrorTable() {
    for (size_t i = 0; i < noerror_table_.size()-1; i++)
    {
        std::cout << noerror_table_[i] << " ";
    }
    std::cout << noerror_table_[noerror_table_.size()-1] << "\n";
}

void LinkLayer::SetErrorTable(BITSET_VECTOR table) {
    error_table_ = table;
}

BITSET_VECTOR LinkLayer::GetErrorTable() {
    return error_table_;
}

void LinkLayer::SetNoErrorTable(BITSET_VECTOR table) {
    noerror_table_ = table;
}

BITSET_VECTOR LinkLayer::GetNoErrorTable() {
    return noerror_table_;
}


void LinkLayer::CharacterCount(BITSET_VECTOR table) {
    std::bitset<BYTE_LENGTH> table_size;
    table_size = table.size();

    table.insert(table.begin(), table_size);

    header_table_ = table;
}

void LinkLayer::DecodeCharacterCount(BITSET_VECTOR table) {
    BITSET_VECTOR aux_table = table;
    
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

void LinkLayer::DecodeByteInsertion(BITSET_VECTOR table) {
    BITSET_VECTOR aux_table = table;

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

void LinkLayer::ParityBit(BITSET_VECTOR table) {

    int counter = 0;
    std::bitset<BYTE_LENGTH> even = 0; //se deu par, quero que fique par
    std::bitset<BYTE_LENGTH> odd = 1; //se deu ímpar, quero que fique par
    

    for (size_t i = 0; i < table.size(); i++)
    {
        for (size_t j = 0; j < BYTE_LENGTH; j++)
        {
            if (table[i][j] != 0) {
                counter++;
            }
        }
        
    }

    if (counter%2 == 0) {
        table.push_back(even);
    }
    else {
        table.push_back(odd);
    }

    error_table_ = table;
    
}

void LinkLayer::DecodeParityBit(BITSET_VECTOR table) {
    BITSET_VECTOR aux_table = table;
    
    aux_table.pop_back();

    noerror_table_ = aux_table;
}

void LinkLayer::CRC(BITSET_VECTOR table) {
    
}

void LinkLayer::DecodeCRC(BITSET_VECTOR table) {
    
}