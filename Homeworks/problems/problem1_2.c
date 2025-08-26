#include <stdio.h>
#include <stdlib.h>
#define INF 50000

typedef struct Heap {
    int size;
    int length;
    int * arr;
}Heap;

Heap* create_heap(int);
void swap(int*, int*);
void heap_increase_key(Heap*, int, int);
int parent(int);
void max_heap_insert(Heap*, int);
void build_max_heap_v2(Heap*, int*);
void print_heap(Heap*);
void delete_heap(Heap*);

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    int input [n];
    Heap * h = create_heap(n);
    for(int i=0; i<n; i++){
        input[i]= atoi(argv[i+2]);
    }
    build_max_heap_v2(h, input);
    print_heap(h);
    delete_heap(h);
    free(h);
    return 0;
}

Heap* create_heap(int length){
    Heap * h = (Heap *)malloc(sizeof(Heap));
    h->arr = (int *)malloc(length*sizeof(int));
    h->size = 0;
    h->length = length;
    return h;
}

void swap(int* n1, int* n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void heap_increase_key(Heap* h, int i, int key){
    h->arr[i] = key;
    while (i>0 && h->arr[parent(i)] < h->arr[i]){
        swap(&h->arr[i], &h->arr[parent(i)]);
        i = parent(i);
    }
}

int parent(int i){
    return (i-1)/2;
}

void max_heap_insert(Heap* h, int key){
    h->size = h->size+1;
    h->arr[h->size-1] = -INF;
    heap_increase_key(h, h->size-1, key);
}

void build_max_heap_v2(Heap* h, int* input){
    for(int i=0; i<h->length; i++) max_heap_insert(h, input[i]);
}

void print_heap(Heap* h){
    for(int i=0; i<h->size; i++){
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

void delete_heap(Heap* h){
    free(h->arr);
}

