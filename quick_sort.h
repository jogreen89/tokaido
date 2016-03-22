// quick_sort.h
//
// A C++ implementation of Quicksort using 
// the last index as the pivot.
// (c) 2016 zubernetes
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stdio.h>

void Exchange(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int *a, int p, int r) {
	int x = a[r];
	int i = p - 1;

	for (int j = p; j <= r - 1; j++) {
		if (a[j] <= x) {
			i++;
			Exchange(&a[i], &a[j]);
		}
	}
	Exchange(&a[i+1], &a[r]);
	return (i+1);
}

void QuickSort(int* a, int p, int r) {
	if (p < r) {
		int q = Partition(a, p, r); 
		QuickSort(a, p, q - 1);
		QuickSort(a, p + 1, r);
	}
}

#endif
