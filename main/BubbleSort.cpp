#include "BubbleSort.h"

void BubbleSort(int* arr, int n, double& count_compare)
{
    for (int i = 0; ++count_compare && i < n - 1; i++)
    {
        for (int j = 0; ++count_compare && j < n - 1 - i; j++)
        {
            if (++count_compare && arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}