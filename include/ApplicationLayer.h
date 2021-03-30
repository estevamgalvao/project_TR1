#ifndef APPLICATIONLAYER_H
#define APPLICATIONLAYER_H

#include <Definitions.h>

class ApplicationLayer {
    protected:
        std::vector<std::bitset<BYTE_LENGTH>> bitstream_;
    
    public:
        ApplicationLayer();
        void start();
};

#endif //APPLICATIONLAYER_H