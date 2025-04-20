#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

std::string get_input() {

    std::string ip_address;

    std::cout << "IP Address: " << std::flush;
    std::getline(std::cin, ip_address);

    return ip_address;
}



std::vector<std::string> string_split(std::string str, std::string delimiter) {

    std::vector<std::string> parts;
    
    while (str.find(delimiter) != std::string::npos) {
        
        int index = str.find(delimiter);

        std::string part = str.substr(0, index);
        parts.push_back(part);
        str.erase(0, index + 1);
    }
    parts.push_back(str);

    return parts;

}

int parse_int(std::string number) {
    std::unordered_set<char> numbers = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int value = 0;

    for (char i : number) {
        if (numbers.find(i) == numbers.end()) {
            return -1;
        }
        else {
            value *= 10;
            value += static_cast<int>(i) - static_cast<int>('0');
        }
    }

    return value;
}



bool validate(std::string ip_address) {

    std::vector<std::string> parts = string_split(ip_address, ".");

    if (parts.size() != 4) {
        return false;
    }

    for (auto& part : parts) {
        int value = parse_int(part);
        if (value < 0 || value > 255) {
            return false;
        }
    }
    
    return true;
}


int main() {

    std::string ip_address = get_input();
    bool is_valid = validate(ip_address);

    if (is_valid == 0) {
        std::cout << "not valid" << std::endl;
    }
    else {
        std::cout << "valid" << std::endl;
    }

    return 0;

}