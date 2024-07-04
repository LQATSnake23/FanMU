#include "SelectionSort.h"

void SelectionSort(int* arr, int n, double& count_compare)
{
    // For each element
    for (int i = 0; ++count_compare && i < n - 1; i++)
    {
        // Search for the minimum element from the selected element to the right
        int minIdx = i;
        for (int j = i + 1; ++count_compare && j < n; j++)
        {
            if (++count_compare && arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        
        // Swap the selected element and the minimum element
        HoanVi(arr[i], arr[minIdx]);
    }
}
