#include <stdio.h>
#include <math.h>
#include <limits.h>

void swap(int *a, int * b){
    int temp = *a;
    *a = *b; 
    *b = temp;
}

int partition(int* arr, int p, int r){
    int x = arr[r], i = p-1;
    for(int j=p; j<r-1; j++){
        if(arr[j] < x){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[r], &arr[i+1]);
    return i+1;
}

void quicksort(int * arr, int p, int r){
    if(p<r){
        int q = partition(arr, p, r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }
}

void ordina_righe(int** matrix, int n, int m){
    for(int i=0; i<n; i++){
        quicksort(matrix[i], 0, m);
    }
}

int cerca_vicino();