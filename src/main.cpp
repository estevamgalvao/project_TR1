#include "Definitions.h"
#include "Application.h"
#include "TransmissionEnvironment.h"
#include "PhysicalLayer.h"
#include "ApplicationLayer.h"

int main()
{   
    BITSET_VECTOR encoded_message, transmitted_message, decoded_message;
    std::string message;

    TransmissionEnvironment environment;

    std::cout << "Enter the desired message: ";
    std::getline (std::cin,message);

    int codification_option;
    std::cout << "[1] Binary\n[2] Manchester\n[3] Bipolar\n"
    << "Select the desired codification option from the above ones: ";
    std::cin >> codification_option;
    
    Application transmission_app(1, codification_option);
    Application reception_app(2, codification_option);

    transmission_app.SetMessage(message);
    encoded_message = transmission_app.Communicate();

    transmitted_message = environment.Transmit(encoded_message);

    reception_app.SetBitStream(transmitted_message);
    decoded_message = reception_app.Communicate();

    ApplicationLayer lula;
    ManchesterCodification lol;

    std::getline (std::cin,message);
    std::cout << "Bora testar solta o verbo: ";
    std::getline (std::cin,message);

    lula.SetBitStream(message);
    lol.Encode(lula.GetBitStream());
    lol.PrintEncodedTable();
    lol.Decode(lol.GetEncodedTable());
    lol.PrintDecodedTable();


    return 0;
};
