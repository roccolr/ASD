#include <stdio.h>
#include <stdlib.h>

int binary_search(int *, int, int, int);

int main(int argc, char** argv){
    int y = atoi(argv[1]);
    int l = atoi(argv[2]);
    int start, stop, n;
    int * years = (int*)malloc(l*sizeof(int));
    for(int i=0; i<l; i++){
        years[i] = atoi(argv[i+3]);
    }

    n=0; start =0; stop = 0;
    for(int i=0; i<l; i++){
        int j = binary_search(years, i, l-1, years[i]+y-1);
        int count = j-i+1;
        if(count > n){
            start = i;
            stop = j;
            n = count;
        }
    }
    // O(nlg(n))

    printf("input:\t");
    for(int i=0; i<l; i++){
        printf("%d ", years[i]);
    }
    printf("\noutput: %d, %d, %d", n, years[start], years[stop]);
}

int binary_search(int * arr, int low, int high, int key){
    if(low>high) return high;
    int mid = (int)((low+high)/2);
    if(arr[mid]>key) return binary_search(arr, low, mid-1,key);
    else return binary_search(arr, mid+1, high, key);
}


