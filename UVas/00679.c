#include <stdio.h>

int find_pos(int, int, int);

int main(int argc, char ** argv){
    int j = 1;
    int d,i, output;

    do{
        d = atoi(argv[j]);
        i = atoi(argv[j+1]);
        j+=2;
        output = find_pos(i, d, 1);
        printf("(%d,%d)\t->\t%d\n", d,i,output);
    }while(argv[j] != -1);
}

int find_pos(int i, int d, int root){
    if (d == 1) return root;
    else if(i%2 == 0){
        //even 
        return find_pos(i/2, d-1, root*2+1);
    }
    else return find_pos((i/2)+1, d-1, root*2);
}