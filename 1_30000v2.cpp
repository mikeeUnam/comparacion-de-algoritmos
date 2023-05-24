#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
 
void countingSort(int arr[], int n) {
    int output[n];
    int count[101] = {0};
    for (int i = 0; i < n; ++i) {
        ++count[arr[i]];
    }
    for (int i = 1; i <= 100; ++i) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}
 
int main() {
    int n = 30000;
    int arr[n];
   	 cout<<"Numeros generados: "<<endl;
    // Generate n random numbers between 1 and 100
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100 + 1;
        cout<<arr[i]<<" ";
    }
   cout<<endl;
    // Measure the execution time of countingSort
    clock_t start = clock();
    countingSort(arr, n);
    clock_t end = clock();
    // Output the sorted array and the execution time
    cout<<"Numeros ordenados: "<<endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Execution time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
