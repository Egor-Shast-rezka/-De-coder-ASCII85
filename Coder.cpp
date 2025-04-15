/*
    Egor Shastin st129457@student.spbu.ru
    
    > The coder takes a string input from the user and converts it into ASCII85 encoded format, 
    grouping the data into 4-byte chunks and encoding each chunk into a set of ASCII characters. 
    > It then outputs the encoded result.
*/


#include "Coder.h"


// =============getUserValue============= 
std::string Coder::getUserValue() const {

    std::string value;

    // Prompt user for input
    std::cout << "Enter your string: ";
    std::getline(std::cin, value);

    // Check if in test mode and input is empty
    if (getIsTrue() && value.empty()) {
    
        throw std::invalid_argument("Data empty.");
    }

    // Loop until valid input is provided
    while (value.empty()) {
    
        std::cerr << "ERROR: Data empty.\n";
        std::cout << "Enter your string: ";
        std::getline(std::cin, value);
    }

    return value;
}


// =============encodeTuple============= 
std::string Coder::encodeTuple(uint32_t tuple, int bytesCount) const {

    std::string result;

    // If the tuple is 0 and has 4 bytes, return 'z' as a shortcut for 4 zero bytes.
    if (tuple == 0 && bytesCount == 4) {
    
        return "z";
    }

    // Array to hold encoded characters
    char encodedChars[5];
    
    // Encode tuple into 5 ASCII85 characters
    for (int i = 4; i >= 0; --i) {
    
        encodedChars[i] = (tuple % 85) + '!';
        tuple /= 85;
    }

    // Add characters to result for the actual number of bytes processed
    for (int i = 0; i < bytesCount + 1; ++i) {
    
        result += encodedChars[i];
    }

    return result;
}


// =============codeSTRING============= 
std::string Coder::codeSTRING(const std::string& input) const {

    std::string encoded;
    uint32_t tuple = 0;
    int count = 0;

    // Process input 4 bytes at a time
    for (size_t i = 0; i < input.size(); ++i) {
    
        tuple = (tuple << 8) | (static_cast<char>(input[i])); // Build the tuple from the input
        count++;

        // Once 4 bytes are collected, encode the tuple
        if (count == 4) {
        
            encoded += encodeTuple(tuple);
            tuple = 0;
            count = 0;
        }
    }

    // If there are remaining bytes (less than 4), encode them with padding
    if (count > 0) {
    
        tuple <<= (4 - count) * 8; // Shift to pad the remaining bytes
        encoded += encodeTuple(tuple, count); // Encode the last incomplete tuple
    }

    return encoded;
}

// =============printResultCoder============= 
void Coder::printResultCoder(std::string& result) const {
    
    std::cout << "\nEncoded message: " << result << "\n";
}



















