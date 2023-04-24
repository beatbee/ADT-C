/*
    Task	: hardpassword
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 04 August 2022 [14:49]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char data;
    struct node *next;
}node_t;
typedef node_t stacks_t;
stacks_t *push(stacks_t *now,char a){
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node -> data = a;
    node -> next = NULL;
    node -> next = now;
    now = node;
    return now;
}
char top(stacks_t *now){
    if(now == NULL){return '\0';}
    else{return now->data;}
}
stacks_t *pop(stacks_t *now){
    if(now == NULL){return now;}
    node_t *node = now;
    now = now -> next;
    free(node);
    return now;
}
int main(){
    stacks_t *s = NULL;
    char a = '\0';
    int ch = 0;
    while(1){
        scanf(" %c",&a);
        if(a == 'y'){break;}
        if(a == 'x'){ch = 1;}
        else if(ch == 0){s = push(s,a);}
        else if(ch == 1){
            if(a == top(s)){s = pop(s);}
            else{ch = 2;break;}
        }
    }
    if(ch == 2 || s!=NULL){printf("0");}
    else{printf("1");}
    return 0;
}