/*
    Egor Shastin st129457@student.spbu.ru
    
    The program allows the user to choose between two options: 
    decoding an ASCII85 encoded string or encoding a string into ASCII85 format.
*/


#include "Decoder.h"
#include "Coder.h"


int CheckUserAnswer(std::string str, std::vector<int> values) { // Function to display a prompt and validate user's input against allowed values

    std::cout << str;  // Display the prompt to the user
    int answer = 0;  // Variable to store the user's input
    
    std::cin >> answer;
    
    while (std::find(values.begin(), values.end(), answer) == values.end()) {  // Loop until a valid input is received
    
        std::cout << "Invalid input. Please try again.\n";  // Error message if input is invalid
        std::cin.clear();
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << str;
        std::cin >> answer;
        
    }
    return answer;  // Return the valid user input
}


bool resetProgram() { // Function to check if the user wants to run the program again

    int answer = CheckUserAnswer("Do you want to restart? (1 - Yes, 2 - No): ", {1, 2});
    
    std::cout << "\n";
    
    return answer == 1;
}


int main() {

    do {
        try {
        
            // Ask the user if they want to decode or encode
            int answer = CheckUserAnswer("Choose (1 - Decoder, 2 - Encoder) : ", {1, 2});
        
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
            if (answer == 1) {
            
                // User chose Decoder
                Decoder decoder;
        
                std::string value = decoder.getUserValue();  // Get the user's ASCII85 encoded data
                std::vector<uint8_t> result = decoder.decodeASCII85(value);  // Decode the data
        
                decoder.printResultDecoder(result);  // Print the decoded result
                
            } else {
            
                // User chose Encoder
                Coder coder;
        
                std::string value = coder.getUserValue();  // Get the string to encode
                std::string result = coder.codeSTRING(value);  // Encode the string into ASCII85
            
                coder.printResultCoder(result);  // Print the encoded result
            }
        
        } catch (const std::runtime_error& e) {
        
            // Handle runtime errors (e.g., invalid characters in decoding)
            std::cerr << "\nDecoding error: " << e.what() << "\n";
        
        } catch (const std::invalid_argument& e) {
        
            // Handle other exceptions (e.g., invalid input or empty data)
            std::cerr << "\nUser interaction error: " << e.what() << "\n";
        }
    } while (resetProgram());  // Repeat the program if the user chooses to restart
    
    return 0;
}














