/*
    Task	: shortestPath
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 05 October 2022 [22:42]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node1{
    int vertex;
    int weight;
    struct node1 *next;
}neighbor;
typedef struct node
{
    neighbor **cor;
    int size;
}graph;
struct node1 *append(struct node1 *now,int vertex,int weight){
    struct node1 *node = (struct node1 *)malloc(sizeof(struct node1));
    node -> vertex = vertex;
    node -> weight = weight;
    node -> next = NULL;
    if(now == NULL){
        now = node;
        return now;
    }
    struct node1 *new = now;
    while(now -> next != NULL){
        now = now -> next;
    }
    now -> next = node;
    return new;
}
graph *createGraph(int size){
    graph *new = (graph *)malloc(sizeof(graph *));
    new -> size = size;
    new -> cor = (neighbor **)malloc(sizeof(neighbor *)*size);
    for(int i = 0;i < size;i++){
        new -> cor[i] = NULL;
        new -> cor[i] = append(new -> cor[i],i,0);
    }
    return new;
}
graph *addEdge(graph *now,int v1,int v2,int weight){
    now -> cor[v1] = append(now -> cor[v1],v2,weight);
    now -> cor[v2] = append(now -> cor[v2],v1,weight);
    return now;
}
int shortestPath(graph *now,int start,int end){
    int *visited = (int *)malloc(sizeof(int)*now -> size);
    int *distance = (int *)malloc(sizeof(int)*now -> size);
    for(int i = 0;i < now -> size;i++){
        visited[i] = 0;
        distance[i] = 1e9;
    }
    distance[start] = 0;
    for(int i = 0;i < now -> size;i++){
        int min = 1e9;
        int minnode = -1;
        for(int j = 0;j < now -> size;j++){
            if(visited[j] == 0 && distance[j] < min){
                min = distance[j];
                minnode = j;
            }
        }
        if(minnode == -1){
            break;
        }
        visited[minnode] = 1;
        neighbor *temp = now -> cor[minnode];
        while(temp != NULL){
            if(visited[temp -> vertex] == 0 && distance[temp -> vertex] > distance[minnode] + temp -> weight){
                distance[temp -> vertex] = distance[minnode] + temp -> weight;
            }
            temp = temp -> next;
        }
    }
    if(distance[end] == 1e9){ return -1;}
    else{return distance[end];}
}
int main(){
    int n,m,p,i;
    int u,v,w,start,end,x;
    graph *now = NULL;
    scanf("%d %d %d",&n,&m,&p);
    now = createGraph(n);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        now = addEdge(now,u,v,w);
    }
    for(i=0;i<p;i++){
        scanf("%d %d",&start,&end);
        x = shortestPath(now,start,end);
        printf("%d\n",x);
    }
    return 0;
}