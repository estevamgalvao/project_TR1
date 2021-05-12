#ifndef LINKLAYER_H
#define LINKLAYER_H

#include "Definitions.h"

class LinkLayer {
    private:
        BITSET_VECTOR header_table_;
        BITSET_VECTOR noheader_table_;

        BITSET_VECTOR error_table_;
        BITSET_VECTOR noerror_table_;
        
    
    public:
        LinkLayer();
        void CharacterCount(BITSET_VECTOR table);
        void DecodeCharacterCount(BITSET_VECTOR table);
        void ByteInsertion(BITSET_VECTOR table);
        void DecodeByteInsertion(BITSET_VECTOR table);
       
        void ParityBit(BITSET_VECTOR table);
        void DecodeParityBit(BITSET_VECTOR table);
        void CRC(BITSET_VECTOR table);
        void DecodeCRC(BITSET_VECTOR table);

        void PrintHeaderTable();        
        void PrintNoHeaderTable();
        void SetHeaderTable(BITSET_VECTOR table);
        BITSET_VECTOR GetHeaderTable();
        void SetNoHeaderTable(BITSET_VECTOR table);
        BITSET_VECTOR GetNoHeaderTable();
        
        void PrintErrorTable();        
        void PrintNoErrorTable();
        void SetErrorTable(BITSET_VECTOR table);
        BITSET_VECTOR GetErrorTable();
        void SetNoErrorTable(BITSET_VECTOR table);
        BITSET_VECTOR GetNoErrorTable();
};


#endif //LINKLAYER