#ifndef APPLICATIONLAYER_H
#define APPLICATIONLAYER_H

#include "Definitions.h"

class ApplicationLayer {
    protected:
        std::string message_;
        BITSET_VECTOR bit_stream_;
    
    public:
        ApplicationLayer();
        void SetBitStream(std::string message);
        BITSET_VECTOR GetBitStream();
        std::string GetMessage();
        void PrintBitStream();
        void Translate(BITSET_VECTOR bit_stream);

};

#endif //APPLICATIONLAYER_H