/*
    Task	: basiclist1
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 03 August 2022 [20:54]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node_t;
node_t *append(node_t *now){
    node_t *startNode = (node_t *)malloc(sizeof(node_t));
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    int value;
    scanf("%d",&value);
    newNode -> data = value;
    newNode -> next = NULL;
    startNode = newNode;
    if(now == NULL){
        now = startNode;
        return now;
    }
    else{
        while(now -> next != NULL){
            now = now -> next;
        }
        now -> next = newNode;
    }    
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