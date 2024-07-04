#include "QuickSort.h"

// Partition an array using a pivot, then return the pivot
int Partition(int* arr, int left, int right, double& count_compare)
{
    // Choose the last element as the pivot
    int p = right;

    // Find the correct position for the pivot in the array
    right = right - 1;
    while (++count_compare && left <= right)
    {
        while (++count_compare && arr[left] < arr[p] && ++count_compare && left <= right)
        {
            left++;
        }
        while (++count_compare && arr[right] > arr[p] && ++count_compare && right >= left)
        {
            right--;
        }
        if (++count_compare && left <= right)
        {
            HoanVi(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    // Move the pivot to the correct position
    HoanVi(arr[left], arr[p]);

    // Return the pivot index
    return left;
}

void QuickSort(int* arr, int left, int right, double& count_compare)
{
    if (left < right)
    {
        // Partition the current array using a pivot
        int p = Partition(arr, left, right, count_compare);

        // Sort the sub-array to the left of the pivot using Quick Sort
        QuickSort(arr, left, p - 1, count_compare);

        // Sort the sub-array to the right of the pivot using Quick Sort
        QuickSort(arr, p + 1, right, count_compare);
    }
}
