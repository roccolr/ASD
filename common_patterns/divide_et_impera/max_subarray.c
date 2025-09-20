#include <stdio.h>
#include <limits.h>
#define INF INT_MAX

void find_max_crossing_subarray(int*, int, int, int, int*, int*, int*);
void find_max_subarray(int*, int, int, int*, int*, int*);

int main(){ 
    int n, left_idx, right_idx, sum;
    
    // SETUP
    printf("[main]\tinserire la dimensione dell'array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("[main]\tinserire gli elementi dell'array:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    find_max_subarray(arr, 0, n-1, &left_idx, &right_idx, &sum);
    printf("[main]\tleft_idx=%d, right_idx=%d, sum=%d", left_idx, right_idx, sum);
    return 0;
}


void find_max_crossing_subarray(int* arr, int low, int high, int mid, int* cross_sum, int* left, int* right){
    int left_sum = -INF, right_sum = -INF, sum = 0;
    int left_idx, right_idx;
    for(int i=mid; i>=low; i--){
        sum += arr[i];
        if(sum > left_sum){
            left_sum = sum;
            left_idx = i;
        }
    }

    sum = 0;
    for(int i=mid+1; i<=high; i++){
        sum+=arr[i];
        if(sum>right_sum){
            right_sum = sum;
            right_idx = i;
        }
    }
    *cross_sum = left_sum + right_sum; 
    *left = left_idx;
    *right = right_idx;
}

void find_max_subarray(int* a, int low, int high, int* left_idx, int* right_idx, int* sum){
    if(low == high){
        *left_idx = low;
        *right_idx = high;
        *sum = a[low];
        return;
    }
    int mid, left_sum, right_sum, cross_sum, left_low, left_high, right_low, right_high, cross_low, cross_high;
    mid = (low+high)/2;
    find_max_subarray(a, low, mid, &left_low, &left_high, &left_sum);
    find_max_subarray(a, mid+1, high, &right_low, &right_high, &right_sum);
    find_max_crossing_subarray(a, low, high, mid, &cross_sum, &cross_low, &cross_high);

    if(left_sum>=right_sum && left_sum>=cross_sum){
        *left_idx = left_low;
        *right_idx = left_high;
        *sum = left_sum;
    }else if(right_sum>=left_sum && right_sum>=cross_sum){
        *left_idx = right_low;
        *right_idx = right_high;
        *sum = right_sum;
    }else{
        *left_idx = cross_low;
        *right_idx = cross_high;
        *sum = cross_sum;
    }
    return;
}

