/*
    Egor Shastin st129457@student.spbu.ru
    
    This is code for testing all classes by using Google Test
*/


#include <gtest/gtest.h>
#include <random>
#include "Decoder.h"
#include "Coder.h"


// ============= Random test with valid data =============
TEST(RandomValidTest, RandomValidTest) {

    Decoder decoder;
    Coder coder;
    
    std::string validInput = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstu";

    for (int i = 0; i < 1000; ++i) {
        
        std::random_device rd;
        std::mt19937 gen(rd());
        
        std::uniform_int_distribution<> rand_num(0, static_cast<int>(validInput.size()) - 1);
        std::uniform_int_distribution<> rand_len(1, 200000);
        
        int current_len_word = rand_len(gen);
        
        std::string current_word_ASCII85;
        std::string current_word_normal;
        
        for (int j = 1; j <= current_len_word; ++j) {
            
            current_word_ASCII85 += validInput[rand_num(gen)];
        }
        
        current_word_normal = coder.codeSTRING(current_word_ASCII85);
        
        std::vector<uint8_t> current_word_ASCII85_new = decoder.decodeASCII85(current_word_normal);
        
        std::string current_word_ASCII85_new_str(current_word_ASCII85_new.begin(), current_word_ASCII85_new.end());
        
        EXPECT_EQ(current_word_ASCII85, current_word_ASCII85_new_str);
        
        if (i % 200 == 0) {
            std::cout << "200 test completed.\n";
        }
    }
}



// ============= add Invalid Character To String =============
std::string addInvalidCharacterToString(const std::string& validData) {
    
    std::vector<uint8_t> invalidCharacters = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
        0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13,
        0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,
        0x1E, 0x1F, 0x7F, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86,
        0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90,
        0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A,
        0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE,
        0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8,
        0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF
    };

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> randIndex(0, static_cast<int>(invalidCharacters.size()) - 1);
    
    uint8_t invalidChar = invalidCharacters[randIndex(gen)];
    
    std::uniform_int_distribution<> randPos(0, validData.size());
    int pos = randPos(gen);

    std::string result = validData;
    result.insert(pos, 1, invalidChar);

    return result;
}


// ============= Random test with invalid data =============
TEST(RandomInalidTest, RandomInalidTest) {

    Decoder decoder;
    
    std::string validInput = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

    for (int i = 0; i < 1000; ++i) {
        
        std::random_device rd;
        std::mt19937 gen(rd());
        
        std::uniform_int_distribution<> rand_num(0, static_cast<int>(validInput.size() - 1));
        std::uniform_int_distribution<> rand_len(1, 200000);
        
        int current_len_word = rand_len(gen);
        
        std::string current_word_ASCII85_valid;
        
        for (int j = 1; j <= current_len_word; ++j) {
            
            current_word_ASCII85_valid += validInput[rand_num(gen)];
        }
        
        std::string current_word_ASCII85_invalid = addInvalidCharacterToString(current_word_ASCII85_valid);
        
        EXPECT_THROW(decoder.decodeASCII85(current_word_ASCII85_invalid), std::runtime_error);
        
        if (i % 200 == 0) {
            std::cout << "200 test completed.\n";
        }
    }
}


// ============= Test printResultDecoder with empty data =============
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

