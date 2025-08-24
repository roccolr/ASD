#include "sorting.h"

int partition(int * arr, int p, int r){
    /* the array starts at 0 */
    int x = arr[r];
    int i = p-1;
    for(int j=p; j<=r-1; j++){
        if (arr[j] <= x){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i+1; 
}

void quicksort(int *arr, int p, int r){
    if (p<r){
        int q = partition(arr, p, r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }
}