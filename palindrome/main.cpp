#include <iostream>
#include <string>
#include <cctype>


int main() {
    
    std::string str;
    std::cout << "Input: " << std::flush;
    std::getline(std::cin, str);
    
    int l = 0, r = str.size() - 1;

    while (l < r) {

        if (std::tolower(str[l]) == std::tolower(str[r])) {
            l++;
            r--;
            continue;
        }

        else {
            std::cout << "Result: Not a palindrome" << std::endl;            
            return 0;
        }
    }

    std::cout << "Result: Is a palindrome" << std::endl;
    return 0;
}