// Kristoffer Carlino
// C++ 300 
// Dr. Robert Flowers
// Assignment: Ch07Exercise04.cpp
// Ch07Exercise04.cpp
// Prompts for a string, removes all vowels using substr, and prints the result.

#include <iostream>
#include <string>
#include <cctype>

bool isVowel(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    char lower = static_cast<char>(std::tolower(uc));
    // AEIOU only; 'y' is not treated as a vowel to match the example ("There" -> "Thr")
    return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
}

std::string removeVowels(const std::string& s) {
    std::string out;
    out.reserve(s.size());
    for (std::size_t i = 0; i < s.size(); ++i) {
        if (!isVowel(s[i])) {
            // Use substr to append exactly this one non-vowel character
            out += s.substr(i, 1);   // <-- explicit use of substr per instructions
        }
        // else skip vowels
    }
    return out;
}

int main() {
    std::cout << "Enter a string: ";
    std::string input;
    std::getline(std::cin, input);

    std::string result = removeVowels(input);
    std::cout << "After removing vowels: " << result << '\n';
    return 0;
}
