#ifndef PHYSICALLAYER_H
#define PHYSICALLAYER_H

#include "Definitions.h"

class PhysicalLayer {
    protected:
        char table_;
        char bit_stream_;

    public:
        PhysicalLayer();
        virtual bool Encode();
        virtual bool Decode();
        bool Send();
        bool Recieve();
        

};

class BinaryCodification : public PhysicalLayer {

};

class ManchesterCodification : public PhysicalLayer {

};

class BipolarCodification : public PhysicalLayer {
    
};

#endif //PHYSICALLAYER_H