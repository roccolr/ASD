#include <stdio.h>
#include <string.h>
#define MAX 10000

typedef struct {
    int top;
    int data[MAX];
} Stack;

void init_stack(Stack *);
int is_empty(Stack *);
void push(Stack*, int);
int pop(Stack*);
int top(Stack*);
int largest_rectangle(int*, int);
int max(int, int);


int main(){
    int i,j,N,M;
    int max_area = 0;

    // inizializza la matrice
    scanf("%d %d", &N, &M);
    int matrix[M][N];
    int hist[M];
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    memset(hist, 0, M*sizeof(int));
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(matrix[i][j] == 0) hist[j] += 1;
            else hist[j] = 0;
        }

        max_area = max(max_area, largest_rectangle(hist, M));
    }

    printf("MAX AREA: %d\n", max_area);
}

void init_stack(Stack * s){
    s->top = -1;
}

int is_empty(Stack * s){
    return s->top==-1? 1:0;
}
void push(Stack* s, int v){
    s->data[++s->top]=v;
}
int pop(Stack* s){
    return s->data[s->top--];
}
int top(Stack* s){
    return s->data[s->top];
}

int max(int n1, int n2) {
    return n1>n2? n1:n2;
}

int largest_rectangle(int* hist, int M){
    Stack s;
    init_stack(&s);
    int max_area=0;
    int j=0;

    while(j<M){
        if (is_empty(&s) || hist[j]>hist[top(&s)]){
            push(&s, j);
            j++;
        }else{
            int top_idx = pop(&s);
            int top_val = hist[top_idx];
            int width = is_empty(&s)? j:(j-top(&s)-1);
            max_area = max(max_area, top_val*width);
        }
    }

    while(!is_empty(&s)){
        int top_idx = pop(&s);
        int top_val = hist[top_idx];
        int width = is_empty(&s)? j:(j-top(&s)-1);
        max_area = max(max_area, top_val*width);
    }
    return max_area;
}

