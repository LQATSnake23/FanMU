#include "SelectionSort.h"
void SelectionSort(int* arr, int n, int& count_compare)
{

    for (int i = 0; ++count_compare && i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; ++count_compare && j < n; j++)
        {
            if (++count_compare && arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        HoanVi(arr[i], arr[minIdx]);
    }
}
