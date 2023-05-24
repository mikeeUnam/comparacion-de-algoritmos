#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int n = 100;
    int arr[n];
    
    srand(time(0));  // seed for random numbers
    
    // generate random numbers between 1 and 100
    for (int i=0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
    
    cout << "Numeros generados: "<<endl;
    printArray(arr, n);
    
    // measure execution time
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    insertionSort(arr, n);
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    cout << "Ordenados: "<<endl;
    printArray(arr, n);
    cout<<endl;
    cout << "Tiempo de ejecucion: " << cpu_time_used << " seconds." << endl;
    
    return 0;
}

