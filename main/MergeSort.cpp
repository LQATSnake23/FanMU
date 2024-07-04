#include "MergeSort.h"

void Merge(int* arr, int left, int mid, int right, double& count_compare)
{
    // Initialize secondary array and variables
    int* new_arr = new int[right - left + 1];
    int i = 0;
    int point_1 = left;
    int point_2 = mid + 1;

    // Sort the elements of the left and right sub-array into the secondary array
    while (++count_compare && point_1 <= mid && ++count_compare && point_2 <= right)
    {
        if (++count_compare && arr[point_1] <= arr[point_2])
        {
            new_arr[i] = arr[point_1];
            ++i;
            ++point_1;
        }
        else
        {
            new_arr[i] = arr[point_2];
            ++i;
            ++point_2;
        }
    }

    // Sort the remaining elements of the left sub-array into the secondary array
    while (++count_compare && point_1 <= mid)
    {
        new_arr[i] = arr[point_1];
        ++i;
        ++point_1;
    }

    // Sort the remaining elements of the right sub-array into the secondary array
    while (++count_compare && point_2 <= right)
    {
        new_arr[i] = arr[point_2];
        ++i;
        ++point_2;
    }

    // Returning the values of the secondary array to the original array
    for (int j = 0; ++count_compare && j < right - left + 1; j++)
    {
        arr[left + j] = new_arr[j];
    }

    // Delete the secondary array
    delete[]new_arr;
}

void MergeSort(int* arr, int left, int right, double& count_compare)
{
    // Stop if the array can no longer be divided
    if (++count_compare && left >= right) return;

    else
    {
        int mid = (left + right) / 2;

        // Call MergeSort for the left sub-array
        MergeSort(arr, left, mid, count_compare);

        // Call MergeSort for the right sub-array
        MergeSort(arr, mid + 1, right, count_compare);

        // Merge the two divided array into one sorted array
        Merge(arr, left, mid, right, count_compare);
    }
}
