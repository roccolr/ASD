#include <stdio.h>

/*
    BACKTRACKING: SOTTOINSIEMI (2^n)
    Idea: per ogni indice 'idx' decidiamo se:
          - escludere arr[idx]
          - includere arr[idx]
    Questo genera tutte le combinazioni possibili (2 scelte ^ n).
*/

// Stampa un "insieme" nei formati {a, b, c} o {} se vuoto
void print_subset(int *cur, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", cur[i]);
        if (i < len - 1) printf(", ");
    }
    printf("}\n");
}

// Backtracking per generare tutti i sottoinsiemi (power set)
void subsets_backtrack(int idx,          // posizione corrente nell'array originale
                       int n,            // dimensione dell'array
                       int *arr,         // array di input
                       int *cur,         // soluzione parziale (sottoinsieme in costruzione)
                       int cur_len,      // lunghezza della soluzione parziale
                       int *count) {     // contatore delle soluzioni trovate (output)
    // Caso base: abbiamo considerato tutti gli elementi da 0 a n-1
    if (idx == n) {
        // A questo punto 'cur' contiene un sottoinsieme valido
        print_subset(cur, cur_len);
        (*count)++;          // contabilizziamo una soluzione
        return;              // risaliamo (backtrack) allo step precedente
    }

    // Scelta 1: ESCLUDI arr[idx] dal sottoinsieme
    // Non modifichiamo 'cur' né 'cur_len'
    subsets_backtrack(idx + 1, n, arr, cur, cur_len, count);

    // Scelta 2: INCLUDI arr[idx] nel sottoinsieme
    cur[cur_len] = arr[idx];                 // aggiungiamo l'elemento alla soluzione parziale
    subsets_backtrack(idx + 1, n, arr, cur, cur_len + 1, count);
    // Backtrack implicito: non serve "togliere" esplicitamente l'elemento;
    // alla prossima chiamata cur_len decremente risalendo lo stack.
}

/*
    BACKTRACKING: PERMUTAZIONI (n!)
    Idea: costruiamo una sequenza di lunghezza n scegliendo ogni volta
          un elemento non ancora usato.
*/

void permutations_backtrack(int n, int *arr,
                            int *cur, int cur_len,
                            int *used, int *count) {
    // Caso base: abbiamo costruito una permutazione completa
    if (cur_len == n) {
        print_subset(cur, cur_len);   // riuso la stessa stampa per comodità
        (*count)++;
        return;
    }

    // Prova a mettere in posizione 'cur_len' ciascun elemento non ancora usato
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;        // salta se l'elemento arr[i] è già in uso

        used[i] = 1;                  // scegli arr[i]
        cur[cur_len] = arr[i];        // posiziona arr[i]
        permutations_backtrack(n, arr, cur, cur_len + 1, used, count);
        used[i] = 0;                  // BACKTRACK: libera arr[i] per altre scelte
    }
}

int main(void) {
    // Esempio: insieme di partenza
    int arr[] = {1, 2, 3};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    // Buffer per le soluzioni parziali (al massimo n elementi)
    int cur[16]; // 16 è sufficiente per l'esempio; in generale usa n
                 // (qui n=3, quindi è più che sufficiente)

    // 1) SOTTOINSIEMI (2^n)
    printf("Sottoinsiemi (2^n) dell'insieme {1, 2, 3}:\n");
    int count_subsets = 0;
    subsets_backtrack(/*idx=*/0, n, arr, cur, /*cur_len=*/0, &count_subsets);
    printf("Totale sottoinsiemi: %d (attesi 2^%d = %d)\n\n",
           count_subsets, n, 1 << n);

    // 2) PERMUTAZIONI (n!) — variante utile se per \"permutazioni\" intendevi davvero n!
    printf("Permutazioni (n!) dell'insieme {1, 2, 3}:\n");
    int used[16] = {0}; // marca gli elementi già usati nella permutazione corrente
    int count_perms = 0;
    permutations_backtrack(n, arr, cur, /*cur_len=*/0, used, &count_perms);
    // Fattoriale semplice per confronto (solo per n piccolo)
    int expected = 1;
    for (int i = 2; i <= n; i++) expected *= i;
    printf("Totale permutazioni: %d (attesi %d)\n", count_perms, expected);

    return 0;
}
