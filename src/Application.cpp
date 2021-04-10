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
        std::cout << "\n########### Application Layer ###########\n";
        std::cout << "Application started.\n";
        ApplicationLayer transmission_application_layer;
        
        transmission_application_layer.SetBitStream(this->GetMessage());

        switch (codification_option_)
        {
        case 1: {
            std::cout << "\n########### Physical Layer ###########\n";
            BinaryCodification transmission_physical_layer;
            transmission_physical_layer.Encode(
                transmission_application_layer.GetBitStream()
                );
            transmission_physical_layer.PrintEncodedTable();
            return transmission_physical_layer.GetEncodedTable();
            // break;
        }
        case 2: {
            std::cout << "\n########### Physical Layer ###########\n";
            ManchesterCodification transmission_physical_layer;
            transmission_physical_layer.Encode(
                transmission_application_layer.GetBitStream()
                );
            transmission_physical_layer.PrintEncodedTable();
            return transmission_physical_layer.GetEncodedTable();
            // break;
        }
        case 3: {
            std::cout << "\n########### Physical Layer ###########\n";
            BipolarCodification transmission_physical_layer;
            transmission_physical_layer.Encode(
                transmission_application_layer.GetBitStream()
                );
            transmission_physical_layer.PrintEncodedTable();
            return transmission_physical_layer.GetEncodedTable();
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
            std::cout << "\n########### Physical Layer ###########\n";
            BinaryCodification reception_physical_layer;
            reception_physical_layer.Decode(
                this->GetBitStream()
                );
            reception_physical_layer.PrintDecodedTable();
            
            std::cout << "\n########### Application Layer ###########\n";
            reception_application_layer.Translate(
                reception_physical_layer.GetDecodedTable()
            );

            std::cout << "Translated received message: \n" 
            << reception_application_layer.GetMessage() << "\n";
            return reception_physical_layer.GetDecodedTable();
            // break;
        }
        case 2: {
            std::cout << "\n########### Physical Layer ###########\n";
            ManchesterCodification reception_physical_layer;
            reception_physical_layer.Decode(
                this->GetBitStream()
                );
            reception_physical_layer.PrintDecodedTable();
            
            
            std::cout << "\n########### Application Layer ###########\n";
            reception_application_layer.Translate(
                reception_physical_layer.GetDecodedTable()
            );

            std::cout << "Translated received message: \n" 
            << reception_application_layer.GetMessage() << "\n";
            return reception_physical_layer.GetDecodedTable();
            // break;
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

