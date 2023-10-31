// RBE104TC Coursework 1
// Name: Chukwudalu Precious Chibeze
// Student ID: 2254178
// Programme: Intelligent Robotics Engineering with Contemporary Entrepreneurialism

#include <iostream> // Include the header for input and output.
#include <cstring>  // Include the header for C-style string manipulation.
// Include necessary C++ libraries for the program

// Functions for Exercise 2.

// Function to check if the input consists of uppercase letters only.
bool isUppercase(const char* str) 
{
    // The function takes a C-style string as input, which is a pointer to the first character.

    while (*str) 
    {
        // The while loop iterates through the string until it reaches the null terminator ('\0'),
        // which marks the end of the string.

        if (*str < 'A' || *str > 'Z') 
        {
            // If the current character is not in the range 'A' to 'Z',
            // it means it's not an uppercase letter.

            return false; // Return false immediately.
        }

        str++; // Move to the next character.
    }

    // If the loop completes without encountering a non-uppercase letter,
    // it means all characters are uppercase, so return true.
    return true;
}

// Function to find the first occurrence of obj in the source.
char* findC(const char* source, const char* obj) 
{
    // Check if either the source or obj is a null pointer (nullptr).
    if (source == nullptr || obj == nullptr) 
    {
        return nullptr; // Return nullptr if either of the input pointers is nullptr.
    }

    int sourceLen = strlen(source);
    int objLen = strlen(obj);

    // Loop through the source and search for obj.
    for (int i = 0; i <= sourceLen - objLen; i++) 
    {
        // Use strncmp to compare a substring of the source with obj.
        if (strncmp(source + i, obj, objLen) == 0) 
        {
            // If a match is found, return a pointer to the start of the match.
            return const_cast<char*>(source + i);
        }
    }

    // If no match is found, return nullptr.
    return nullptr;
}

int main() 
{
    // Exercise 2.

char source[100]; // Declare an array to store the source string
char obj[100];    // Declare an array to store the destination string

    // Validate and obtain the source character sequence.
    while (true) 
    {
        std::cout << "Enter the source character sequence (uppercase only): ";
        std::cin.getline(source, sizeof(source));
        
        if (isUppercase(source)) 
        {
            break; // Exit the loop if the input is uppercase.
        } 
        else 
        {
            std::cout << "Invalid input. Please enter uppercase characters only." << std::endl;
            // If the input is not uppercase, display an error message and repeat the loop.
        }
    }

    // Validate and obtain the obj character sequence to search.
    while (true) 
    {
        std::cout << "Enter the character sequence to search (obj, uppercase only): ";
        std::cin.getline(obj, sizeof(obj));
        
        if (isUppercase(obj)) 
        {
            break; // Exit the loop if the input is uppercase.
        } 
        else 
        {
            std::cout << "Invalid input. Please enter uppercase characters only." << std::endl;
            // If the input is not uppercase, display an error message and repeat the loop.
        }
    }

    // Call the findC function to search for obj in source.
    char* result = findC(source, obj);

    if (result != nullptr) 
    {
        // If a match is found, the result will point to the start of the match.

        int position = result - source + 1;
        // Calculate the position of the first matching character by subtracting
        // the result pointer from the source pointer and adding 1 (1-based indexing).

        std::cout << "Match found at position " << position << " in the source." << std::endl;
        // Print the position of the match.

        std::cout << "First matching character: " << *result << std::endl;
        // Print the first matching character (the character pointed to by result).
    } 
    else 
    {
        std::cout << "No match found." << std::endl;
        // If no match is found, display a message indicating that.
    }

    return 0;
}
