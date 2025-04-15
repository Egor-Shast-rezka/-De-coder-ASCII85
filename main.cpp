/*
    Egor Shastin st129457@student.spbu.ru
    
    The program allows the user to choose between two options: 
    decoding an ASCII85 encoded string or encoding a string into ASCII85 format.
*/


#include "Decoder.h"
#include "Coder.h"


int main(int argc, char* argv[]) {

    if (argc == 2) {
    
        std::string flag = argv[1];
        
        try {
            if (flag == "-d") {
            
                Decoder decoder;
                std::string value = decoder.getUserValue();
                std::vector<uint8_t> result = decoder.decodeASCII85(value);
                decoder.printResultDecoder(result);
                
            } else if (flag == "-e") {
            
                Coder coder;
                std::string value = coder.getUserValue();
                std::string result = coder.codeSTRING(value);
                coder.printResultCoder(result);
                
            } else {
                std::cerr << "Unknown flag. Use -d for decode or -e for encode.\n";
                return 1;
            }
        } catch (const std::runtime_error& e) {
            std::cerr << "\nError: " << e.what() << "\n";
        } catch (const std::invalid_argument& e) {
            std::cerr << "\nUser interaction error: " << e.what() << "\n";
        }
    }
    return 0;
}














