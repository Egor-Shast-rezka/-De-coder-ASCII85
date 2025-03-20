/*
    Egor Shastin st129457@student.spbu.ru
    
    This main function. 
    This code defines a Decoder class that handles ASCII85 decoding.
*/


#include "Decoder.h"
#include "Coder.h"

#include <string>
#include <iostream>


int main() {
    
    try {
        
        std::cout << "Choose (1 - Decoder, 2 - Encoder) : ";
        int answer = 0;
        std::cin >> answer;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (answer == 1) {
            
            Decoder decoder;
            
            decoder.setIsTrue(false); // Set no test mode
        
            std::string value = decoder.getUserValue(); // Get user answer (user`s ASCII85 code)
            std::vector<uint8_t> result = decoder.decodeASCII85(value); // Decode user`s ASCII85 code
        
            decoder.printResultDecoder(result); // Print users decoding user`s ASCII85 code
        } else {
        
            Coder Coder;
            
            Coder.setIsTrue(false); // Set no test mode
        
            std::string value = Coder.getUserValue();
            std::string result = Coder.codeSTRING(value);
            
            Coder.printResultCoder(result);
        }
        
        
    } catch (const std::runtime_error& e) {
    
        // Handle specific runtime error (e.g., invalid characters)
        std::cerr << "\nDecoding error: " << e.what() << "\n";
        
    } catch (const std::invalid_argument& e) {
    
        // Handle other exceptions
        std::cerr << "\nUser interaction error: " << e.what() << "\n";
    }

    return 0;
}
