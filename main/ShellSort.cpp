#include "ShellSort.h"

void ShellSort(int* arr, int n, double& count_compare)
{
    for (int gap = n / 2; ++count_compare && gap > 0; gap /= 2)
    {
        for (int i = gap; ++count_compare && i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; (++count_compare && j >= gap) && (++count_compare && arr[j - gap] > temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
