#include <stdio.h>
#include <string.h>
#include <math.h>

void backtrack(char* soluzione_locale, char * input, int i ,int k, int dim){ 
    // k -> indice del vettore riga di soluzione locale 
    // condizione di stampa
    // printf("entrato nella backtrack");
    if(i==dim){
        soluzione_locale[k] = '\0';
        printf("%s\n", soluzione_locale);
        return;
    } 
    
    soluzione_locale[k] = input[i];
    backtrack(soluzione_locale, input, i+1, k+1, dim);



    soluzione_locale[k] = ' ';
    soluzione_locale[k+1] = input[i];
    backtrack(soluzione_locale, input, i+1 ,k+2, dim);
    
        
    // soluzione_locale[k+1] = '\0';
    return;
}

int main() {
    char input_str[] = "XYZ";
    int dim = strlen(input_str); // dim = 3

    // La dimensione massima dell'output è 2*dim + 1. Es. "X Y Z\0" -> 2*3 + 1 = 7
    char sol_locale[2 * dim + 1];

    // Inizializzazione: Mettiamo il PRIMO carattere (X) nel primo slot [0]
    // La ricorsione inizia dal SECONDO carattere (i=1) e dal SECONDO slot (k=1).
    sol_locale[0] = input_str[0];

    printf("Combinazioni per \"%s\":\n", input_str);
    backtrack(sol_locale, input_str, 1, 1, dim);
    
    return 0;
}
