#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>


std::string WORDS[] = {
    "cat", "dog", "sun", "hat", "car", "pen", "box", "cup", "bat", "rat"
};


std::string to_lowercase(std::string input) {
    std::string result = "";
    for (char i : input) {
        if (static_cast<int>(i) < 97 || static_cast<int>(i) > 122) {
            result += (char(i - 32));
        }
        else {
            result += i;
        }
    }
    return result;
}

void generate_word() {
    srand(time(0));
    int random_time_wait = rand() % 6 + 4;

    std::string random_word = WORDS[rand() % 10];

    std::string input;
    sleep(random_time_wait);
    std::cout << random_word << ": " << std::flush;
    
    time_t start = time(0);
    getline(std::cin, input);
    time_t end = time(0);
    
    std::string lower_input = to_lowercase(input);


    if (lower_input == random_word) {
        std::cout << "Time: " << end - start << std::endl;
        if (end - start <= 2) {
            std::cout << "Correct" << std::endl;
        }
        else {
            std::cout << "Too Slow" << std::endl;
        }
    }
    else {
        std::cout << "Incorrect" << std::endl;
    }


}


int main() {

    while(true) {
        generate_word();
    }
}