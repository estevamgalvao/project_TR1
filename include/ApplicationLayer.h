#ifndef APPLICATIONLAYER_H
#define APPLICATIONLAYER_H

#include "Definitions.h"

/* First try to make the entire code with DOCgen comments but it would take ages
just for one-person group, then i gave up doing that */

/*! \class ApplicationLayer
 *  \brief Class that represents the application layer during the transmission
 and reception. 
 *
 * First layer of transmission and last layer of reception. Responsible for
 * translate the message from ASCII to Binary and from Binary to ASCII.
 */
class ApplicationLayer {
    protected:
        std::string message_; /*!< String that stores the ASCII message */
        BITSET_VECTOR bit_stream_; /*!< BITSET_VECTOR that stores the Binary message */
    
    public:
        ApplicationLayer();
        /*!
        \brief Sets the bit_stream_ atributte translating the ASCII message into a Binary stream.
        
        \param message String which is going to be setted.
        */
        void SetBitStream(std::string message);
        /*!
        \brief Gets the bit_stream_ atributte.
        
        \return Binary BitStream that represents the ASCII message.
        */
        BITSET_VECTOR GetBitStream();
        /*!
        \brief Gets the message_ atributte.
        
        \return ASCII message.
        */
        std::string GetMessage();
        /*!
        \brief Prints the bit_stream_ atributte.
        */
        void PrintBitStream();
        /*!
        \brief Receive a BitStream and translate it to an string containing 
        an ASCII message and stores it on the message_ atributte.
        
        \param bit_stream the bitstream which is going to be translated.
        */
        void Translate(BITSET_VECTOR bit_stream);

};

#endif //APPLICATIONLAYER_H