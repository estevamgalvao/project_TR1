#include "Application.h"
#include "ApplicationLayer.h"
#include "PhysicalLayer.h"
#include "TransmissionEnvironment.h"

Application::Application(int role_option, int codification_option) {
    role_ = role_option;
    codification_option_ = codification_option;
}

void Application::SetCodeOption(int option) {
    codification_option_ = option;
}

int Application::GetCodeOption() {
    return codification_option_;
}

void Application::SetMessage(std::string message) {
    message_ = message;
}

std::string Application::GetMessage() {
    return message_;
}

void Application::SetBitStream(BITSET_VECTOR bit_stream) {
    bit_stream_ = bit_stream;
}

BITSET_VECTOR Application::GetBitStream() {
    return bit_stream_;
}

BITSET_VECTOR Application::Communicate() {

    switch (role_)
    {
    case 1: {
        std::cout << "\n########### NEW LAYER ###########\n";
        std::cout << "Application started.\n";
        ApplicationLayer transmission_application_layer;
        
        transmission_application_layer.SetBitStream(this->GetMessage());
        // transmission_application_layer.PrintBitStream();

        switch (codification_option_)
        {
        case 1: {
            std::cout << "\n########### NEW LAYER ###########\n";
            BinaryCodification transmission_physical_layer;
            transmission_physical_layer.Encode(
                transmission_application_layer.GetBitStream()
                );
            return transmission_physical_layer.GetEncodedTable();
            // break;
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

    case 2: {
        ApplicationLayer reception_application_layer;
        switch (codification_option_)
        {
        case 1: {
            std::cout << "\n########### NEW LAYER ###########\n";
            BinaryCodification reception_physical_layer;
            reception_physical_layer.Decode(
                this->GetBitStream()
                );
            
            std::cout << "\n########### NEW LAYER ###########\n";
            reception_application_layer.Translate(
                reception_physical_layer.GetDecodedTable()
            );

            std::cout << "Translated received message: \n" 
            << reception_application_layer.GetMessage() << "\n";
            return reception_physical_layer.GetDecodedTable();
            // break;
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

    }
        
    default:
        break;
    }


}

