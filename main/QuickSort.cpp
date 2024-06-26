#include "QuickSort.h"

int Partition(int* arr, int left, int right, int& count_compare)
{
    int p = right;
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
    HoanVi(arr[left], arr[p]);
    return left;
}

void QuickSort(int* arr, int left, int right, int& count_compare)
{
    if (left < right)
    {
        int p = Partition(arr, left, right, count_compare);
        QuickSort(arr, left, p - 1, count_compare);
        QuickSort(arr, p + 1, right, count_compare);
    }
}
