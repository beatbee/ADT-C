#include "week8.h"
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef __bin_tree__
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node_t;
typedef node_t tree_t;
#endif
int height(tree_t *now){
    if(now == NULL)
        return -1;
    int hl = height(now->left);
    int hr = height(now->right);
    if(hl > hr)
        return hl+1;
    else
        return hr+1;
}
int is_full(tree_t *now){
    if(now == NULL)
        return 1;
    if(now->left == NULL && now->right == NULL)
        return 1;
    if(now->left != NULL && now->right != NULL)
        return is_full(now->left) && is_full(now->right);
    return 0;
}
int countnode(tree_t *now){
    if(now == NULL)
        return 0;
    return 1+countnode(now->left)+countnode(now->right);
}
int is_perfect(tree_t *now){
    if(now == NULL)
        return 0;
    int h = height(now);
    if(pow(2,h+1)-1 == countnode(now))
        return 1;
    return 0;
}
int check_complete(tree_t *now,int index,int number){
    if(now == NULL)
        return 1;
    if(index >= number)
        return 0;
    return check_complete(now->left,2*index+1,number) && check_complete(now->right,2*index+2,number);
}
int is_complete(tree_t *now){
    int current = 0;
    if(now == NULL)
        return 1;
    if(current >= countnode(now))
        return 0;
    return check_complete(now,current,countnode(now));
}
int is_degenerate(tree_t *now){
    if(now == NULL)
        return 1;
    if(now->left == NULL && now->right == NULL)
        return 1;
    if(now->left != NULL && now->right == NULL)
        return is_degenerate(now->left);
    if(now->left == NULL && now->right != NULL)
        return is_degenerate(now->right);
    return 0;
}
int is_skewedl(tree_t *now){
    if(now == NULL)
        return 1;
    if(now->left == NULL && now->right == NULL)
        return 1;
    if(now->left != NULL && now->right == NULL)
        return is_skewedl(now->left);
    return 0;
}
int is_skewedr(tree_t *now){
    if(now == NULL)
        return 1;
    if(now->left == NULL && now->right == NULL)
        return 1;
    if(now->left == NULL && now->right != NULL)
        return is_skewedr(now->right);
    return 0;
}
int is_skewed(tree_t *now){
    if(now == NULL)
        return 1;
    if(now->left == NULL && now->right == NULL)
        return 1;
    if(is_skewedl(now) == 1 || is_skewedr(now) == 1)
        return 1;
    return 0;
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
    printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));
    return 0;
}