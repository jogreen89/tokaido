// timing.cpp
//
// Timing selection_sort.cpp && insertion_sort &&
// quicksort && randomized quicksort algorithms. 
// (c) 2016 zubernetes
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <iostream>

void selection_sort(int *a, int n) {
    int i, j, m, t;
    for (i = 0; i < n; i++) {
        for (j = i, m = i; j < n; j++) {
            if (a[j] < a[m]) {
                m = j;
            }
        }
        // Swap
        t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}

void insertion_sort(int *a, int n) {
    int i, j, len = n - 1, key;
    for (i = 2; i < len; i++ ) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int* buildDataSet(int size) {
    int* data_set = new int[size];
    int num;
    srand (time(NULL));
    for (int i = 0; i < size; i++) {
        num = rand() % 1000 + 1;       /* random number between 0..1000 */
        data_set[i] = num;
    }
    return &data_set[0];
}

void Exchange(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Random_Partition(int *a, int p, int r) {
	srand(time(NULL));
	int index = p + rand() % (r - p + 1);
	int q = a[index];
	Exchange(a[index], a[r]);
	index = r;
	int i = p - 1;
	
	for (int j = p; j <= r - 1; j++) {
		if (a[j] <= q) {
			i++;
			Exchange(a[i], a[j]);
		}
	}
	Exchange(a[i+1], a[index]);
	return (i+1);	
}

int Partition(int *a, int p, int r) {
	int x = a[r];
	int i = (p - 1);

	for (int j = p; j <= r - 1; j++) {
		if (a[j] <= x) {
			i++;
			Exchange(&a[i], &a[j]);
		}
	}
	Exchange(&a[i+1], &a[r]);
	return (i+1);
}

void QuickSort(int *a, int p, int r) {
	if (p < r) {
		int q = Partition(a, p, r); 
		QuickSort(a, p, q - 1);
		QuickSort(a, p + 1, r);
	}
}

void Randomized_QuickSort(int *a, int p, int r) {
	if (p < r) {
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, p + 1, r);
	}
}

int main(int argc, char *argv[]) {
    // 100, 1000, 3000, 5000, 10000
    int *a;
    int size = 50;
    a = buildDataSet(size);

    // define the time struct
    struct timeval start, stop;

    // initialize the time struct
    start.tv_usec = 0; stop.tv_usec = 0;
    // call gettimeofday() before the function call
    gettimeofday(&start, NULL);

    /* call insertion sort */
    // insertion_sort(a, size);

    /* call selection sort */
    // selection_sort(a, size);

	/* call quicksort (non-random) */
	// QuickSort(a, 0, size); 

	/* call quicksort (random) */
	// Randomized_QuickSort(a, 0, size);

    // call gettimeofday() after the function call
    gettimeofday(&stop, NULL);

    // calculate the difference
    std::cout << ((stop.tv_sec - start.tv_sec) * 1000000 +
                  stop.tv_usec - start.tv_usec) << std::endl;
    return 0;
}
