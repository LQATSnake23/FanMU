#include "ShellSort.h"

void ShellSort(int* arr, int n, int& count_compare)
{
    int h = 1;
    while (++count_compare && h <= n / 3)
    {
        h = h * 3 + 1;
    }
    while (++count_compare && h > 0)
    {
        for (int i = h; ++count_compare && i < n; i++)
        {
            int key = arr[i];
            int j = i;
            while (++count_compare && arr[j - h] > key && ++count_compare && j > h - 1)
            {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = key;
        }
        h = (h - 1) / 3;
    }
}
