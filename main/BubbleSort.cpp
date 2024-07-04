#include "BubbleSort.h"

void BubbleSort(int* arr, int n, double& count_compare)
{
    // Outer Loop 
    for (int i = 0; ++count_compare && i < n - 1; i++)
    {
        // Inner Loop 
        for (int j = 0; ++count_compare && j < n - 1 - i; j++)
        {
            // If the left element is higher than the right element, swap them
            if (++count_compare && arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}