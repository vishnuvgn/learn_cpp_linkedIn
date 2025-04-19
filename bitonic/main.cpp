#include <vector>
#include <iostream>

// O(n^2)

bool isBitonic(const std::vector<int> seq, int start, int length) {
    bool hasPeaked = false;
    for (int i = 0; i < length - 1; i++) {
        int index = (start + i) % length;

        if (!hasPeaked) {
            if (seq[index] > seq[index + 1]) {
                hasPeaked = true;
            }
        }

        else {
            if (seq[index] < seq[index + 1]) {
                return false;
            }
        }

    }
    return true;
}


int main() {
    std::vector<int> sequence = {1, 3, 1, 3};

    int length = sequence.size();
    
    bool valid = false;

    for (int start = 0; start < length; start++) {
        valid = isBitonic(sequence, start, length);

        if (valid) {
            std::cout << "True" << std::endl;
            return 0;
        }
    }

    std::cout << "False" << std::endl;
    return 0;
}