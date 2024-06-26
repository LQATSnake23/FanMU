#include "ShakerSort.h"

void ShakerSort(int* arr, int n, int& count_compare)
{
    int left = 0;
    int right = n - 1;
    int mark = 0;
    while (++count_compare && left < right)
    {
        for (int i = left; ++count_compare && i < right; i++)
        {
            if (++count_compare && arr[i] > arr[i + 1])
            {
                HoanVi(arr[i], arr[i + 1]);
                mark = i;
            }
        }
        right = mark;
        for (int j = right; ++count_compare && j > left; j--)
        {
            if (++count_compare && arr[j] < arr[j - 1])
            {
                HoanVi(arr[j], arr[j - 1]);
                mark = j;
            }
        }
        left = mark;
    }
}
