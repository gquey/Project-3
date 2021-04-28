#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;


// Taken from module 6 lecture notes on sorting
int partition(int array[], int low, int high)
{
    // Select the pivot element
    int pivot = array[low];
    int up = low, down = high;
    while (up < down)
    {
        for (int j = up; j < high; j++)
        {
            if (array[up] > pivot)
                break;
            up++;
        }
        for (int j = high; j > low; j--)
        {
            if (array[down] < pivot)
                break;
            down--;
        }
        if (up < down)
            swap(array[up], array[down]);
    }
    swap(array[low], array[down]);
    return down;
}

// Taken from module 6 lecture notes on sorting
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}


// Taken from module 6 lecture notes on sorting
void merge(int arr[], int left, int mid, int right)
{
    // Create X ← arr[left..mid] & Y ← arr[mid+1..right]
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* X = new int[n1];
    int* Y = new int[n2];

    for (int i = 0; i < n1; i++)
        X[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Y[j] = arr[mid + 1 + j];

    // Merge the arrays X and Y into arr
    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (X[i] <= Y[j])
        {
            arr[k] = X[i];
            i++;
        }
        else
        {
            arr[k] = Y[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = X[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = Y[j];
        j++;
        k++;
    }
}



// Taken from module 6 lecture notes on sorting
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // m is the point where the array is divided into two subarrays
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Merge the sorted subarrays
        merge(arr, left, mid, right);
    }
}


 

int main()
{

    /**********************************
    *     1000 Data Points    *
    ***********************************/

    int array1ThouX[1000];
    int array1ThouY[1000];

    for (int i = 0; i < 1000; i++) {

        array1ThouX[i] = rand();

    }

    for (int i = 0; i < 1000; i++) {

        array1ThouY[i] = rand();

    }


    //quickSort
    auto start = chrono::high_resolution_clock::now();

    quickSort(array1ThouX, 0, 999);

    auto end = chrono::high_resolution_clock::now();

    auto quickSort1Thou = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Quick Sort sorting time for 1000 data points : " << quickSort1Thou << endl;

    //merge sort
    start = chrono::high_resolution_clock::now();

    mergeSort(array1ThouY, 0, 999);

    end = chrono::high_resolution_clock::now();

    auto mergeSort1Thou = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Merge Sort sorting time for 1000 data points : " << mergeSort1Thou << endl;

    /**********************************
    *     10000 Data Points    *
    ***********************************/

    int arrayTenThouX[10000];
    int arrayTenThouY[10000];

    for (int i = 0; i < 10000; i++) {

        arrayTenThouX[i] = rand();

    }

    for (int i = 0; i < 10000; i++) {

        arrayTenThouY[i] = rand();

    }

    //Quick sort
    start = chrono::high_resolution_clock::now();

    quickSort(arrayTenThouX, 0, 9999);

    end = chrono::high_resolution_clock::now();

    auto quickSortTenThou = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Quick Sort sorting time for 10000 data points : " << quickSortTenThou << endl;

    //merge sort
    start = chrono::high_resolution_clock::now();

    mergeSort(arrayTenThouY, 0, 9999);

    end = chrono::high_resolution_clock::now();

    auto mergeSortTenThou = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Merge Sort sorting time for 10000 data points : " << mergeSortTenThou << endl;

    /**********************************
    *     100000 Data Points    *
    ***********************************/

    int array1HundredThouX[100000];
    int array1HundredThouY[100000];

    for (int i = 0; i < 100000; i++) {

        array1HundredThouX[i] = rand();

    }

    for (int i = 0; i < 100000; i++) {

        array1HundredThouY[i] = rand();

    }

    //Quick sort
    start = chrono::high_resolution_clock::now();

    quickSort(array1HundredThouX, 0, 99999);

    end = chrono::high_resolution_clock::now();

    auto quickSort1HundredThou = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Quick Sort sorting time for 100000 data points : " << quickSort1HundredThou << endl;

    //merge sort
    start = chrono::high_resolution_clock::now();

    mergeSort(array1HundredThouY, 0, 99999);

    end = chrono::high_resolution_clock::now();

    auto mergeSort1HundredThou = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Merge Sort sorting time for 100000 data points : " << mergeSort1HundredThou << endl;

    
}


