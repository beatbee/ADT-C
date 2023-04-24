#include<stdio.h>
#include <stdlib.h>
#include"week9.h"
#ifndef __avl_tree__
typedef struct node{
    int data;
    int height;
    struct node *left;
    struct node *right;
}node_t;
typedef node_t avl_t;
#endif
int height(avl_t *now){
    if(now == NULL)
        return -1;
    int hl = height(now->left);
    int hr = height(now->right);
    if(hl > hr)
        return hl+1;
    else
        return hr+1;
}
avl_t* createNode(int data){
    avl_t *tmp;
    tmp = (avl_t*)malloc(sizeof(avl_t));
    tmp->data = data;
    tmp->height = 0;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
int checkbalance(avl_t *now){
    if(now == NULL)
        return 0;
    int hl = height(now->left);
    int hr = height(now->right);
    return hl-hr;
}
avl_t* rightrotate(avl_t *now){
    avl_t *tmp = now->left;
    now->left = tmp->right;
    tmp->right = now;
    now->height = height(now);
    tmp->height = height(tmp);
    return tmp;
}
avl_t* leftrotate(avl_t *now){
    avl_t *tmp = now->right;
    now->right = tmp->left;
    tmp->left = now;
    now->height = height(now);
    tmp->height = height(tmp);
    return tmp;
}
avl_t* insert(avl_t *now,int data){
    if(now == NULL){
        return createNode(data);
    }
    if(now->data > data){
        now->left = insert(now->left,data);
    }
    else if(now->data < data){
        now->right = insert(now->right,data);
    }
    now->height = height(now);
    if(checkbalance(now) > 1){
        if(data < now->left->data){
            now = rightrotate(now);
        }
        else{
            now->left = leftrotate(now->left);
            now = rightrotate(now);
        }

    }
    if(checkbalance(now) < -1){
        if(data > now->right->data){
            now = leftrotate(now);
        }
        else{
            now->right = rightrotate(now->right);
            now = leftrotate(now);
        }

    }
    return now;
}
avl_t* min(avl_t *now){
    avl_t *tmp = now;
    if(now == NULL){
        return NULL;
    }
    if(now -> left == NULL){
        return now;
    }
    return min(now -> left);
}
avl_t* delete(avl_t *now,int data){
    if(now == NULL){
        return NULL;
    }
    if(now -> data == data){
        if(now -> left == NULL){
            avl_t *tmp = now -> right;
            free(now);
            return tmp;
        }
        else if(now -> right == NULL){
            avl_t *tmp = now -> left;
            free(now);
            return tmp;
        }
        else{
            avl_t *tmp = min(now -> right);
            now -> data = tmp -> data;
            now -> right = delete(now -> right,tmp -> data);
        }
    }
    else if(now -> data > data){
        now -> left = delete(now -> left,data);
    }
    else if(now -> data < data){
        now -> right = delete(now -> right,data);
    }
    now->height = height(now);
    if(checkbalance(now) > 1){
        if(data >= now->left->data){
            now = rightrotate(now);
        }
        else{
            now->left = leftrotate(now->left);
            now = rightrotate(now);
        }

    }
    if(checkbalance(now) < -1){
        if(data <= now->right->data){
            now = leftrotate(now);
        }
        else{
            now->right = rightrotate(now->right);
            now = leftrotate(now);
        }

    }
    return now;
}
int main(){
    avl_t *t = NULL;
    int n,i;
    int command,data;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&command);
        switch(command){
            case 1:
                scanf("%d",&data);
                t = insert(t,data);
                break;
            case 2:
                scanf("%d",&data);
                t = delete(t,data);
                break;
            case 3:
                print_tree(t);
    }
    }
    return 0;
}