/*
    Task	: basicStack
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 03 August 2022 [21:24]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node_t;
typedef node_t stack_t;
stack_t *push(stack_t *now,int a){
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node -> data = a;
    node -> next = NULL;
    node -> next = now;
    now = node;
    return now;
}
void top(stack_t *now){
    if(now == NULL){
        printf("Stack is empty.\n");
    }
    else{
        printf("%d\n",now -> data);
    }
}
stack_t *pop(stack_t *now){
    if(now == NULL){
        return now;
    }
    node_t *node = now;
    now = now -> next;
    free(node);
    return now;
}
void empty(stack_t *now){
    if(now == NULL){
        printf("Stack is empty.\n");    
    }
    else{
       printf("Stack is not empty.\n"); 
    } 
}
void size(stack_t *now){
    int cnt = 0;
    while(now != NULL){
        cnt++;
        now = now -> next;
    }
    printf("%d\n",cnt);
}
int main(){
    stack_t *s = NULL;
    int n,i,command,value;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&command);
        switch(command){
            case 1:
            scanf("%d", &value);
            s = push(s, value);
            break;
            case 2:
                top(s);
                break;
            case 3:
                s = pop(s);
                break;
            case 4:
                empty(s);
                break;
            case 5:
                size(s);
                break;        
        }
    }
    return 0;
}