#include "InsertionSort.h"

void InsertionSort(int* arr, int n, int& count_compare)
{

    for (int i = 1; ++count_compare && i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (++count_compare && j >= 0 && ++count_compare && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
