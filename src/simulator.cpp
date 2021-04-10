#include "Definitions.h"
#include "Application.h"
#include "TransmissionEnvironment.h"
#include "PhysicalLayer.h"
#include "ApplicationLayer.h"

int main()
{   
    /* Messages variables */

    BITSET_VECTOR encoded_message, transmitted_message, decoded_message;
    std::string message;

    /* Getting info from the user - desired message and which codification 
    is going to be used */

    std::cout << "Enter the desired message: ";
    std::getline (std::cin,message);

    int codification_option;
    std::cout << "[1] Binary\n[2] Manchester\n[3] Bipolar\n"
    << "Select the desired codification option from the above ones: ";
    std::cin >> codification_option;

    /* Applications objects initialized - transmissor and receptor */
    /* Transmission Enviroment that links the two Applications initialized */

    TransmissionEnvironment environment;    
    Application transmission_app(1, codification_option);
    Application reception_app(2, codification_option);

    /* Application workflow */
    /* App Transmissor => Transmission Environment => App Receptor */
    
    /* App Transmissor: Application Layer (ASCII to Binary)
                        => 
                        Physhical Layer (Encode) */
    /* App Receptor:    Physical Layer (Decode)
                        => 
                        Application Layer (Binary to ASCII) */


    transmission_app.SetMessage(message);
    encoded_message = transmission_app.Communicate();

    transmitted_message = environment.Transmit(encoded_message);

    reception_app.SetBitStream(transmitted_message);
    decoded_message = reception_app.Communicate();

    return 0;
};
