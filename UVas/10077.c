#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void to_string(char*,int,int,int,int,int,int,int);
void clear_string(char*,int);

int main(int argc, char**argv){
    int end = 0;
    int n, m, i;
    i = 1;
    char * str =(char*)(malloc(MAX*sizeof(char)));
    while(!end){
        m = atoi(argv[i]);
        n = atoi(argv[i+1]);
        if (m==1 && n==1){
            end = 1;
        }else{
            to_string(str,0,m,n, 0,1,1,0);
            printf("input: %d/%d -> %s\n", m, n, str);
            clear_string(str, MAX);
            i+=2;
        }
    }
    free(str);
    return 1;
}

void to_string(char* str, int index, int m, int n, int p_l, int q_l, int p_h, int q_h){
    int p = (p_l+p_h);
    int q = (q_l+q_h);
    if ((long long)m*q == (long long)p*n){
        str[index] = '\0';
    }
    else if( (long long)m*q < (long long)n*p){

        str[index] = 'L';
        to_string(str, index+1, m, n, p_l, q_l, p, q);
    }
    else{
        str[index] = 'R';
        to_string(str, index+1, m, n, p, q, p_h, q_h);
    }
}

void clear_string(char* str, int dim){
    for(int i=0; i<dim; i++){
        str[i] = '\0';
    }
}