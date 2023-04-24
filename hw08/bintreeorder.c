/*
    Task	: bintreeorder
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 01 September 2022 [14:06]
    Algo	: 
    Status	: 
*/
#include "week8.h"
#include<stdio.h>
#include <stdlib.h>

#ifndef __bin_tree__
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node_t;
typedef node_t tree_t;
#endif
void print_preorder(tree_t *now){
    if(now == NULL)
        return;
    printf("%d ",now->data);
    print_preorder(now->left);
    print_preorder(now->right);
}
void print_postorder(tree_t *now){
    if(now == NULL)
        return;
    print_postorder(now->left);
    print_postorder(now->right);
    printf("%d ",now->data);
}
void print_inorder(tree_t *now){
    if(now == NULL)
        return;
    print_inorder(now->left);
    printf("%d ",now->data);
    print_inorder(now->right);
}
int main(){
    tree_t *t = NULL;
    int n,i;
    int parent,child;
    int branch; // 0 now, 1 left, 2 right
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d",&parent,&child,&branch);
        t = attach(t,parent,child,branch);
    }
    print_preorder(t);
    printf("\n");
    print_postorder(t);
    printf("\n");
    print_inorder(t);
    return 0;
}