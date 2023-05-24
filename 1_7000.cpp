#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main()
{
    int n = 7000; // number of elements
    int arr[n];

    // generate random numbers between 1 and 100
    srand(time(0)); // seed the random number generator
    
    cout<<"Numeros random : "<<endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    // print the unsorted array
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // sort the array using Bubble sort and measure the execution time
    clock_t start, end;
    start = clock();
    bubbleSort(arr, n);
    end = clock();
    double executionTime = double(end - start) / double(CLOCKS_PER_SEC);

    // print the sorted array and the execution time
    cout << "Ordenados: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Tiempo de ejecución: " << executionTime << " seconds" << endl;

    return 0;
}

