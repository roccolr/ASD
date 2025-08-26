#include <stdio.h>
#include <stdlib.h>
#define INF 50000

typedef struct Heap{
    int size;
    int length;
    int * arr;
}Heap;

void swap(int*, int*);
Heap * create_heap(int);
void destroy_heap(Heap*);
int left(int);
int right(int);
int parent(int);
void min_heapify(Heap *, int);
int extract_min(Heap *);
void heap_decrease_key(Heap*, int, int);
void min_heap_insert(Heap*, int);
void ordina(int *, int, int);

int main(int argc, char ** argv){
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int * input = (int*)malloc(n*sizeof(int)); 
    for(int i=0; i<n; i++) input[i] = atoi(argv[i+3]);
    ordina(input, n, k);
    for(int i=0; i<n; i++) printf("%d ", input[i]);
    printf("\n");
    free(input);
    return 0;
}

void swap(int* n1, int* n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

Heap * create_heap(int l){
    Heap * h = (Heap*)malloc(sizeof(Heap));
    h->length = l;
    h->size = 0;
    h->arr = (int*)malloc(l*sizeof(int));
    return h;
}

void destroy_heap(Heap* h){
    free(h->arr);
    free(h);
}

int left(int i){
    return (2*i)+1;
}
int right(int i){
    return (2*i)+2;
}
int parent(int i){
    return (i-1)/2;
}

void min_heapify(Heap * h, int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < h->size && h->arr[l] < h->arr[smallest]) smallest = l;
    if (r < h->size && h->arr[r] < h->arr[smallest]) smallest = r;
    if (smallest != i){
        swap(&h->arr[i], &h->arr[smallest]);
        min_heapify(h, smallest);
    }
}

int extract_min(Heap * h){
    if (h->size == 0) return -1;
    int min = h->arr[0];
    h->arr[0] = h->arr[h->size-1];
    h->size = h->size-1;
    min_heapify(h, 0);
    return min;
}

void heap_decrease_key(Heap* h, int i, int key){
    h->arr[i] = key;
    while(i>0 && h->arr[parent(i)]>h->arr[i]){
        swap(&h->arr[i], &h->arr[parent(i)]);
        i = parent(i);
    }
}

void min_heap_insert(Heap* h, int key){
    h->size = h->size+1;
    h->arr[h->size-1] = INF;
    heap_decrease_key(h, h->size-1, key);
}

void ordina(int * input, int n, int k){
    Heap * h = create_heap(k+1);

    for(int i=0; i<k+1 && i<n; i++)
        min_heap_insert(h, input[i]);
    
    int idx = 0;
    for(int i=k+1; i<n; i++){
        input[idx] = extract_min(h);
        min_heap_insert(h, input[i]);
        idx++;
    }

    // svuotiamo gli ultimi elementi dall'heap
    while(h->size>0) input[idx++] = extract_min(h);
    destroy_heap(h);
}