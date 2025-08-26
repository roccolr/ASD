#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node * left;
    struct Node * right;
    struct Node * p;
} Node;

typedef struct Tree{
    int size;
    struct Node * root;
}Tree;

void tree_insert(Tree*, Node *);
void tree_init(Tree*);
void in_order_tree_walk(Node *);
void delete_tree(Tree *);

int main(int argc, char ** argv){
    int n = atoi(argv[1]);
    Tree * tree = (Tree*)malloc(sizeof(Tree));
    tree_init(tree);

    for(int i=0; i<n; i++){
        Node * new_node = (Node*)malloc(sizeof(Node));
        new_node->key=atoi(argv[i+2]);
        new_node->left = NULL;
        new_node->right = NULL;
        tree_insert(tree, new_node);
    }
    in_order_tree_walk(tree->root);
    delete_tree(tree);
    free(tree);
    return 0;
}

void tree_insert(Tree* tree,  Node * z){
    Node * y = NULL;
    Node * x = tree->root;
    while(x != NULL){
        y = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->p=y;
    if(y == NULL) tree->root = z;
    else if(z->key < y->key) y->left=z;
    else y->right = z;
    tree->size += 1;
}

void tree_init(Tree* tree){
    tree->root = NULL;
    tree->size = 0;
}

void in_order_tree_walk(Node * x){
    if (x != NULL){
        in_order_tree_walk(x->left);
        printf("%d ", x->key);
        in_order_tree_walk(x->right);
    }
}

void free_node(Node * x){
    if(x != NULL){
        free_node(x->left);
        free_node(x->right);
        free(x);
    }
}

void delete_tree(Tree * tree){
    free_node(tree->root);
    tree->root = 0;
    tree->size = 0;
}

