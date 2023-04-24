/*
    Task	: basicqueue
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 03 August 2022 [22:05]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node_t;
typedef node_t queue_t;
queue_t *enqueue(queue_t *now,int a){
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node_t *new = (node_t *)malloc(sizeof(node_t));
    new = now;
    node -> data = a;
    node -> next = NULL;
    if(now == NULL){
        now = node;
        return now;        
    }
    while (now -> next != NULL){
        now = now -> next;
    }
    now -> next = node;
    return new;
}
queue_t *dequeue(queue_t *now){
    if(now == NULL){
        printf("Queue is empty.\n");
        return now;
    }
    node_t *node = now;
    printf("%d\n",now -> data);
    now = now -> next;
    free(node);
    return now;
}
void show(queue_t *now){
    if(now == NULL){
        printf("Queue is empty.\n");
    }
    else{
        while(now != NULL){
            printf("%d ",now -> data);
            now = now -> next;
        }
        printf("\n");
    }
}
void empty(queue_t *now){
    if(now == NULL){
        printf("Queue is empty.\n");    
    }
    else{
       printf("Queue is not empty.\n"); 
    } 
}
void size(queue_t *now){
    int cnt = 0;
    while(now != NULL){
        cnt++;
        now = now -> next;
    }
    printf("%d\n",cnt);
}
int main(){
    queue_t *q = NULL;
    int n,i,command,value;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&command);
        switch(command){
            case 1:
            scanf("%d", &value);
            q = enqueue(q, value);
            break;
            case 2:
                q = dequeue(q);
                break;
            case 3:
                show(q);
                break;
            case 4:
                empty(q);
                break;
            case 5:
                size(q);
                break;        
        }
    }
    return 0;
}