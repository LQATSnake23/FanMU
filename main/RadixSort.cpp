#include "RadixSort.h"

// code referenced at https://www.geeksforgeeks.org/radix-sort/

void CountingSortForRadix(int* arr, int n, int div, double& count_compare)
{
    // Initialize count array and output array
    const int max = 10;
    int* count_arr = new int[max];
    int* result_arr = new int[n];
    for (int i = 0; ++count_compare && i < max; i++)
    {
        count_arr[i] = 0;
    }

    // Sort the array at the digit corresponding to div variable using Counting Sort
    for (int i = 0; ++count_compare && i < n; i++)
    {
        count_arr[(arr[i] / div) % 10] += 1;
    }
    for (int i = 1; ++count_compare && i < max; i++)
    {
        count_arr[i] = count_arr[i] + count_arr[i - 1];
    }
    for (int i = n - 1; ++count_compare && i >= 0; i--)
    {
        result_arr[count_arr[(arr[i] / div) % 10] - 1] = arr[i];
        count_arr[(arr[i] / div) % 10] -= 1;
    }
    for (int i = 0; ++count_compare && i < n; i++)
    {
        arr[i] = result_arr[i];
    }

    // Free up used memory
    delete[]count_arr;
    delete[]result_arr;
}

void RadixSort(int* arr, int n, double& count_compare)
{
    // Find the maximum value
    int max = arr[0];
    for (int i = 1; ++count_compare && i < n; i++)
    {
        if (++count_compare && arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Run the counting sort for each digit of the maximum value
    for (int i = 1; ++count_compare && max / i > 0; i *= 10)
    {
        CountingSortForRadix(arr, n, i, count_compare);
    }
}
