#include "HeapSort.h"

void MaxHeapify(int* arr, int n, int i, double& count_compare)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (++count_compare && left < n && ++count_compare && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (++count_compare && right < n && ++count_compare && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        HoanVi(arr[largest], arr[i]);
        MaxHeapify(arr, n, largest, count_compare);
    }
}
void BuildMaxHeap(int* arr, int n, double& count_compare)
{
    for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
    {
        MaxHeapify(arr, n, i, count_compare);
    }
}
void HeapSort(int* arr, int n, double& count_compare)
{
    BuildMaxHeap(arr, n, count_compare);
    for (int i = n - 1; ++count_compare && i >= 0; i--)
    {
        HoanVi(arr[0], arr[i]);
        MaxHeapify(arr, i, 0, count_compare);
    }
}
