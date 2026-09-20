#include <vector>
#include <iostream>
#include <functional>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

void algorithmTest(vector<vector<int>> lists, std::function<void(vector<int>&)> sortAlgorithm) {
    string listNames[3] = {"Unsorted List Test - ", "Reversed List Test - ", "Sorted List Test - "};
    double sortTime = 0.0;
    
    for (int i = 0; i < 3; i++) {
        auto start = steady_clock::now();
        (sortAlgorithm)(lists[i]);
        auto end = steady_clock::now();
        
        sortTime = duration<double, milli>(end - start).count();
        cout << listNames[i] << isSorted(lists[0]) << " in time: " << sortTime << " milliseconds \n";
    }
}

void algorithmTestButForSpecifcallyQuickSort(vector<vector<int>> lists, std::function<void(vector<int>&, int, int)> sortAlgorithm) {
    string listNames[3] = {"Unsorted List Test - ", "Reversed List Test - ", "Sorted List Test - "};
    double sortTime = 0.0;
    
    for (int i = 0; i < 3; i++) {
        auto start = steady_clock::now();
        (sortAlgorithm)(lists[i], 0, lists[i].size());
        auto end = steady_clock::now();
        
        sortTime = duration<double, milli>(end - start).count();
        cout << listNames[i] << isSorted(lists[0]) << " in time: " << sortTime << " milliseconds \n";
    }
}

int main() {
    vector<int> unsorted = {41, 21, 6, 16, 42, 85, 94, 50, 5, 11, 80, 79, 1, 47, 65, 9, 23, 69, 
    87, 74, 34, 68, 46, 86, 20, 15, 72, 49, 48, 12, 54, 29, 75, 99, 24, 37, 77, 71, 44, 36, 82, 
    73, 45, 63, 3, 33, 13, 27, 96};
    vector<int> reversed;
    vector<int> sorted;
    
    for (int i = 90; i > 0; i--) {
        reversed.push_back(i);
    }
    for (int i = 0; i < 110; i++) {
        sorted.push_back(i);
    }
    
    

    vector<vector<int>> test_vectors;

    test_vectors = {unsorted, reversed, sorted};
    cout << boolalpha;

    cout << "Bubble Sort Test: \n";
    algorithmTest(test_vectors, bubbleSort);
    cout << "\nSelection Sort Test: \n";
    algorithmTest(test_vectors, selectionSort);
    cout << "\nInsertion Sort Test: \n";
    algorithmTest(test_vectors, insertionSort);
    cout << "\nQuick Sort Test: \n";
    algorithmTestButForSpecifcallyQuickSort(test_vectors, quickSort);
}
