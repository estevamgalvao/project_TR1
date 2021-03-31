#ifndef APPLICATIONLAYER_H
#define APPLICATIONLAYER_H

#include "Definitions.h"

class ApplicationLayer {
    protected:
        std::string message_;
        BITSET_VECTOR bit_stream_;
    
    public:
        ApplicationLayer();
        BITSET_VECTOR GetBitStream();
        void SetBitStream();
        void PrintBitStream();
        void Receive();

};

#endif //APPLICATIONLAYER_H