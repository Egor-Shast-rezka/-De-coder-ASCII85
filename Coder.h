/*
    Egor Shastin st129457@student.spbu.ru
    
    The Coder class, which inherits from Decoder.
    It provides methods to encode a string into ASCII85 and print 
*/


#include "Decoder.h"


#ifndef CODER_H
#define CODER_H


class Coder : public Decoder {
public:

    std::string getUserValue() const override;   // Prompts the user to input a string

    std::string encodeTuple(uint32_t tuple, int bytesCount = 4) const;  // Encodes a tuple into ASCII85

    std::string codeSTRING(const std::string& input) const;  // Encodes a string into ASCII85

    void printResultCoder(std::string& result) const;  // Prints the encoded result
};


#endif
