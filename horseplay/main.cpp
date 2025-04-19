#include <iostream>
#include <string>
#include <vector>

std::vector<char> letterPositions = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

std::string getInput() {
    std::string position;
    std::cout << "Enter the Knight's position on the chessboard: " << std::flush;
    std::cin >> position;
    return position;
}

// returns a number between 1 and 8, inclusive if found
// else  -1
int convertLetter(char x) {
    for (int i = 0; i < letterPositions.size(); i++) {
        if (x == letterPositions[i]) {
            return i + 1;
        }
    }
    return -1;
}
 
// turn chars like "1" to int versions (like 1)
int parseLetter(char y) {
    return static_cast<int>(y) - static_cast<int>('0');
}


std::vector<std::string> getValidPositions(std::string position) {
    std::vector<std::string> validPositions;
    char x = position[0];
    char y = position[1];

    int h = convertLetter(x);
    int v = parseLetter(y);

    // std::cout << h << " " << v << std::endl;

    
    for (int delta_h : std::vector<int> {2, -2}) {
        for (int delta_v : std::vector<int> {1, -1}) {
            
            if (0 < h + delta_h && h + delta_h < 9) {
                if (0 < v + delta_v && v + delta_v < 9) {
                    // std::cout << letterPositions[h + delta_h - 1] + std::to_string(v + delta_v) << std::endl;
                    validPositions.push_back(letterPositions[h + delta_h - 1] + std::to_string(v + delta_v));
                }
            }

            if (0 < h + delta_v && h + delta_v < 9) {
                if (0 < v + delta_h && v + delta_h < 9) {
                    // std::cout << letterPositions[h + delta_v - 1] + std::to_string(v + delta_h) << std::endl;
                    validPositions.push_back(letterPositions[h + delta_v - 1] + std::to_string(v + delta_h));
                }
            }
        }    
    }


    return validPositions;
}




int main() {
    std::string position = getInput();
    std::vector<std::string> validPositions = getValidPositions(position);
    

    for (int i = 0; i < validPositions.size(); i++) {
        std::cout << validPositions[i] << std::endl;
    }

    return 0;
}