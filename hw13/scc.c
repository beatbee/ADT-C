#include <stdio.h>
#include <stdlib.h>
int go[100][100],a[100],back[100][100],b[100],c[100],d[100];
int ans[100];
int n,m,temp,g,ba,finalist;
void dfs(int node, int *t){
    a[node] = 1;
    for(int i=0;i<n;i++){
        if(go[node][i] && !a[i]){
            dfs(i,t);
        }
    }
    c[node] = *t;
    (*t)++;
}

void dfs_2(int node, int *t, int *list){
    b[node] = 1;
    for(int i=0;i<n;i++){
        if(back[node][i] && !b[i]){
            dfs_2(i,t,list);
        }
    }
    d[node] = *t;
    list[*t - temp] = node;
    (*t)++;
}

void sort(){
    int temp;
    for(int i=0;i<finalist;i++){
        for(int j=i+1;j<finalist;j++){
            if(ans[i]>ans[j]){
                temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
            }
        }
    }
}

int main(){
    int *list = malloc(sizeof(int)*100);
    int i,size = 0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        go[u][v] = 1;
        back[v][u] = 1;
    }
    for(i=0;i<n;i++){
        if(a[i] == 0){
            dfs(i,&g);
        }
    }
    for(i=0;i<n;i++){
        int mx = 0, idx = -1;
        for(int j=0;j<n;j++){
            if(!b[j] && c[j] > mx){
                mx = c[j];
                idx = j;
            }
        }
        if(idx == -1) {
            break;
        }
        temp = ba;
        dfs_2(idx,&ba,list);
        size = ba - temp;
        if(finalist < size){
            finalist = size;
            for(int j=0;j<size;j++){
                ans[j] = list[j];
            }
        }
    }
    sort();
    for(i=0;i<finalist;i++){
        printf("%d ",ans[i]);
    }
}