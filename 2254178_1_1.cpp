// RBE104TC Coursework 1
// Name: Chukwudalu Precious Chibeze
// Student ID: 2254178
// Programme: Intelligent Robotics Engineering with Contemporary Entrepreneurialism

#include <iostream> // Include the header for input and output.
#include <string>   // Include the header for string manipulation.
#include <limits>   // Include the header for limiting data types.
#include <cmath>    // Include the header for mathematical functions and constants.
#include <sstream>  // Include the header for stream processing.
#include <iomanip>  // Include the header for manipulatiing input and output operations.
#include <cctype>   // Include the header for character checking.
// Include necessary C++ libraries for the program.


// Functions for Exercise 1.

// Functions for the input of Name.
// Define a function to check if a string contains only alphabetic characters and white spaces.
bool isValidName(const std::string& name) 
{
    for (char c : name) 
    {
        // Iterate through each character in the input string 'name'.

        if (!isalpha(c) && !isspace(c)) 
        {
            // Check if the character is not alphabetic and not a white space.
            return false;  // If an invalid character is found, return false immediately.
        }
    }

    return true;  // If all characters are alphabetic or white spaces, return true.
}
// Define a function to get a valid name from the user.
std::string getValidName() 
{
    std::string fullName;
    // Declare a string to store the user's input.

    while (true) 
    {
        // Start a validation loop that continues until a valid name is provided.

        std::cout << "Enter your complete name: ";
        std::getline(std::cin, fullName);
        // Prompt the user to enter their complete name and store it in the 'fullName' string.

        if (isValidName(fullName)) 
        {
            // Call the 'isValidName' function to check the validity of the input.

            return fullName;
            // If the name is valid, return it.
        }
        else 
        {
            std::cout << "Invalid input. Please use only characters and white spaces.\n";
            // If the input is invalid, display an error message and repeat the loop.
        }
    }
}

// Functions for the input of 11-digit phone number.
// Define a function to check if a string is a valid 11-digit phone number.
bool isValidPhoneNumber(const std::string& input) 
{
    // Check if the input is exactly 11 digits and contains only digits (no characters or special characters).
    return (input.length() == 11) && (input.find_first_not_of("0123456789") == std::string::npos);
}
// Define a function to get a valid 11-digit phone number from the user.
std::string getValidPhoneNumber() 
{
    std::string phoneNumber;
    // Declare a string to store the user's input.

    while (true) 
    {
        // Start a validation loop that continues until a valid phone number is provided.

        std::cout << "Enter your 11-digit telephone number: ";
        std::getline(std::cin, phoneNumber);
        // Prompt the user to enter their 11-digit telephone number and store it in the 'phoneNumber' string.

        if (isValidPhoneNumber(phoneNumber)) 
        {
            // Call the 'isValidPhoneNumber' function to check the validity of the input.

            return phoneNumber;
            // If the input is a valid phone number, return it.
        } 
        else 
        {
            std::cout << "Invalid input. Please enter an 11-digit integer with no characters or special characters.\n";
            // If the input is not valid, display an error message and repeat the loop.
        }
    }
}

// Functions for the input of 2-digit decimal number.
// Define a function to obtain a valid 2-digit decimal number from the user.
int getValidTwoDigitDecimal() 
{
    std::string input;    // Declare a string variable to store user input.
    int decimalNumber;    // Declare an integer variable to store the valid decimal number.

    while (true) 
    {
        std::cout << "Enter a 2-digit decimal number: ";  // Prompt the user to input a 2-digit decimal number.
        std::cin >> input;  // Read the user's input as a string.

        // Check if the input has a length of 2, consists of digits, and is within the range of 10 to 99.
        if (input.length() == 2 && std::isdigit(input[0]) && std::isdigit(input[1])) 
        {
            decimalNumber = std::stoi(input);  // Convert the valid input string to an integer.
            
            if (decimalNumber >= 10 && decimalNumber <= 99) 
            {
                return decimalNumber;  // Return the valid 2-digit decimal number.
            }
        }

        std::cout << "Invalid input. Please enter a 2-digit decimal number.\n";  // Display an error message for invalid input.
    }
}

// Functions for the input and output of Temperature.
// Define the absolute zero temperature in degrees Celsius.
const double absoluteZeroCelsius = -273.15; 
// Declare a constant double variable to store the value of the absolute zero temperature in degrees Celsius.
// Function to check if a string consists of numeric characters.
bool isNumeric(const std::string& str) 
{
    size_t dotCount = 0;
    // Initialize a counter to keep track of the number of decimal points found.

    for (char c : str) 
    {
        // Iterate through each character in the input string 'str'.

        if (!std::isdigit(c) && c != '.') 
        {
            // Check if the character is not a digit and not a decimal point.
            return false; // If an invalid character is found, return false immediately.
        }
        
        if (c == '.') 
        {
            // If a decimal point is encountered, increment the dotCount.
            dotCount++;
        }
    }

    return dotCount <= 1;
}
// Function to convert temperature from Celsius to Fahrenheit and Kelvin and round to the nearest whole number.
void convertTemperature(double celsius, double& fahrenheit, double& kelvin) 
{
    // Calculate the temperature in Fahrenheit and Kelvin.
    fahrenheit = static_cast<int>(std::round(celsius * 9.0 / 5.0 + 32.0));
    kelvin = static_cast<int>(std::round(celsius + 273.15));
}
// Function to obtain a valid temperature in degrees Celsius from the user.
double getValidTemperatureCelsius() 
{
    double temperatureCelsius;
    // Declare a double variable to store the value of temperature in degree Celsius.

    while (true) 
    {
        std::cout << "Enter the temperature in degrees Celsius: ";
        std::string userInput;
        std::cin >> userInput;
        // Prompt the user to enter the temperature and store it as a string in 'userInput'.

        if (isNumeric(userInput)) 
        {
            // Check if the input consists of numeric characters and at most one decimal point.

            std::istringstream ss(userInput);
            ss >> temperatureCelsius;
            // Convert the valid string input to a double value 'temperatureCelsius'.

            if (temperatureCelsius >= absoluteZeroCelsius) 
            {
                // Check if the temperature is equal to or above absolute zero (-273.15°C).
                break;
            }
            else 
            {
                std::cout << "Invalid input. Please enter a temperature equal to or above absolute zero (-273.15°C).\n";
                // If the temperature is below absolute zero, display an error message and repeat the loop.
            }
        }
        else 
        {
            std::cin.clear(); // Clear any error flags in the input stream.
            std::cout << "Invalid input. Please enter a numeric temperature value.\n";
            // If the input is not a valid number, display an error message and repeat the loop.
        }
    }

    return temperatureCelsius;
    // Return the valid temperature in degrees Celsius.
}

// Functions for the input of a, b and c in the quadratic equation solver.
// Function to check if a string represents a valid numeric value.
bool isNumericQuad(const std::string& str) 
{
    std::istringstream ss(str);   // Create a string stream for conversion.
    double num;
    ss >> num;  // Try to convert the string to a double.

    // Check if the conversion was successful and if there are no remaining characters.
    return ss.eof() && !ss.fail();
}

int main() 
{
    // Exercise 1.1.

    // Call the getValidName function to obtain a valid name.
    std::string validFullName = getValidName();
    std::cout << "You entered a valid name: " << validFullName << std::endl;
    // Now 'validFullName' contains a valid name.

    // Call the getValidPhoneNumber function to obtain a valid phone number.
    std::string validPhoneNumber = getValidPhoneNumber();
    std::cout << "You entered a valid phone number: " << validPhoneNumber << std::endl;
    // Now 'validPhoneNumber' contains a valid phone number.

    // Call the function to get a valid 2-digit decimal number.
    int validDecimalNumber = getValidTwoDigitDecimal(); 
    std::cout << "You entered a valid 2-digit decimal number: " << validDecimalNumber << std::endl;
    // Now 'validDecimalNumber' contains a valid 2-digit decimal number.

    // Call the function to get a valid temperature in degrees Celsius.
    double validTemperatureCelsius = getValidTemperatureCelsius();  
    std::cout << "You entered a valid temperature in degrees Celsius: " << validTemperatureCelsius << "°C" << std::endl;
    // Now 'validTemperatureCelsius' contains a valid temperature in degrees Celsius.

    // Exercise 1.2.

    // Extract the first six digits from the validPhoneNumber.
    std::string firstSixDigits = validPhoneNumber.substr(0, 6);

    // Extract the next five digits starting from the 7th digit.
    std::string lastFiveDigits = validPhoneNumber.substr(6, 5);

    // Convert the first six digits to an integer.
    int firstPart = std::stoi(firstSixDigits);

    // Convert the next five digits to an integer.
    int secondPart = std::stoi(lastFiveDigits);

    // Perform the division operation and store the result as a double.
    // Ensure that you handle possible division by zero errors.
    double result = static_cast<double>(firstPart) / static_cast<double>(secondPart);

    // Print the result of the division.
    std::cout << "First 6 digits / Last 5 digits = " << result << std::endl;

    // Exercise 1.3.

    // Display an integer in decimal, octal, and hexadecimal formats.
    std::cout << "Decimal: " << validDecimalNumber << std::endl;
    std::cout << "Octal: " << std::oct << validDecimalNumber << std::endl;
    std::cout << "Hexadecimal: " << std::hex << std::uppercase << validDecimalNumber << std::endl;
    // Display an integer in decimal, octal, and hexadecimal formats using stream manipulators.

    // Exercise 1.4.

    // Convert the Celsius temperature to Fahrenheit and Kelvin.
    double fahrenheit, kelvin; // Declare double variables fahrenheit and kelvin to store temperature in respective degrees.
    convertTemperature(validTemperatureCelsius, fahrenheit, kelvin); // Convert the Celsius temperature to Fahrenheit and Kelvin.

    // Display the user's valid input and the converted temperatures (rounded to the nearest whole number).
    std::cout << "You entered a valid temperature in degrees Celsius: " << validTemperatureCelsius << "°C" << std::endl;
    std::cout << "Converted to degrees Fahrenheit: " << fahrenheit << "°F" << std::endl;
    std::cout << "Converted to degrees Kelvin: " << kelvin << "°K" << std::endl;

    // Exercise 1.5.

    // Quadratic equation solver.
    double a, b, c; // Declare double variables a, b and c to store the coefficients of the quadratic equation.
    bool validInput = true;  // Initialize a flag to track valid input.

    do 
    {
        validInput = true;  // Reset the flag for valid input.

        std::string inputA;  // Declare a string variable to store user input.
        std::cout << "Enter the value of 'a' in the quadratic equation (ax^2 + bx + c): ";
        std::cin >> inputA;  // Read user input for 'a'.

        if (!isNumericQuad(inputA) || std::stod(inputA) == 0)  // Add a condition to check if 'a' is not numeric or is equal to 0.
        {
            std::cout << "Invalid input for 'a'. Please enter a valid non-zero numeric value for 'a." << std::endl;
            validInput = false;  // Set the flag to indicate invalid input.
        } 
        else 
        {
            a = std::stod(inputA);  // Convert the valid input to a double and store it in 'a'.
        }

    } 
    while (!validInput);  // Repeat the loop until valid input for 'a' is provided.

    do 
    {
        validInput = true;  // Reset the flag for valid input.

        std::string inputB;  // Declare a string variable to store user input.
        std::cout << "Enter the value of 'b': ";
        std::cin >> inputB;  // Read user input for 'b'.

        if (!isNumericQuad(inputB)) 
        {
            std::cout << "Invalid input for 'b'. Please enter a valid numeric value for 'b." << std::endl;
            validInput = false;  // Set the flag to indicate invalid input.
        } 
        else 
        {
            b = std::stod(inputB);  // Convert the valid input to a double and store it in 'b'.
        }

    } 
    while (!validInput);  // Repeat the loop until valid input for 'b' is provided.

    do 
    {
        validInput = true;  // Reset the flag for valid input.

        std::string inputC;  // Declare a string variable to store user input.
        std::cout << "Enter the value of 'c': ";
        std::cin >> inputC;  // Read user input for 'c'.

        if (!isNumericQuad(inputC)) 
        {
            std::cout << "Invalid input for 'c'. Please enter a valid numeric value for 'c." << std::endl;
            validInput = false;  // Set the flag to indicate invalid input.
        } 
        else 
        {
            c = std::stod(inputC);  // Convert the valid input to a double and store it in 'c'.
        }

    } 
    while (!validInput);  // Repeat the loop until valid input for 'c' is provided.

if (a == 0) 
{
    std::cout << "Invalid input: 'a' cannot be zero." << std::endl;
} 
else 
{
    // Calculate the discriminant of the quadratic equation.
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        // Calculate two distinct real roots when the discriminant is positive.
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "Two distinct real roots: x1 = " << root1 << ", x2 = " << root2 << std::endl;
    } 
    else if (discriminant == 0) 
    {
        // Calculate a single real root when the discriminant is zero.
        double root = -b / (2 * a);
        std::cout << "Two equal real roots: x = " << root << std::endl;
    } 
    else 
    {
        // Handle the case when the discriminant is negative (no real roots).
        std::cout << "No real roots." << std::endl;
    }
}
    // Solve the quadratic equation, considering different cases and displaying the results.

    return 0;
}