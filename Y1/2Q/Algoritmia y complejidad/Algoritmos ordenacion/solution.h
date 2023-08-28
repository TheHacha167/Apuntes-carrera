#ifndef SOLUTION_H
#define SOLUTION_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], int n);
void selectionSort(int array[], int n);
void insertionSort(int array[], int n);
void mergeSort(int array[], int izquierda, int derecha);
void quickSort(int array[], int bajo, int alto);
void randomizarArarray(int array[], int tamanio);
void merge(int A[], int izquierda, int centro, int derecha);


void merge(int A[], int izquierda, int centro, int derecha) {
    int i, j, k;
    int n1 = centro - izquierda + 1;
    int n2 = derecha - centro;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[izquierda + i];
    for (j = 0; j < n2; j++)
        R[j] = A[centro + 1 + j];

    i = 0;
    j = 0;
    k = izquierda;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int bajo, int alto) {
    int pivot = array[alto];
    int i = (bajo - 1);

    for (int j = bajo; j <= alto - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[alto]);
    return (i + 1);
}

void randomizarArarray(int array[], int tamanio) {
    srand(time(NULL));
    int i;
    for (i = tamanio - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void copiarArray(int original[], int destino[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        destino[i] = original[i];
    }
}

void bubbleSort(int array[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void selectionSort(int A[], int n) {
    int i, j, min_index;

    for (i = 0; i < n - 1; i++) {
        min_index = i;

        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }

        swap(&A[i], &A[min_index]);
    }
}

void insertionSort(int array[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void mergeSort(int A[], int izquierda, int derecha) {
    if (izquierda < derecha) {
        int centro = (izquierda + derecha) / 2;

        mergeSort(A, izquierda, centro);
        mergeSort(A, centro + 1, derecha);

        merge(A, izquierda, centro, derecha);
    }
}

void quickSort(int array[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = partition(array, bajo, alto);

        quickSort(array, bajo, pi - 1);
        quickSort(array, pi + 1, alto);
    }
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}



#endif