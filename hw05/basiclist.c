/*
    Task	: basiclist
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 28 July 2022 [21:00]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node_t;
node_t* append(node_t *current){
    int a;
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    node_t *node = (node_t *)malloc(sizeof(node_t));
    scanf("%d",&a);
    newnode = current;
    node -> data = a;
    node -> next = NULL;
    if(current == NULL){
        current = node;
        return current;
    }
    else{
        while(current -> next != NULL){
        current = current -> next;
        }
        current -> next = node;
    }
    return newnode;
}
void get(node_t *current){
    int a,cnt = 0;
    scanf("%d",&a);
    while(cnt!=a){
        current = current->next;
        cnt++;
    }
    printf("%d\n",current -> data);
}
void show(node_t *current){
    while(current != NULL){
        printf("%d ",current -> data);
        current = current->next;
    }
    printf("\n");
}
node_t* cut(node_t *current){
    int s,e,i=0;
    node_t *newnode;
    scanf("%d %d",&s,&e);
    while(i<=e){
        if(i == s){
            newnode = current;
        }
        if(i == e){
            current -> next = NULL;
            break;
        }
        current = current -> next;
        i++;    
    }
    return newnode;
}
node_t* reverse(node_t *current){
    if(current == NULL) return current;
    node_t *nownode = NULL;
    node_t *link = current -> next;
    current -> next = NULL;
    while(link != NULL){
        nownode = link;
        link = link -> next;
        nownode -> next = current;
        current = nownode;
    }
    return current;
}
int main(){
    node_t *startNode;
    int n,i;
    char command;

    startNode = NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c",&command);
        switch (command)
        {
        case 'A':
            startNode = append(startNode);
            break;
        case 'G':
            get(startNode);
            break;
        case 'S':
            show(startNode);
            break;
        case 'R':
            startNode = reverse(startNode);
            break;
        case 'C':
            startNode = cut(startNode);
            break;
        default:
            break;
        }
    }

    return 0;
}