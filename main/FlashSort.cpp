#include "FlashSort.h"
void FlashSort(int* arr, int n, double& count_compare)
{
    int m = 0.45 * n;
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; ++count_compare && i < n; i++)
    {
        if (++count_compare && arr[i] > max)
        {
            max = arr[i];
        }
        if (++count_compare && arr[i] < min)
        {
            min = arr[i];
        }
    }
    if (++count_compare && max == min) return;
    int* count_arr = new int[m];
    for (int i = 0; ++count_compare && i < m; i++)
    {
        count_arr[i] = 0;
    }

    for (int i = 0; ++count_compare && i < n; i++)
    {
        int k = ((m - 1) * (arr[i] - min)) / (max - min);
        count_arr[k]++;
    }
    for (int i = 1; i < m; i++)
    {
        count_arr[i] += count_arr[i - 1];
    }
    int count_move = 0;
    int j = 0;
    while (++count_compare && count_move < n)
    {

        int k = ((m - 1) * (arr[j] - min)) / (max - min);
        while (++count_compare && j >= count_arr[k])
        {
            j++;
            k = ((m - 1) * (arr[j] - min)) / (max - min);
        }
        int flash = arr[j];
        while (++count_compare && j != count_arr[k])
        {
            k = ((m - 1) * (flash - min)) / (max - min);
            --count_arr[k];
            swap(flash, arr[count_arr[k]]);
            count_move++;
        }
    }
    InsertionSort(arr, n, count_compare);
}
