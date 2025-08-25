#include <stdio.h>
#include <stdlib.h>

void find_chimps(int * arr, int n, int h, int * chimp1, int* chimp2);
void binary_search(int * arr, int low, int high, int n,int key, int * elem1, int * elem2);

int main(int argc, char ** argv){
    int chimp1, chimp2;
    int n = atoi(argv[1]);
    int q = atoi(argv[2+n]);
    int * arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        arr[i] = atoi(argv[1+i]);
    }
    for(int i=0; i<q; i++){
        find_chimps(arr, n, atoi(argv[3+n+i]), &chimp1, &chimp2);
        if(chimp1 != -1 && chimp2 != -1) printf("%d %d\n", chimp2, chimp1);
        else if(chimp2 == -1 && chimp1 != -1){
            printf("X %d\n", chimp1);
        }
        else if(chimp2 != -1 && chimp1 == -1){
            printf("%d X\n", chimp2);
        }
    }
    free(arr);
    return 0;
}

void find_chimps(int * arr, int n, int h, int * chimp1, int* chimp2){
    /* chimp 1 is the shortest chimp higher than luchu */
    /* chimp 2 is the tallest chimp shorter than luchu */
    binary_search(arr, 0, n-1, n, h, chimp1, chimp2);
    return;
}

void binary_search(int * arr, int low, int high, int n ,int key, int * elem1, int * elem2){
    int mid = (low+high)/2;
    if(arr[mid] == key){
        *elem1 = mid+1>=n? -1:arr[mid+1];
        *elem2 = mid-1<0? -1:arr[mid-1];
        return;
    }else if(low == high){
        if(mid+1 == n && arr[mid] < key){
            *elem1 = -1;
            *elem2 = arr[mid];
        }else if(mid+1 == n && arr[mid] > key){
            *elem1 = arr[mid];
            *elem2 = arr[mid-1];
        }else if(mid-1<0 && arr[mid] > key){
            *elem1 = arr[mid];
            *elem2 = -1;
        }else if(mid-1 <0 && arr[mid] < key){
            *elem1 = arr[mid+1];
            *elem2 = arr[mid];
        }
        if(arr[mid] > key){
            *elem1 = arr[mid];
            *elem2 = arr[mid-1];
        }else{
            *elem1 = arr[mid+1];
            *elem2 = arr[mid];
        }
        return;
    }
    if(arr[mid]>key){
        binary_search(arr, low, mid-1, n, key, elem1, elem2);
    }else{
        binary_search(arr, mid+1, high, n, key, elem1, elem2);
    }
    return;
}
