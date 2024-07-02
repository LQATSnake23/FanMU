#include "FlashSort.h"
void FlashSort(int a[], int n, double& count_compare) {
    if (n <= 1) return;
    int m = n * 0.45;
    if (m <= 2) m = 2;
    int* __L = new int[m];
    for (int i = 0; ++count_compare && i < m; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; ++count_compare && i < n; ++i) {
        if (++count_compare && Mx < a[i]) Mx = a[i];
        if (++count_compare && Mn > a[i]) Mn = a[i];
    }
    if (++count_compare && Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; ++count_compare && i < n; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; ++count_compare && i < m; ++i)
        __L[i] += __L[i - 1];
    int count = 0;
    int i = 0;
    while (++count_compare && count < n) {
        int k = getK(a[i]);
        while (++count_compare && i >= __L[k])
            k = getK(a[++i]);
        int z = a[i];
        while (++count_compare && i != __L[k]) {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }
    for (int k = 1; ++count_compare && k < m; ++k) {
        for (int i = __L[k] - 2; ++count_compare && i >= __L[k - 1]; --i)
            if (++count_compare && a[i] > a[i + 1]) {
                int t = a[i], j = i;
                while (++count_compare && t > a[j + 1]) {
                    a[j] = a[j + 1];
                    ++j; 
                }
                a[j] = t;
            }
    }
    delete[] __L;
}