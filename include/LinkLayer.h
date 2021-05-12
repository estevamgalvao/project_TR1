#ifndef LINKLAYER_H
#define LINKLAYER_H

#include "Definitions.h"

class LinkLayer {
    private:
        BITSET_VECTOR header_table_;
        BITSET_VECTOR noheader_table_;
    
    public:
        LinkLayer();
        void CharacterCount(BITSET_VECTOR table);
        void DecodeCharacterCount();
        void ByteInsertion(BITSET_VECTOR table);
        void DecodeByteInsertion();
        //TODO
        /* 

        */
        void PrintHeaderTable();        
        void PrintNoHeaderTable();
        void SetHeaderTable(BITSET_VECTOR table);
        BITSET_VECTOR GetHeaderTable();
        void SetNoHeaderTable(BITSET_VECTOR table);
        BITSET_VECTOR GetNoHeaderTable();
        

};


#endif //LINKLAYER