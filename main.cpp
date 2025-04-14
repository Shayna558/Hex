/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: sjmcf
 *
 * Created on April 13, 2025, 1:04 PM
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <cmath>

// Function to convert a hex string to a decimal number
int hex2Dec(const std::string& hexString) {
    // Validate the hex string
    for (char c : hexString) {
        if (!std::isxdigit(c)) { // Check if character is not a hexadecimal digit
            throw std::invalid_argument("Invalid hex string: " + hexString);
        }
    }

    // Convert hex to decimal
    int decimalValue = 0;
    for (size_t i = 0; i < hexString.size(); ++i) {
        char c = hexString[i];
        int hexDigitValue;

        if (std::isdigit(c)) {
            hexDigitValue = c - '0';
        } else {
            hexDigitValue = std::toupper(c) - 'A' + 10; // For A-F/a-f
        }

        decimalValue = decimalValue * 16 + hexDigitValue;
    }

    return decimalValue;
}

int main() {
    try {
        std::string hexInput;
        std::cout << "Enter a hexadecimal number: ";
        std::cin >> hexInput;

        int decimalValue = hex2Dec(hexInput);
        std::cout << "The decimal value of " << hexInput << " is " << decimalValue << std::endl;
    } catch (const std::invalid_argument& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}


