#ifndef TRANSMISSIONENVIRONMENT_H
#define TRANSMISSIONENVIRONMENT_H

#include "Definitions.h"

/* TransmissionEnvironment is the one which simulates the environment where the
data is going through */

class TransmissionEnvironment {
    private:
        std::vector<std::bitset<BYTE_LENGTH>> origin_bits_;
        std::vector<std::bitset<BYTE_LENGTH>> destination_bits_;

    public:
        TransmissionEnvironment();
        BITSET_VECTOR SetPath(std::vector<std::bitset<BYTE_LENGTH>> bit_stream);
};


#endif //TRANSMISSIONENVIRONMENT_H