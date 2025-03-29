/*
    Egor Shastin st129457@student.spbu.ru
    
    This code defines a Decoder class that handles ASCII85 decoding. 
    It retrieves user input, decodes the ASCII85 encoded data, and prints the decoded result.
*/


#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdint>


#ifndef DECODER_H
#define DECODER_H


class Decoder {
public:
    
    virtual std::string getUserValue() const; // Get user answer (user`s ASCII85 code)
    
    std::vector<uint8_t> decodeASCII85(const std::string& input) const; // Decode user`s ASCII85 code
    
    void printResultDecoder(std::vector<uint8_t>& result) const; // Print users decoding user`s ASCII85 code
};


#endif
