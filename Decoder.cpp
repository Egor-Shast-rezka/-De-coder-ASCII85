/*
    Egor Shastin st129457@student.spbu.ru
    
    This code defines a Decoder class that:
    > Prompts the user to input ASCII85 encoded data.
    > Handles symbol processing for decoding.
    > Decodes ASCII85 encoded strings into binary data.
    > Prints the decoded result or throws an error if the data is invalid.
*/


#include "Decoder.h"


// =============getUserValue============= 
std::string Decoder::getUserValue() const {

    std::string value;

    // Prompt user for input
    std::cout << "Enter ASCII85 encoded data: ";
    std::getline(std::cin, value);

    // Loop until valid input is provided
    while (value.empty()) {
    
        std::cerr << "ERROR: Data empty.\n";
        std::cout << "Enter ASCII85 encoded data: ";
        std::getline(std::cin, value);
    }

    return value;
}


// =============decodeASCII85============= 
std::vector<uint8_t> Decoder::decodeASCII85(const std::string& input) const {

    std::vector<uint8_t> decodedData; // Answer
    uint32_t tuple = 0; // Store decoded 32-bit value
    int count = 0; // Number of processed characters in the group

    for (size_t i = 0; i < input.size(); ++i) {
    
        char ch = input[i];

        // Skip whitespace and invalid characters
        if (ch == ' ' || ch == '\r' || ch == '\t') {
        
            continue;
        }

        // Handle 'z' shortcut for 4 zero bytes
        if (ch == 'z') {
        
            if (count != 0) {
            
                throw std::runtime_error("'z' cannot appear inside a partial group");
            }
            decodedData.push_back(0);
            decodedData.push_back(0);
            decodedData.push_back(0);
            decodedData.push_back(0);
            continue;
        }

        // Validate ASCII85 character
        if (ch < '!' || ch > 'u') {
        
            throw std::runtime_error("Invalid character in ASCII85 encoded string");
        }

        // Build tuple by converting ASCII85 characters to base 85
        tuple = tuple * 85 + (ch - '!');
        count++;

        // When a group of 5 characters is complete, convert to 4 bytes
        if (count == 5) {
        
            decodedData.push_back((tuple >> 24) & 0xFF);
            decodedData.push_back((tuple >> 16) & 0xFF);
            decodedData.push_back((tuple >> 8) & 0xFF);
            decodedData.push_back(tuple & 0xFF);
            tuple = 0;
            count = 0;
        }
    }

    // Handle the last incomplete tuple (if less than 5 characters remain)
    if (count > 0) {
    
        for (int j = count; j < 5; ++j) {
        
            tuple = tuple * 85 + 84; // Padding with 'u'
        }
        for (int j = 0; j < count - 1; ++j) {
        
            decodedData.push_back((tuple >> (24 - j * 8)) & 0xFF);
        }
    }

    return decodedData;
}


// =============printResultDecoder============= 
void Decoder::printResultDecoder(std::vector<uint8_t>& result) const {

    // Check if decoded data is empty
    if (result.empty()) {
    
        throw std::invalid_argument("Invalid data. The decoded result cannot be empty.");
    }

    // Convert decoded bytes to a string and print the result
    std::string decodedMessage(result.begin(), result.end());
    std::cout << "\nDecoded message: " << decodedMessage << "\n";
}













