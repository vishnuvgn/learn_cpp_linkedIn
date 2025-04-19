#include <iostream>
#include <climits>


void bubblesort(int* arr, int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionsort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        int min = INT_MAX;
        int min_index = -1;
        for (int j = i; j < size; j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[min_index] = temp;
    }
}






int main() {
    
    int arr[] = {2};

    int size = sizeof(arr) / sizeof(arr[0]); // length of array


    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }

    std::cout << "=======" << std::endl;

    bubblesort(arr, size);
    // selectionsort(arr, size);

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
    
 


    return 0;
}