#include "Application.h"
#include "ApplicationLayer.h"
#include "PhysicalLayer.h"
#include "TransmissionEnvironment.h"

Application::Application(int role_option) {

    switch (role_option)
    {
    case 1: {
        std::cout << "########### NEW LAYER ###########\n";
        std::cout << "Application started.\n";
        ApplicationLayer transmission_application_layer;
        
        transmission_application_layer.SetBitStream();
        transmission_application_layer.PrintBitStream();

        int codification_option;
        std::cout << "[1] Binary\n[2] Manchester\n[3] Bipolar\n"
        << "Select the desired codification option from the above ones: ";
        std::cin >> codification_option;
        
        switch (codification_option)
        {
        case 1: {
            std::cout << "########### NEW LAYER ###########\n";
            BinaryCodification transmission_physical_layer;
            transmission_physical_layer.Encode(
                transmission_application_layer.GetBitStream()
                );
            break;
        }
        case 2: {
            // ManchesterCodification transmission_physical_layer;
            break;
        }
        case 3: {
            //BipolarCodification transmission_physical_layer;
            break;
        }
        default:
            break;
        }
        break;
    }
        
    default:
        break;
    }


}

