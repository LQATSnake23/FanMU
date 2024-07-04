#include "ShellSort.h"

// code referenced at https://www.geeksforgeeks.org/shellsort/

void ShellSort(int* arr, int n, double& count_compare)
{
    // Calculate the gap size
    for (int gap = n / 2; ++count_compare && gap > 0; gap /= 2)
    {
        // Divide the array into sub-lists
        for (int i = gap; ++count_compare && i < n; i += 1)
        {
            // Sort each sub-list using Insertion Sort
            int temp = arr[i];
            int j;
            for (j = i; (++count_compare && j >= gap) && (++count_compare && arr[j - gap] > temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
