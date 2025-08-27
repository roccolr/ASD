#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>
#include <time.h>
#define N 8
#define MAX 100

uint8_t diag_p[2*N-1]; 
uint8_t diag_s[2*N-1];
uint8_t pos[N]; // un elemento per ogni riga, 1 se è occupata 0 altrimenti 
uint8_t col[N]; // un elemento per ogni colonna, 1 se è occupata 0 altrimenti
int board[N][N];

unsigned long long solutions_found = 0;
unsigned int sum = 0;

void init();
int calculate_sum();
void queen_backtrack(int);

int main(){
    init();
    queen_backtrack(0);
    printf("sum: %d\n", sum);
    return 0;
}

int calculate_sum(){
    unsigned int partial_sum = 0;
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            if(pos[r] == c) partial_sum+=board[r][c];
        }
    }
    return partial_sum;
}

void queen_backtrack(int r){
    if (r == N){
        solutions_found++;
        int partial_sum = calculate_sum();
        sum = partial_sum>sum? partial_sum:sum;
    }

    for(int c =0; c<N; c++){
        int idx_p = r+c;
        int idx_s = r-c+(N-1);

        if(!col[c] && !diag_p[idx_p] && !diag_s[idx_s]){
            // valid position
            
            // make move
            pos[r] = c;
            col[c] = 1;
            diag_p[idx_p] = 1;
            diag_s[idx_s] = 1;

            queen_backtrack(r+1);

            // pos[r] = 0; don't need to cancel this move
            col[c] = 0;
            diag_p[idx_p] = 0;
            diag_s[idx_s] = 0;
        }
    }
}

void init(){
    srand(time(NULL));
    for(int i=0; i<N; i++){
        pos[i] = 0;
        col[i] = 0;
    }

    for(int i=0; i<2*N-1; i++){
        diag_p[i]=0;
        diag_s[i]=0;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            board[i][j] = rand()%MAX;
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

