#include "CountingSort.h"
#include "CountingSort.h"

void CountingSort(int* arr, int n, int& count_compare)
{
    int max = arr[0];
    for (int i = 1; ++count_compare && i < n; i++)
    {
        if (++count_compare && arr[i] > max)
        {
            max = arr[i];
        }
    }
    int* count_arr = new int[max + 1];
    int* result_arr = new int[n];
    for (int i = 0; ++count_compare && i <= max; i++)
    {
        count_arr[i] = 0;
    }
    for (int i = 0; ++count_compare && i < n; i++)
    {
        count_arr[arr[i]] += 1;
    }
    for (int i = 1; ++count_compare && i <= max; i++)
    {
        count_arr[i] = count_arr[i] + count_arr[i - 1];
    }
    for (int i = n - 1; ++count_compare && i >= 0; i--)
    {
        result_arr[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]] -= 1;
    }
    for (int i = 0; ++count_compare && i < n; i++)
    {
        arr[i] = result_arr[i];
    }
    delete[]count_arr;
    delete[]result_arr;
}
