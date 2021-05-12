#include "Application.h"
#include "ApplicationLayer.h"
#include "PhysicalLayer.h"
#include "TransmissionEnvironment.h"
#include "LinkLayer.h"

Application::Application(int role_option, int codification_option, 
int framing_option) {
    role_ = role_option;
    codification_option_ = codification_option;
    framing_option_ = framing_option;
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
        
        std::cout << "\n\nOriginal received message: " << this->GetMessage()
        << "\n\n";
        transmission_application_layer.SetBitStream(this->GetMessage());

        /* Switch that represent the codification start */
        /* The encodification that is going to be used is based on the
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
            std::cout << "[Binary] Coded: ";
            transmission_physical_layer.PrintEncodedTable();
            
            return transmission_physical_layer.GetEncodedTable();
        }
        case 2: {
            ManchesterCodification transmission_physical_layer;
            
            transmission_physical_layer.Encode
                (
                transmission_application_layer.GetBitStream()
                );
            std::cout << "[Manchester] Coded: ";
            transmission_physical_layer.PrintEncodedTable();
            
            return transmission_physical_layer.GetEncodedTable();
        }
        case 3: {
            BipolarCodification transmission_physical_layer;
            
            transmission_physical_layer.Encode
                (
                transmission_application_layer.GetBitStream()
                );
            std::cout << "[Bipolar] Coded: ";
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
            BinaryCodification reception_physical_layer;

            reception_physical_layer.Decode
                (
                this->GetBitStream()
                );
            std::cout << "[Binary] Decoded: ";
            reception_physical_layer.PrintDecodedTable();
            
            reception_application_layer.Translate
                (
                reception_physical_layer.GetDecodedTable()
                );

            std::cout << "\nTranslated received message: " 
            << reception_application_layer.GetMessage() << "\n";

            return reception_physical_layer.GetDecodedTable();
        }
        case 2: {
            ManchesterCodification reception_physical_layer;
            
            reception_physical_layer.Decode
                (
                this->GetBitStream()
                );
            std::cout << "[Manchester] Decoded: ";
            reception_physical_layer.PrintDecodedTable();
            
            
            reception_application_layer.Translate
                (
                reception_physical_layer.GetDecodedTable()
                );

            std::cout << "\nTranslated received message: " 
            << reception_application_layer.GetMessage() << "\n";

            return reception_physical_layer.GetDecodedTable();
        }
        case 3: {
            BipolarCodification reception_physical_layer;

            reception_physical_layer.Decode
                (
                this->GetBitStream()
                );
            std::cout << "[Bipolar] Decoded: ";
            reception_physical_layer.PrintDecodedTable();
            
            
            reception_application_layer.Translate
                (
                reception_physical_layer.GetDecodedTable()
                );

            std::cout << "\nTranslated received message: " 
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


BITSET_VECTOR Application::Transmit() {

    BITSET_VECTOR aux_message;
    ApplicationLayer transmission_application_layer;
        
        std::cout << "\n\nOriginal received message: " << this->GetMessage()
        << "\n\n";

        transmission_application_layer.SetBitStream(this->GetMessage());
        aux_message = transmission_application_layer.GetBitStream();

    switch (this->framing_option_)
    {
    case 1:
    {
        LinkLayer transmission_link_layer;

        transmission_link_layer.CharacterCount(aux_message);
        std::cout << "[CharacterCount] Framed: ";
        transmission_link_layer.PrintHeaderTable();

        aux_message = transmission_link_layer.GetHeaderTable();
        break;
    }
    case 2:
    {
        LinkLayer transmission_link_layer;

        transmission_link_layer.ByteInsertion(aux_message);
        std::cout << "[ByteInsertion] Framed: ";
        transmission_link_layer.PrintHeaderTable();

        aux_message = transmission_link_layer.GetHeaderTable();
        break;
    }
    
    default:
        break;
    }


    switch (this->codification_option_) {
        case 1:
        {
            BinaryCodification transmission_physical_layer;

            transmission_physical_layer.Encode(aux_message);
            std::cout << "[Binary] Coded: ";
            transmission_physical_layer.PrintEncodedTable();
            
            aux_message = transmission_physical_layer.GetEncodedTable();
            break;
        }
        
        case 2: 
        {
            ManchesterCodification transmission_physical_layer;
            
            transmission_physical_layer.Encode(aux_message);
            std::cout << "[Manchester] Coded: ";
            transmission_physical_layer.PrintEncodedTable();
            
            aux_message = transmission_physical_layer.GetEncodedTable();
            break;
        }

        case 3: 
        {
            BipolarCodification transmission_physical_layer;
            
            transmission_physical_layer.Encode(aux_message);
            std::cout << "[Bipolar] Coded: ";
            transmission_physical_layer.PrintEncodedTable();
            
            aux_message = transmission_physical_layer.GetEncodedTable();
            break;
        }

        default:
            std::cout << "aí cê ramelou em menó";
    }

    return aux_message;


}

void Application::Receive() {

    BITSET_VECTOR aux_message = this->bit_stream_;
    ApplicationLayer reception_application_layer;

    switch (this->codification_option_) {
        case 1:
        {
            BinaryCodification reception_physical_layer;

            reception_physical_layer.Decode(aux_message);
            std::cout << "[Binary] Decoded: ";
            reception_physical_layer.PrintDecodedTable();
            
            aux_message = reception_physical_layer.GetDecodedTable();
            break;
        }

        case 2:
        {
            ManchesterCodification reception_physical_layer;

            reception_physical_layer.Decode(aux_message);
            std::cout << "[Manchester] Decoded: ";
            reception_physical_layer.PrintDecodedTable();
            
            aux_message = reception_physical_layer.GetDecodedTable();
            break;
        }

        case 3:
        {
            BipolarCodification reception_physical_layer;

            reception_physical_layer.Decode(aux_message);
            std::cout << "[Bipolar] Decoded: ";
            reception_physical_layer.PrintDecodedTable();
            
            aux_message = reception_physical_layer.GetDecodedTable();
            break;
        }

        default:
            break;
    }


    switch (this->framing_option_)
    {
        case 1:
        {
            LinkLayer reception_link_layer;

            reception_link_layer.DecodeCharacterCount(aux_message);
            std::cout << "[CharacterCount] Unframed: ";
            reception_link_layer.PrintNoHeaderTable();

            aux_message = reception_link_layer.GetNoHeaderTable();
            break;
        }

        case 2:
        {
            LinkLayer reception_link_layer;

            reception_link_layer.DecodeByteInsertion(aux_message);
            std::cout << "[ByteInsertion] Unframed: ";
            reception_link_layer.PrintNoHeaderTable();

            aux_message = reception_link_layer.GetNoHeaderTable();
            break;
        }

        default:
            std::cout << "[Invalid Framing Option] aí cê ramelou em menó";
    }

    

    reception_application_layer.Translate(aux_message);

    std::cout << "\nTranslated received message: " 
        << reception_application_layer.GetMessage() << "\n";
    
}