/*
    Egor Shastin st129457@student.spbu.ru
    
*/


#include "Decoder.h"


#ifndef CODER_H
#define CODER_H


class Coder : public Decoder {
public:

    std::string getUserValue() const override;
    
    std::string encodeTuple(uint32_t tuple, int bytesCount = 4) const;
    
    std::string codeSTRING(const std::string& input) const;
    
    void printResultCoder(std::string& result) const;
};


#endif
