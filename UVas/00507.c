#include <stdio.h>
#include <limits.h>

void max_sum(int*, int, int*, int*, int*);
int max(int, int);

void max_sum(int* arr, int n, int* sum, int* start_idx, int* stop_idx){
    int current_start = 0, best_start = 0, best_stop = 0;
    int best_sum = arr[0];
    int dp[n];
    dp[0] = arr[0];

    for(int i=1; i<n; i++){
        if(arr[i] > arr[i] + dp[i-1]){
            //nuovo start
            current_start = i;
            dp[i] = arr[i];
        }else{
            //estendo
            dp[i] = dp[i-1] + arr[i];
        }

        if(dp[i] > sum){
            best_sum = dp[i];
            best_start = current_start;
            best_stop = i;
        }
    }

    *start_idx = best_start;
    *stop_idx = best_stop;
    *sum = best_sum;
    return;
}

int max(int n1, int n2){return n1>n2? n1:n2;}