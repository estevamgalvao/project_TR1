#ifndef PHYSICALLAYER_H
#define PHYSICALLAYER_H

#include "Definitions.h"
/* PhysicalLayer class is divided in 3 sub-classes,
- BinaryCodification
- ManchesterCodification
- BipolarCodification */

/* The physical layer has 2 atributtes:
- decoded_table_: stores the decoded bitstream without any codification on it.
- encoded_table_: stores the encoded bitstream depending of which codification 
was used.

And implements 4 commom methods and 2 virtual methods, Encode and Decode.
Every subclass implements your own decoding and encoding method. */
class PhysicalLayer {
    protected:
        BITSET_VECTOR decoded_table_;
        BITSET_VECTOR encoded_table_;

    public:
        virtual ~PhysicalLayer() {};
        virtual void Encode(BITSET_VECTOR table) = 0;
        virtual void Decode(BITSET_VECTOR table) = 0;
        void PrintDecodedTable();        
        void PrintEncodedTable();
        BITSET_VECTOR GetEncodedTable();
        BITSET_VECTOR GetDecodedTable();
};

class BinaryCodification : public PhysicalLayer {
    public:
        BinaryCodification();
        void Encode(BITSET_VECTOR table);
        void Decode(BITSET_VECTOR table);
};

class ManchesterCodification : public PhysicalLayer {
    public:
        ManchesterCodification();
        void Encode(BITSET_VECTOR table);
        void Decode(BITSET_VECTOR table);
};

class BipolarCodification : public PhysicalLayer {
    public:
        BipolarCodification();
        void Encode(BITSET_VECTOR table);
        void Decode(BITSET_VECTOR table);

};

#endif //PHYSICALLAYER_H