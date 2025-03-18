/*
    Egor Shastin st129457@student.spbu.ru
    This is code for testing all classes by using Google Test
*/


#include <gtest/gtest.h>
#include "Decoder.h"


// ============= Test setIsTrue and getIsTrue =============
TEST(DecoderTest, SetAndGetIsTrue) {
    
    Decoder decoder;
    
    // Test setting isTest to true
    decoder.setIsTest(true);
    EXPECT_TRUE(decoder.getIsTest());

    // Test setting isTest to false
    decoder.setIsTest(false);
    EXPECT_FALSE(decoder.getIsTest());
}


// ============= Test decodeASCII85 =============
TEST(DecoderTest, DecodeValidASCII85) {

    Decoder decoder;
    decoder.setIsTest(true);
    
    // Example of a valid ASCII85 encoded string
    std::string validInput = "87cURD]j7BEbo80";
    
    // Expected result after decoding
    std::vector<uint8_t> expectedOutput = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'};

    // Run decodeASCII85
    std::vector<uint8_t> decodedData = decoder.decodeASCII85(validInput);
    
    // Verify the result matches the expected output
    EXPECT_EQ(decodedData, expectedOutput);
}


// ============= Test printResultDecoder =============
TEST(DecoderTest, PrintResultDecoder) {

    Decoder decoder;
    decoder.setIsTest(true);
    
    // Valid decoded data to print
    std::vector<uint8_t> decodedData = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd' };

    // Redirect std::cout output to stringstream to verify printed output
    std::stringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    // Call the method to print the decoded result
    decoder.printResultDecoder(decodedData);

    // Restore std::cout
    std::cout.rdbuf(oldCoutBuffer);

    // Verify the output is as expected
    EXPECT_EQ(output.str(), "\nDecoded message: Hello World\n");
}


// ============= Test printResultDecoder with empty data =============
TEST(DecoderTest, PrintResultDecoderWithEmptyData) {

    Decoder decoder;
    decoder.setIsTest(true);
    
    // Empty decoded data
    std::vector<uint8_t> emptyData;

    // Expect the method to throw an invalid_argument exception
    EXPECT_THROW(decoder.printResultDecoder(emptyData), std::invalid_argument);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
