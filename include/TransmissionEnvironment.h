#ifndef TRANSMISSIONENVIRONMENT_H
#define TRANSMISSIONENVIRONMENT_H

#include "Definitions.h"

class TransmissionEnvironment {
    private:
        std::vector<std::bitset<BYTE_LENGTH>> origin_bits_;
        std::vector<std::bitset<BYTE_LENGTH>> destination_bits_;

    public:
        TransmissionEnvironment();
        void Transmit(std::vector<std::bitset<BYTE_LENGTH>> bit_stream);
};


#endif //TRANSMISSIONENVIRONMENT_H