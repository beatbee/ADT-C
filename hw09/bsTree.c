#include<stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node_t;
typedef node_t bst_t;
bst_t *createNode(int data){
    bst_t *tmp;
    tmp = (bst_t*)malloc(sizeof(bst_t));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
bst_t* insert(bst_t *now,int data){
    if(now == NULL){
        return createNode(data);
    }
    if(now->data > data){
        now->left = insert(now->left,data);
    }
    else if(now->data < data){
        now->right = insert(now->right,data);
    }
    return now;
}
int find(bst_t *now,int data){
    if(now == NULL){
        return 0;
    }
    if(now -> data == data){
        return 1;
    }
    else if(now -> data > data){
        return find(now -> left,data);
    }
    else if(now -> data < data){
        return find(now -> right,data);
    }
    return 0;
}
bst_t* search(bst_t *now,int data){
    if(now == NULL){
        return NULL;
    }
    if(now -> data == data){
        return now;
    }
    else if(now -> data > data){
        return search(now -> left,data);
    }
    else if(now -> data < data){
        return search(now -> right,data);
    }
    return NULL;
}
bst_t* min(bst_t *now){
    bst_t *tmp = now;
    if(now == NULL){
        return NULL;
    }
    if(now -> left == NULL){
        return now;
    }
    return min(now -> left);
}
bst_t* delete(bst_t *now,int data){
    if(now == NULL){
        return NULL;
    }
    if(now -> data == data){
        if(now -> left == NULL){
            bst_t *tmp = now -> right;
            free(now);
            return tmp;
        }
        else if(now -> right == NULL){
            bst_t *tmp = now -> left;
            free(now);
            return tmp;
        }
        else{
            bst_t *tmp = min(now -> right);
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
    return now;
}
int find_min(bst_t *now){
    if(now == NULL){
        return 0;
    }
    if(now -> left == NULL){
        return now -> data;
    }
    else{
        return find_min(now -> left);
    }
}
int find_max(bst_t *now){
    if(now == NULL){
        return 0;
    }
    if(now -> right == NULL){
        return now -> data;
    }
    else{
        return find_max(now -> right);
    }
}
int main(){
    bst_t *t = NULL;
    int n,i;
    int command,data;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&command);
        switch (command){
            case 1:
                scanf("%d",&data);
                t = insert(t,data);
                break;
            case 2:
             scanf("%d",&data);
             t = delete(t,data);
             break;
            case 3:
                scanf("%d",&data);
                printf("%d\n", find(t, data));
                break;
            case 4:
                printf("%d\n", find_min(t));
                break;
            case 5:
                printf("%d\n", find_max(t));
                break;
        }
    }
    return 0;   
}