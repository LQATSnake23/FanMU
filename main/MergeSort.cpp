#include "MergeSort.h"

void Merge(int* arr, int left, int mid, int right, double& count_compare)
{
    int* new_arr = new int[right - left + 1];
    int i = 0;
    int point_1 = left;
    int point_2 = mid + 1;
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
    while (++count_compare && point_1 <= mid)
    {
        new_arr[i] = arr[point_1];
        ++i;
        ++point_1;
    }
    while (++count_compare && point_2 <= right)
    {
        new_arr[i] = arr[point_2];
        ++i;
        ++point_2;
    }

    for (int j = 0; ++count_compare && j < right - left + 1; j++)
    {
        arr[left + j] = new_arr[j];
    }
    delete[]new_arr;
}

void MergeSort(int* arr, int left, int right, double& count_compare)
{
    if (++count_compare && left >= right) return;
    else
    {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid, count_compare);
        MergeSort(arr, mid + 1, right, count_compare);
        Merge(arr, left, mid, right, count_compare);
    }
}
