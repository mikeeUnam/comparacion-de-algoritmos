#include <bits/stdc++.h>
using namespace std;

// Heapify the subtree rooted at index i.
void heapify(int arr[], int n, int i) {
    int largest = i;   // Initialize largest as root
    int l = 2*i + 1;   // Left child
    int r = 2*i + 2;   // Right child

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n = 20000;
    int arr[n];
cout<<"Numeros genereados: "<<endl;
    // Generate 100 random integers between 1 and 100
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
        cout<<arr[i]<<" ";
    }
cout<<endl;
    // Measure execution time
    clock_t start = clock();

    // Perform Heap Sort
    heapSort(arr, n);

    // Measure execution time
    clock_t end = clock();

    // Calculate the elapsed time in seconds
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    // Print the sorted array and the elapsed time
    cout << "Ordenados: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Tiempo de ejecución: " << elapsed_time << " seconds" << endl;

    return 0;
    
	}

