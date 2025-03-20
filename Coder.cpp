/*
    Egor Shastin st129457@student.spbu.ru
    
    
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

    if (tuple == 0 && bytesCount == 4) {
    
        return "z";
    }

    char encodedChars[5];
    for (int i = 4; i >= 0; --i) {
    
        encodedChars[i] = (tuple % 85) + '!';
        tuple /= 85;
    }

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

    for (size_t i = 0; i < input.size(); ++i) {
    
        tuple = (tuple << 8) | (static_cast<char>(input[i]));
        count++;

        if (count == 4) {
        
            encoded += encodeTuple(tuple);
            tuple = 0;
            count = 0;
        }
    }

    if (count > 0) {
    
        tuple <<= (4 - count) * 8;
        encoded += encodeTuple(tuple, count);
    }

    return encoded;
}


// =============printResultCoder============= 
void Coder::printResultCoder(std::string& result) const {
    
    std::cout << result << "\n";
}





















