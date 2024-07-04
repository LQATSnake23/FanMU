#include "InsertionSort.h"

void InsertionSort(int* arr, int n, double& count_compare)
{
    // For each element from the second element
    for (int i = 1; ++count_compare && i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Compare the selected element with the previous elements to find the correct position
        while (++count_compare && j >= 0 && ++count_compare && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Move back the compared element to make place
            j--;
        }

        // Move the selected element to the correct position
        arr[j + 1] = key;
    }
}
