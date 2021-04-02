#ifndef APPLICATION_H
#define APPLICATION_H

#include "Definitions.h"

class Application {
    private:
        int role_;
        int codification_option_;
        std::string message_;
        BITSET_VECTOR bit_stream_;

    public:
        Application(int role_option, int codification_option);
        BITSET_VECTOR Communicate();
        void SetCodeOption(int option);
        int GetCodeOption();
        void SetMessage(std::string message);
        std::string GetMessage();
        void SetBitStream(BITSET_VECTOR bit_stream);
        BITSET_VECTOR GetBitStream();

};


#endif //APPLICATION_H