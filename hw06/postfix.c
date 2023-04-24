/*
    Task	: postfix
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 04 August 2022 [00:33]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    float data;
    struct node *next;
}node_t;
typedef node_t stacks_t;
stacks_t *push(stacks_t *now,float a){
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node -> data = a;
    node -> next = NULL;
    node -> next = now;
    now = node;
    return now;
}
stacks_t *pop(stacks_t *now,char c){
    float a =0,b =0;
    node_t *node = now;
    if(now-> next == NULL){return now;}
    else{
        a = now -> data;
        now = now -> next;
        free(node);
        b = now -> data;
        now = now -> next;
        if(c == '+'){now = push(now,a+b);}
        else if(c == '-'){now = push(now,b-a);}
        else if(c == '*'){now = push(now,a*b);}
        else if(c == '/'){now = push(now,b/a);}
        return now;
    }
}
float top(stacks_t *now){
    if(now == NULL){ return 0;}
    else{return now -> data;}
}
int main(){
    stacks_t *s = NULL;
    int i,n,cnt = 0;
    float ch =0,tmp = 0;
    char a;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c",&a);
        if(a == '+' || a == '-' || a == '*' || a == '/'){
            s = pop(s,a);
        }
        else{
            ch = a - '0';
            s = push(s,ch);
        }
    }
    tmp = top(s);
    printf("%.2f",tmp);
    return 0;
}