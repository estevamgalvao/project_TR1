#ifndef APPLICATIONLAYER_H
#define APPLICATIONLAYER_H

#include <Definitions.h>

class ApplicationLayer {
    protected:
        std::string message_;
        std::vector<std::bitset<BYTE_LENGTH>> bitstream_;
    
    public:
        ApplicationLayer(std::string m);
        void Communicate();

};

#endif //APPLICATIONLAYER_H