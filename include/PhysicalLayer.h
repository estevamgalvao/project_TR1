#ifndef PHYSICALLAYER_H
#define PHYSICALLAYER_H

#include "Definitions.h"

class PhysicalLayer {
    private:
        char data_;
        char bitstream_;

    public:
        PhysicalLayer();
        bool Encode();
        bool Decode();
        bool Send();
        bool Recieve();
        

}

#endif //PHYSICALLAYER_H