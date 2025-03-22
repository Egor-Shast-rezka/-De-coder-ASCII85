/*
    Egor Shastin st129457@student.spbu.ru
    
    This is code for unit testing all classes by using Google Test
*/


#include <gtest/gtest.h>
#include "Decoder.h"
#include "Coder.h"


// ============= Test decodeASCII85 with valid data =============
TEST(DecoderTest, DecodeValidASCII85) {

    Decoder decoder;
    
    // Example of a valid ASCII85 encoded string
    std::string validInput = "87cURD]i,\"Ebo7";
    
    // Expected result after decoding
    std::vector<uint8_t> expectedOutput = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};

    // Run decodeASCII85
    std::vector<uint8_t> decodedData = decoder.decodeASCII85(validInput);
    
    // Verify the result matches the expected output
    EXPECT_EQ(decodedData, expectedOutput);
}


// ============= Test decodeASCII85 with invalid data =============
TEST(DecoderTest, DecodeInvalidASCII85) {

    Decoder decoder;
    
    // Example of a invalid ASCII85 encoded string
    std::string invalidInput = "&@)()!()*&FHF~}}{:?";
    
    EXPECT_THROW(decoder.decodeASCII85(invalidInput), std::runtime_error);
}


// ============= Test decodeASCII85 With z =============
TEST(DecoderTest, DecodeInvalidASCII85WithZ) {

    Decoder decoder;
    
    // Example of a invalid ASCII85 encoded string
    std::string invalidInput = "!z";
    
    EXPECT_THROW(decoder.decodeASCII85(invalidInput), std::runtime_error);
}


// ============= Test printResultDecoder =============
TEST(DecoderTest, PrintResultDecoder) {

    Decoder decoder;
    
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
    
    // Empty decoded data
    std::vector<uint8_t> emptyData;

    // Expect the method to throw an invalid_argument exception
    EXPECT_THROW(decoder.printResultDecoder(emptyData), std::invalid_argument);
}


// ============= Test codeSTRING with valid data =============
TEST(CoderTest, codeSTRINGWithValidData) {

    Coder coder;  // Create an instance of the Coder class.
    
    std::string validInput = "Hello World";  // Define the valid input string.
    
    std::string expectedOutput = "87cURD]i,\"Ebo7";  // The expected output after encoding.

    std::string encodedData = coder.codeSTRING(validInput);  // Call the method to encode the input string.
    
    // Assert that the encoded data matches the expected output.
    EXPECT_EQ(encodedData, expectedOutput);
}


// ============= printResultCoder =============
TEST(CoderTest, printResultCoderTest) {

    Coder coder;  // Create an instance of the Coder class.
    std::string testEncodedMessage = "87cURD]i,\"Ebo7";  // Define the encoded message to print.

    // Capture the standard output using ostringstream
    std::ostringstream capturedOutput;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf();  // Save the original cout buffer.
    std::cout.rdbuf(capturedOutput.rdbuf());  // Redirect cout to capturedOutput stream.

    // Call the method that is being tested
    coder.printResultCoder(testEncodedMessage);

    // Restore the original cout buffer to avoid affecting other parts of the program
    std::cout.rdbuf(originalCoutBuffer);

    // Define the expected output that should have been printed
    std::string expectedOutput = "\nEncoded message: 87cURD]i,\"Ebo7\n";

    // Assert that the captured output matches the expected output.
    EXPECT_EQ(capturedOutput.str(), expectedOutput);
}


// ============= Test printResultCoder with empty data =============
TEST(CoderTest, PrintResultCoderWithEmptyData) {

    Coder coder;  // Create an instance of the Coder class.
    
    // Define an empty string as input
    std::string emptyData;

    // Expect the method to throw an invalid_argument exception if the input is empty
    EXPECT_THROW(coder.printResultCoder(emptyData), std::invalid_argument);
}


// ============= Test printResultDecoder with empty data =============
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}









