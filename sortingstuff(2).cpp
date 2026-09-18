#include <vector>
#include <iostream>
using namespace std;

bool isSorted(const std::vector<int>& values) {
    for (int i = 1; i < values.size(); i++) {
        if (values[i-1] > values[i]) {
            return false;
        }
    }
    return true; 
}

void bubbleSort(vector<int>& values) {
    for (int i = 0; i < values.size() - 1; i++) {
        
        for (int j = i; j < values.size() - 1; j++) {
            if (values[i] > values[j + 1]) {
                swap(values[i], values[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& values) {
    int smallest;
    
    for (int i = 0; i < values.size() - 1; i++) {
        smallest = i;
        for (int j = i + 1; j < values.size(); j++) {
            if (values[j] < values[smallest]) {
                smallest = j;
            }
        }
        swap(values[smallest], values[i]);
    }
}

void insertionSort(vector<int>& values) {
    for (int i = 1; i < values.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (values[j] < values[j - 1]) {
                swap(values[j], values[j - 1]);
            }
            else {
                break;
            }
        }
    }
}

int partition(vector<int>& values, int low, int high) {
    int pivot = values[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (values[j] < pivot) {
            swap(values[j], values[i]);
            i++;
        }
    }
    swap(values[i], values[high]);
    return i;
}

void quickSort(vector<int>& values, int low, int high) {
    if (low < high) {
        int pivot = partition(values, low, high);
        quickSort(values, low, pivot - 1);
        quickSort(values, pivot + 1, high);
    }
}

int main() {
    vector<int> unsorted = {1, 2, 10, 5, 7, 11, 43, 12, 46, 23 , 87 , 12, 4, 1, 5, 34, 76, 23, 53, 1, 2, 6, 23, 54, 23, 12, 43, 34, 84};
    vector<int> reversed = {90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 8, 6, 4, 2};
    vector<int> sorted = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    vector<vector<int>> test_vectors;

    test_vectors = {unsorted, reversed, sorted};
    cout << boolalpha;

    cout << "Bubble Sort: \n";
    bubbleSort(test_vectors[0]);
    cout << "Unsorted List Test - " << isSorted(test_vectors[0]) << endl;   
    bubbleSort(test_vectors[1]);
    cout << "Reversed List Test - " << isSorted(test_vectors[1]) << endl;
    bubbleSort(test_vectors[2]);
    cout << "Sorted List Test - " << isSorted(test_vectors[2]) << "\n\n";

    test_vectors = {unsorted, reversed, sorted};

    cout << "Insertion Sort: \n";
    insertionSort(test_vectors[0]);
    cout << "Unsorted List Test - " << isSorted(test_vectors[0]) << endl;   
    insertionSort(test_vectors[1]);
    cout << "Reversed List Test - " << isSorted(test_vectors[1]) << endl;
    insertionSort(test_vectors[2]);
    cout << "Sorted List Test - " << isSorted(test_vectors[2]) << "\n\n";

    test_vectors = {unsorted, reversed, sorted};

    cout << "Selection Sort: \n";
    selectionSort(test_vectors[0]);
    cout << "Unsorted List Test - " << isSorted(test_vectors[0]) << endl;   
    selectionSort(test_vectors[1]);
    cout << "Reversed List Test - " << isSorted(test_vectors[1]) << endl;
    selectionSort(test_vectors[2]);
    cout << "Sorted List Test - " << isSorted(test_vectors[2]) << "\n\n";

    test_vectors = {unsorted, reversed, sorted};

    cout << "Quick Sort: \n";
    quickSort(test_vectors[0], 0, test_vectors[0].size());
    cout << "Unsorted List Test - " << isSorted(test_vectors[0]) << endl;   
    quickSort(test_vectors[1], 0, test_vectors[1].size());
    cout << "Reversed List Test - " << isSorted(test_vectors[1]) << endl;
    quickSort(test_vectors[2], 0, test_vectors[2].size());
    cout << "Sorted List Test - " << isSorted(test_vectors[2]) << "\n\n";

    test_vectors = {unsorted, reversed, sorted};

    cout << "Vector Check: \n";
    cout << "Unsorted List Test - " << isSorted(test_vectors[0]) << endl;   
    cout << "Reversed List Test - " << isSorted(test_vectors[1]) << endl;
    cout << "Sorted List Test - " << isSorted(test_vectors[2]) << "\n\n";
}