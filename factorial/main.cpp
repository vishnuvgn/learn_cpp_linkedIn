#include <vector>
#include <iostream>

// terribly written, unoptimized code
// int factorial(int n) {
//     if (n == 0) {
//         return 1;
//     }

//     return n * factorial(n - 1);
// }


// int main() {

//     std::vector<int> seq;

//     int n;

//     std::cout << "n: " << std::flush;
//     std::cin >> n;

//     for (int i = 0; i < n+1; i++) {
//         seq.push_back(factorial(i));
//     }

//     for (int i = 0; i < seq.size(); i++) {
//         std::cout << seq[i] << std::endl;
//     }

//     return 0;
// }

// dynamic programming (memoized)

int main() {
    
    int n;

    std::cout << "n: " << std::flush;
    std::cin >> n;

    int seq[n+1];
    seq[0] = 1;
    for (int i = 1; i < n+1; i++) {
        seq[i] = i * seq[i-1];
    }   

    for (int j = 0; j < n+1; j++) {
        std::cout << seq[j] << std::endl;
    }

}