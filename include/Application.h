#ifndef APPLICATION_H
#define APPLICATION_H

#include "Definitions.h"

/* Application class is the one which start the entire proccess trying to commu-
nicate, initializating all layers of a transmitter or a receptor */
/* It has two unique atributtes called role_ and codification_option_, both are
responsible for indicating if the app is a transmitter or a receptor and which 
codification is going to be used */ 

class Application {
    private:
        int role_;
        int codification_option_;
        int framing_option_;
        int error_option_;
        int error_chance_;
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