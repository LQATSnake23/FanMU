#include "ShakerSort.h"

// code referenced at https://www.iostream.co/article/bubble-sort-va-shaker-sort-01Si3U

void ShakerSort(int* arr, int n, double& count_compare)
{
    // Declare variables
    int left = 0;
    int right = n - 1;
    int mark = 0; // The element before the most recently sorted element

    // Loop until the array is sorted
    while (++count_compare && left < right)
    {
        // Pass through the array from left to right
        for (int i = left; ++count_compare && i < right; i++)
        {
            // Swap elements if the left one is higher than the right one
            if (++count_compare && arr[i] > arr[i + 1])
            {
                HoanVi(arr[i], arr[i + 1]);
                mark = i;
            }
        }

        // Exclude the sorted elements to the right of the array
        right = mark;

        // Pass through the array from left to right
        for (int j = right; ++count_compare && j > left; j--)
        {
            // Swap elements if the left one is higher than the right one
            if (++count_compare && arr[j] < arr[j - 1])
            {
                HoanVi(arr[j], arr[j - 1]);
                mark = j;
            }
        }

        // Exclude the sorted elements to the left of the array
        left = mark;
    }
}
