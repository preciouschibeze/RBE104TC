// RBE104TC Coursework 2
// Name: Chukwudalu Precious Chibeze
// Student ID: 2254178
// Programme: Intelligent Robotics Engineering with Contemporary Entrepreneurialism

#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

// Function to calculate the greatest common divisor of two integers.
int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Forward Declaration of iFraction and Complex Classes
class iFraction;
class Complex;

// Class for Fractions
class Fraction 
{
private:
    int top; // Numerator
    int down; // Denominator

protected:
    // Method to normalize the fraction (reduces it to its simplest form).
    void normalize() 
    {
        if (down == 0) 
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        if (down < 0) 
        {
            top = -top;
            down = -down;
        }
        int common = gcd(abs(top), down);
        top /= common;
        down /= common;
    }

public:
    // Constructor for the Fraction class.
    Fraction(int numerator, int denominator = 1) : top(numerator), down(denominator) 
    {
        normalize();
    }

    // Getter methods for numerator and denominator.
    int getNumerator() const 
    {
        return top;
    }

    int getDenominator() const 
    {
        return down;
    }

    // Setter method to update the fraction.
    void setFraction(int numerator, int denominator) 
    {
        top = numerator;
        down = denominator;
        normalize();
    }


    // Arithmetic operators
    Fraction operator+(const Fraction& other) const 
    {
        return Fraction(top * other.down + other.top * down, down * other.down);
    }

    Fraction operator-(const Fraction& other) const 
    {
        return Fraction(top * other.down - other.top * down, down * other.down);
    }

    Fraction operator*(const Fraction& other) const 
    {
        return Fraction(top * other.top, down * other.down);
    }

    Fraction operator/(const Fraction& other) const 
    {
        return Fraction(top * other.down, down * other.top);
    }

    // Comparison operators
    bool operator==(const Fraction& other) const 
    {
        return top * other.down == other.top * down;
    }

    bool operator!=(const Fraction& other) const 
    {
        return !(*this == other);
    }

    // Conversion to decimal
    double toDecimal() const 
    {
        return static_cast<double>(top) / down;
    }

    // Static method to create fraction from decimal
    static Fraction fromDecimal(double decimal, int precision = 1000000) 
    {
        return Fraction(static_cast<int>(decimal * precision), precision);
    }

    // Input and output
    friend ostream& operator<<(ostream& out, const Fraction& f) 
    {
        out << f.top << "/" << f.down;
        return out;
    }

    friend istream& operator>>(istream& in, Fraction& f) 
    {
        in >> f.top >> f.down;
        f.normalize();
        return in;
    }

    // Declaring iFraction and convertF as friend to allow access to private members.
    friend class iFraction;
    friend void convertF(const Fraction& f, iFraction& result);

};

// Function to validate if a string is a correctly formatted fraction input.
bool isValidFractionInput(const string& input) 
{
    stringstream ss(input);
    int numerator;
    char slash;
    int denominator = 1;

    if (!(ss >> numerator)) 
    {
        return false; 
    }

    if (ss >> slash) 
    {
        if (slash != '/' || !(ss >> denominator)) 
        {
            return false; 
        }
        if (denominator == 0)
        {
            return false; 
        }
    }

    string remaining;
    if (ss >> remaining) 
    {
        return false; // Invalid if extra characters are found after processing
    }

    return true;
}

// Function to get a Fraction object from user input.
Fraction getFractionFromUser(const string& prompt) 
{
    string input;
    while (true) 
    {
        cout << prompt;
        getline(cin, input);

        if (isValidFractionInput(input)) 
        {
            stringstream ss(input);
            int num, den = 1;
            char slash;

            ss >> num;
            if (ss >> slash) 
            {
                ss >> den;
            }

            return Fraction(num, den);
        } 
        else 
        {
            cout << "Invalid fraction. Please enter a valid fraction or a whole number: " << endl;
        }
    }
}

// Function to validate if a string is a correctly formatted decimal input.
bool isValidDecimalInput(const string& input) 
{
    stringstream ss(input);
    double value;
    if (!(ss >> value)) 
    {
        return false; // Failed to read as a decimal
    }
    return ss.eof(); // Check if we've reached the end of the string (no extra characters)
}

// Function to get a decimal number from user input and convert it to a fraction.
double getDecimalFromUser(const string& prompt) 
{
    string input;
    while (true) 
    {
        cout << prompt;
        getline(cin, input);

        if (isValidDecimalInput(input)) 
        {
            stringstream ss(input);
            double value;
            ss >> value;
            return value;
        }
        else 
        {
            cout << "Invalid input. Please enter a valid decimal number: " << endl;
        }
    }
}

// Class for Mixed Fraction.
class iFraction : public Fraction 
{
private:
    int integerPart; // Whole part of the mixed fraction

public:
    // Constructor for the iFraction Class
    iFraction(int whole = 0, int numerator = 0, int denominator = 1) : Fraction(numerator, denominator), integerPart(whole) 
    {
        normalizeMixedFraction();
    }

    // Normalize the mixed fraction
    void normalizeMixedFraction() 
    {
        int numerator = getNumerator();
        int denominator = getDenominator();
        bool isNegative = numerator < 0;
        numerator = abs(numerator);

        if (numerator >= denominator) 
        {
            integerPart += numerator / denominator;
            numerator %= denominator;
        }

        if (isNegative) 
        {
            integerPart = -integerPart;
            numerator = -numerator;
        }

        setFraction(numerator, denominator);
    }

    // Function to display mixed fractions
    void display() const 
    {
        if (integerPart != 0) 
        {
            cout << integerPart << " ";
        }
        if (getNumerator() != 0) 
        {
            cout << getNumerator() << "/" << getDenominator();
        } 
        else if (integerPart == 0) 
        {
            cout << "0";
        }
    }

    // Output
    friend ostream& operator<<(ostream& out, const iFraction& f) 
    {
        if (f.integerPart != 0) 
        {
            out << f.integerPart << " ";
        }
        if (f.getNumerator() != 0) 
        {
            out << f.getNumerator() << "/" << f.getDenominator();
        } 
        else if (f.integerPart == 0) 
        {
            out << "0";
        }
        return out;
    }

};

// Function to get a valid improper fraction from the user
Fraction getValidImproperFraction(const string& prompt) 
{
    while (true) {
        cout << prompt;
        Fraction f = getFractionFromUser("Enter an improper fraction e.g, 9/4: ");

        if (f.getNumerator() >= f.getDenominator()) {
            return f; // Return the fraction if it is improper
        } else {
            cout << "Please enter a valid improper fraction." << endl;
        }
    }
}

// Function to convert an improper fraction to a mixed fraction
void convertF(const Fraction& f, iFraction& result) 
{
    bool isNegative = f.getNumerator() < 0;
    int whole = abs(f.getNumerator()) / f.getDenominator();
    int numerator = abs(f.getNumerator()) % f.getDenominator();
    int denominator = f.getDenominator();

    if (isNegative) 
    {
        whole = -whole;
        numerator = -numerator;
    }

    result = iFraction(whole, numerator, denominator);
}

// Class representing a complex number with fractions as real and imaginary parts.
class Complex 
{
private:
    Fraction real; // Real part of the complex number.
    Fraction imaginary; // Imaginary part of the complex number.

public:
    // Constructors for the Complex Class
    Complex(const Fraction& r, const Fraction& i) : real(r), imaginary(i) {}
    Complex(int realPart, int imaginaryPart = 0) : real(realPart), imaginary(imaginaryPart) {}

    // Arithmetic Operators
    Complex operator+(const Complex& other) const 
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const 
    {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const 
    {
        // (a + bi)(c + di) = ac + adi + bci - bd = (ac - bd) + (ad + bc)i
        Fraction ac = real * other.real;
        Fraction bd = imaginary * other.imaginary;
        Fraction ad = real * other.imaginary;
        Fraction bc = imaginary * other.real;
        return Complex(ac - bd, ad + bc);
    }

    // Output
    friend ostream& operator<<(ostream& out, const Complex& c) 
    {
        out << c.real;
        if (c.imaginary.getNumerator() >= 0) 
        {
            out << " + "; // Use '+' if imaginary part is non-negative
        } 
        else 
        {
            out << " - "; // Use '-' if imaginary part is negative
        }
        // Output the absolute value of the imaginary part to avoid double negative sign
        out << Fraction(abs(c.imaginary.getNumerator()), c.imaginary.getDenominator()) << "i";
        return out;
    }
};

// Function to get a complex number from the user
Complex getComplexFromUser(const string& prompt) 
{
    cout << prompt << endl;
    Fraction realPart = getFractionFromUser("Enter the real part (e.g, 1/2): ");
    Fraction imaginaryPart = getFractionFromUser("Enter the imaginary part (e.g, 3/4): ");
    return Complex(realPart, imaginaryPart);
}

int main() 
{   // Prompt the user to enter two fractions
    cout << "Please enter fractions in the format: numerator/denominator or a whole number." << endl;

    Fraction f1 = getFractionFromUser("Enter the first fraction or whole number: ");
    Fraction f2 = getFractionFromUser("Enter the second fraction or whole number: ");

    // Display the entered fractions and their arithmetic operations
    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;
    cout << "f1 + f2: " << f1 + f2 << endl;
    cout << "f1 - f2: " << f1 - f2 << endl;
    cout << "f1 * f2: " << f1 * f2 << endl;
    cout << "f1 / f2: " << f1 / f2 << endl;

    // Prompt the user to enter a valid decimal number
    cout << "Enter a decimal number to convert it into a fraction." << endl;

    double decimalNumber = getDecimalFromUser("Enter a decimal number: ");
    Fraction fraction = Fraction::fromDecimal(decimalNumber);

    cout << "The fraction equivalent of " << decimalNumber << " is: " << fraction << endl;

    // Prompt the user to enter a valid improper fraction
    Fraction improperFraction = getValidImproperFraction("Enter your fraction: ");

    // Convert the entered improper fraction to a mixed fraction
    iFraction mixedFraction;
    convertF(improperFraction, mixedFraction);

    // Display the mixed fraction
    cout << "Mixed Fraction: ";
    mixedFraction.display();
    cout << endl;

    // Prompt the user to enter two complex numbers
    Complex c1 = getComplexFromUser("Enter the first complex number:");
    Complex c2 = getComplexFromUser("Enter the second complex number:");

    // Display the entered complex numbers and their arithmetic operations
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c1 + c2: " << c1 + c2 << endl; 
    cout << "c1 - c2: " << c1 - c2 << endl;  
    cout << "c1 * c2: " << c1 * c2 << endl;  

    return 0;
}