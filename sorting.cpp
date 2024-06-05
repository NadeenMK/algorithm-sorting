#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;


    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void randomFunction(int arr[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int main()
{
    int n = 100000;
    int *arr = new int[n];
    randomFunction(arr, n);
    int N = n;
    // insertionSort(arr, N);
    heapSort(arr, N);
    // Measure the start time
    auto start = high_resolution_clock::now();


    // insertionSort(arr, N);
    heapSort(arr, N);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

     printArray(arr, N);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    delete[] arr; 

    return 0;
}
