// heap_sort.cpp
// 
// A C++ implementation of the heapsort algorithm.

#include <iostream>
#define MAX_SIZE 10

int* BuildArray(int size);
void BuildMaxHeap(int* A, int size);
void DisplayArray(int* A, int size);
void HeapSort(int* A, int size);
void BuildMaxHeap(int* A);
void MaxHeapify(int* A, int i, int size);
void exchange(int* A, int* B);

int main() {
    int* A = BuildArray(MAX_SIZE);
    DisplayArray(A, MAX_SIZE);
    return 0;
}
int* BuildArray(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = i;
    return &array[0];
}
void BuildMaxHeap(int* A, int size) {
}
void DisplayArray(int* A, int size) {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << *A;
        if (i != size - 1)
            std::cout << ", ";
        A++;
    }
    std::cout << "]";
}
void exchange(int* A, int* B) {
    int temp;
    temp = *A;
    *A = *B;
    *B = temp;
}
void MaxHeapify(int* A, int i, int size) {
    int largest;
    int left = A[2*i];
    int right = A[2*i+1];
    if (left <= size && left > right)
        largest = left;
    else
        largest = right;
    if (right <= size && right > largest)
        largest = right;
    if (largest != i) {
        exchange(&A[i], &A[largest]);
        MaxHeapify(&A[0], i, size);
    }
}


