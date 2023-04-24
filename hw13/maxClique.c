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
int graph[10000][10000];
int vertex[10000];
int degree[10000];
int n;
int is_clique(int a){
    for(int i = 1;i<a;i++){
        for(int j = i+1;j<a;j++){
            if(graph[vertex[i]][vertex[j]] == 0){
                return 0;
            }
        }
    }
    return 1;
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int maxClique(int i,int j){
    int maxx = 0;
    for(int k = i+1;k<=n;k++){
        vertex[j] = k;
        if(is_clique(j+1) == 1){
            maxx = max(maxx,j);
            maxx = max(maxx,maxClique(k,j+1));
        }
    }
    return maxx;
}
int main(){
    int m;
    int u,v;
    scanf("%d %d",&n,&m);
    for(int i=0;i<(m);i++){
        scanf("%d %d",&u,&v);
        u+=1;
        v+=1;
        graph[u][v] = 1;
        graph[v][u] = 1;
        degree[u]++;
        degree[v]++;
    }
    printf("%d",maxClique(0,1));
    return 0;
}