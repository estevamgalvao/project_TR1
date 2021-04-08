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
        void Decode(BITSET_VECTOR table);
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
    protected:
        std::vector<int> encoded_table_;    
    public:
        BipolarCodification();
        void Encode(BITSET_VECTOR table);
        void Decode(std::vector<int> table);
        std::vector<int> GetEncodedTable();

};

#endif //PHYSICALLAYER_H