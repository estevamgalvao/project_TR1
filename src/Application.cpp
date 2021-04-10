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

    /* Switch that represent the communication start */
    /* If the application is going to transmitt or recept is based on the role_
    atributte
    [1] Transmitter
    [2] Receptor */

    switch (role_)
    {
    case 1: {
        ApplicationLayer transmission_application_layer;
        
        transmission_application_layer.SetBitStream(this->GetMessage());

        /* Switch that represent the codification start */
        /* The codification that is going to be used is based on the
        codification_option_ atributte
        [1] Binary
        [2] Manchester
        [3] Bipolar */

        switch (codification_option_)
        {
        case 1: {
            BinaryCodification transmission_physical_layer;

            transmission_physical_layer.Encode
                (
                transmission_application_layer.GetBitStream()
                );
            transmission_physical_layer.PrintEncodedTable();
            
            return transmission_physical_layer.GetEncodedTable();
        }
        case 2: {

            ManchesterCodification transmission_physical_layer;
            transmission_physical_layer.Encode(
                transmission_application_layer.GetBitStream()
                );
            transmission_physical_layer.PrintEncodedTable();
            return transmission_physical_layer.GetEncodedTable();
        }
        case 3: {
            std::cout << "\n########### Physical Layer ###########\n";
            BipolarCodification transmission_physical_layer;
            transmission_physical_layer.Encode(
                transmission_application_layer.GetBitStream()
                );
            transmission_physical_layer.PrintEncodedTable();
            return transmission_physical_layer.GetEncodedTable();
        }
        default:
            break;
        }
        break;
    }

    case 2: {
        ApplicationLayer reception_application_layer;

        /* Switch that represent the decodification start */
        /* The decodification that is going to be used is based on the
        codification_option_ atributte
        [1] Binary
        [2] Manchester
        [3] Bipolar */

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
        }
        case 3: {
            std::cout << "\n########### Physical Layer ###########\n";
            BipolarCodification reception_physical_layer;
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
        }
        default:
            break;
        }
    }
    default:
        break;
    }
}

