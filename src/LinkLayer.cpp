#include "LinkLayer.h"

LinkLayer::LinkLayer() {};

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
    // int table_size;
    std::bitset<BYTE_LENGTH> table_size;
    table_size = table.size();

    table.insert(table.begin(), table_size);

    header_table_ = table;
};



