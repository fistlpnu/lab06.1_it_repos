#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

void generateArray(int arr[], int size, int minVal, int maxVal) {
    for (int i = 0; i < size; ++i) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void processArray(int arr[], int size, int& sum, int& count) {
    sum = 0;
    count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0 || arr[i] % 2 != 0) {
            sum += arr[i];
            count++;
            arr[i] = 0;
        }
    }
}

int main() {
    srand(time(0));

    const int SIZE = 27;
    const int MIN_VAL = -35;
    const int MAX_VAL = 25;

    int arr[SIZE];

    generateArray(arr, SIZE, MIN_VAL, MAX_VAL);

    cout << "Initial array: " << endl;
    printArray(arr, SIZE);

    int sum = 0, count = 0;
    processArray(arr, SIZE, sum, count);

    cout << "Number of items that meet the criterion: " << count << endl;
    cout << "The sum of these elements: " << sum << endl;

    cout << "Modified array: " << endl;
    printArray(arr, SIZE);

    return 0;
}
