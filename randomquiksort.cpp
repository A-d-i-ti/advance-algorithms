#include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;

// Function to partition the array with a random pivot
int partition(int a[], int low, int high) {
    //  Choose a random pivot index between low and high
    int randomIndex = low + rand() % (high - low + 1);

    
    cout << "Pivot chosen: " << a[randomIndex] << " (at index " << randomIndex << ")" << endl;

    swap(a[randomIndex], a[high]);


    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);  // Get the pivot index
        quickSort(a, low, pi - 1);         // Recursively sort left
        quickSort(a, pi + 1, high);        // Recursively sort right
    }
}


int main() {
    srand(time(0)); // Seed the random number generator

    int a[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
