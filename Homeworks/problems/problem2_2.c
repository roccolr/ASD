#include <stdio.h>

int max(int, int);
int lis(int*, int);

int main(){
    int n,len;
    scanf("%d", &n);
    int arr[n];
    
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    len = lis(arr, n);
    printf("%d", len);
    return 0;
}

int max(int n1, int n2){
    return n1>n2? n1:n2;
}


int lis(int* arr, int n){
    int dp[n];
    int len = 0;
    for(int i=0; i<n; i++) dp[i] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]) dp[i] = max(dp[j]+1, dp[i]); 
        }
    }

    for(int i=0; i<n; i++) len = max(len, dp[i]);
    return len;
}
