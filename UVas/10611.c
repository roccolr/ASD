#include <stdio.h>
#include <stdlib.h>

void find_chimps(int * arr, int n, int h, int * chimp1, int* chimp2);
void binary_search(int * arr, int low, int high, int n,int key, int * elem1, int * elem2);

int main(int argc, char ** argv){
    int chimp1, chimp2;
    int n = atoi(argv[1]);
    int q = atoi(argv[2+n]);
    int * arr = (int*)malloc(n*sizeof(int));
    printf("input: ");
    for(int i=0; i<n; i++){
        arr[i] = atoi(argv[2+i]);
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    if(low>high){
        // failed research
        if (low == n){
            *elem1 = -1;
            *elem2 = arr[high];
        }
        else if (high < 0){
            *elem1 = low;
            *elem2 = -1;
        }
        else{
            *elem1 = arr[low];
            *elem2 = arr[high];
        }
    }
    int mid = (low+high)/2;
    if (arr[mid] > key) binary_search(arr, low, mid-1, n, key, elem1, elem2);
    else if (arr[mid] < key) binary_search(arr, mid+1, high, n, key, elem1, elem2);
    else if (arr[mid]==key && mid+1 == n){
        *elem1 = -1;
        *elem2 = arr[mid-1]; 
    }
    else if (arr[mid]==key && mid-1 < 0){
        *elem1 = arr[mid+1];
        *elem2 = -1;
    }
    else if(arr[mid] == key){
        *elem1 = arr[mid+1];
        *elem2 = arr[mid-1];
    }
}
