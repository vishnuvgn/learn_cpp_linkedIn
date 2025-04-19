#include <iostream>
#include <string>

int main() {
    
    // cool approach

    int n;
    std::cout << "Enter a number: " << std::flush;
    std::cin >> n;
    std::cout << std::endl;
    bool m3, m5;

    for (int i = 1; i < n+1; i++) {
        m3 = (i % 3 == 0);
        m5 = (i % 5 == 0);

        if (!m3 && !m5) {
            std::cout << i;
        }
        else{
            if (m3) { 
                std::cout << "Fizz";
            }
            if (m5) {
                std::cout << "Buzz";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}