// merge_sort.h
// 
// A C++ implementation of the Merge sort algorithm.
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <math.h>

void MergeSort(int* a, int p, int r);
void Merge(int* a, int p, int q, int r);

void MergeSort(int* a, int p, int r) {
    if (p < r) {
        double q;
        q = floor((p+r)/2);
        MergeSort(a, p, int(q));
        MergeSort(a, int(q)+1, r);
        Merge(a, p, int(q), r);
    }
}

void Merge(int* a, int p, int q, int r) {
    int i, j, n1, n2;
    n1 = q - p + 1;
    n2 = r - q;
    int L[n1+1], R[n2+1];
    for (i = 1; i < n1; i++)
        L[i] = a[p+i-1];
    for (j = 1; j < n2; j++)
        R[j] = a[q+j];
    L[n1+1] = 99;
    R[n2+1] = 99;
    for (int k = 0; k < r; k++) {
        if (L[i] < R[j]) {
            a[k] = L[i];
            i = i + 1;
        } else if (a[k] = R[j]){
            j = j + 1;
        }
    }
}

#endif
