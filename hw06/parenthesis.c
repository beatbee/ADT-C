/*
    Task	: parenthesis
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 03 August 2022 [22:36]
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
stacks_t *push(stacks_t *now,int a){
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node -> data = a;
    node -> next = NULL;
    node -> next = now;
    now = node;
    return now;
}
stacks_t *pop(stacks_t *now){
    node_t *node = now;
    if(now-> next == NULL){free(node);return NULL;}
    else{now = now -> next;free(node);return now;}
}
char top(stacks_t *now){
    if(now == NULL){ return NULL;}
    else{return now -> data;}
}
int main(){
    stacks_t *s = NULL;
    int i,n,cnt = 0;
    char a,tmp = 'a';
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c",&a);
        if(a == '(' || a == '[' || a == '{'){
            s = push(s,a);
            tmp = top(s);
        }
        else if((a == ')' && tmp == '(') || (a == ']' && tmp == '[' )|| (a == '}' && tmp == '{')){
                s = pop(s);
                cnt++;
                tmp = top(s);
        }
    }
    if(cnt == n/2){printf("1");}
    else{printf("0");}
    return 0;
}