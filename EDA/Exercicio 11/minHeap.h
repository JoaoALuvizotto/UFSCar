#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} MinHeap;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->arr = (int*) malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

void insertMinHeap(MinHeap *minHeap, int key) {
    if (minHeap->size == minHeap->capacity) {
        printf("Overflow: Could not insert key\n");
        return;
    }

    // Primeiro, insere no final da heap.
    int i = minHeap->size;
    minHeap->arr[i] = key;
    minHeap->size++;

    // Depois, realiza o heapify bottom-up.
    while (i != 0 && minHeap->arr[parent(i)] > minHeap->arr[i]) {
        swap(&minHeap->arr[i], &minHeap->arr[parent(i)]);
        i = parent(i);
    }
}

void minHeapify(MinHeap *minHeap, int i) {
    int l = leftChild(i);
    int r = rightChild(i);
    int smallest = i;

    if (l < minHeap->size && minHeap->arr[l] < minHeap->arr[smallest])
        smallest = l;
    if (r < minHeap->size && minHeap->arr[r] < minHeap->arr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(&minHeap->arr[i], &minHeap->arr[smallest]);
        minHeapify(minHeap, smallest);
    }
}

int extractMin(MinHeap *minHeap) {
    if (minHeap->size <= 0)
        return -1; 
    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->arr[0];
    }

    int root = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

void printHeap(MinHeap *minHeap) {
    for (int i = 0; i < minHeap->size; i++) {
        printf("%d ", minHeap->arr[i]);
    }
    printf("\n");
}

#endif
