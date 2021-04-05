#ifndef PHYSICALLAYER_H
#define PHYSICALLAYER_H

#include "Definitions.h"

class PhysicalLayer {
    protected:
        BITSET_VECTOR decoded_table_;
        BITSET_VECTOR encoded_table_;

    public:
        virtual ~PhysicalLayer() {};
        virtual void Encode(BITSET_VECTOR table) = 0;
        virtual void Decode(BITSET_VECTOR table) = 0;
        virtual void PrintDecodedTable() = 0;        
        virtual void PrintEncodedTable() = 0;
        virtual BITSET_VECTOR GetEncodedTable() = 0;
        virtual BITSET_VECTOR GetDecodedTable() = 0;
};

class BinaryCodification : public PhysicalLayer {
    public:
        BinaryCodification();
        void Encode(BITSET_VECTOR table);
        void Decode(BITSET_VECTOR table);
        void PrintDecodedTable();        
        void PrintEncodedTable();
        BITSET_VECTOR GetEncodedTable();
        BITSET_VECTOR GetDecodedTable();

};

class ManchesterCodification : public PhysicalLayer {
    public:
        ManchesterCodification();
        void Encode(BITSET_VECTOR table);
        void Decode(BITSET_VECTOR table);
        void PrintDecodedTable();        
        void PrintEncodedTable();
        BITSET_VECTOR GetEncodedTable();
        BITSET_VECTOR GetDecodedTable();
};

// class BipolarCodification : public PhysicalLayer {
    
// };

#endif //PHYSICALLAYER_H