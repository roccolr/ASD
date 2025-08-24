#include <stdio.h>
#include <stdlib.h>


int partition(int *, int, int); /* O(n) */
void quicksort(int *, int, int); /* O(n lgn) */
int binary_search(int *, int, int, int); /* O(lg n) */

int main(int argc, char ** argv){
    int end = 0;
    int n, q;
    int i = 1;
    int k=1;
    while(!end){
        n = atoi(argv[i]);
        q = atoi(argv[i+1]);
        if(n == 0 && q == 0) return 0;
        else{
            printf("[CASE %d]\n",k);
            int * arr = (int*)malloc(n*sizeof(int));
            for(int j = 0; j<n; j++){
                arr[j] = atoi(argv[j+2+i]);
            }   
            quicksort(arr, 0, n-1);
            for(int j = 0; j<q; j++){
                int res = binary_search(arr, 0, n-1, atoi(argv[i+2+n+j]));
                if(res != -1) printf("%d found at %d\n",atoi(argv[i+2+n+j]), res+1);
                else printf("%d not found\n", atoi(argv[i+2+n+j]));
            }
            free(arr);
        }   
            
        i += n + q + 2;
        k++;
    }
    return 0;
}

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

int binary_search(int * arr, int low, int high, int key){
    if(low > high) return -1;
    int mid = (int)(low+high)/2;
    if(arr[mid] == key){
        int left = binary_search(arr, low, mid-1, key);
        return (left != -1)? left:mid;
    }
    else if(arr[mid] > key){
        return binary_search(arr, low, mid-1, key);
    }else{
        return binary_search(arr, mid+1, high, key);
    }
}
