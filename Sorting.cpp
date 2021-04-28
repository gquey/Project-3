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


int getMax(int arr[], int length) {

    int max = 0;

    for (int i = 0; i <= length;  i++) {

        int number = arr[i];

        if (number > max) {

            max = number;

        }

    }

    return max;

}



void countingSort(int arr[], int length) {

    int max = getMax(arr, length);

    int* output = new int[length + 1];
    int* counts = new int[max + 1];

    

    for (int i = 0; i <= max; i++) {

        counts[i] = 0;


    }

    for (int i = 0; i < length; i++) {

        counts[arr[i]]++;

    }

    for (int i = 1; i <= max; i++) {

        counts[i] = counts[i] + counts[i - 1];

    }

    for (int i = length ; i > 0; i--) {

        output[counts[arr[i]] - 1] = arr[i];
        counts[arr[i]]--;

    }

    for (int i = 0; i < length; i++) {
        arr[i] = output[i];
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

    cout << "Quick Sort sorting time for 1000 data points: " << quickSort1Thou << endl;

    //Counting sort
    start = chrono::high_resolution_clock::now();

    countingSort(array1ThouY, 999);

    end = chrono::high_resolution_clock::now();

    auto countSort1Thou = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Counting Sort sorting time for 1000 data points: " << countSort1Thou << endl;

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

    cout << "Quick Sort sorting time for 10000 data points: " << quickSortTenThou << endl;

    //Counting sort
    start = chrono::high_resolution_clock::now();

    countingSort(arrayTenThouY, 9999);

    end = chrono::high_resolution_clock::now();

    auto countSortTenThou = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Counting Sort sorting time for 10000 data points: " << countSortTenThou << endl;

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

    cout << "Quick Sort sorting time for 100000 data points: " << quickSort1HundredThou << endl;

    //Counting sort
    start = chrono::high_resolution_clock::now();

    countingSort(array1HundredThouY, 99999);

    end = chrono::high_resolution_clock::now();

    auto countSort1HundredThou = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Counting Sort sorting time for 100000 data points: " << countSort1HundredThou << endl;

    
}


