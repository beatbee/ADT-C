/*
    Task	: priorityqueue
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 16 September 2022 [22:23]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct heap{
    int *data;
    int last_index;
}heap_t;
heap_t* init_heap(int m){
    heap_t *h = (heap_t*)malloc(sizeof(heap_t));
    h->data = (int*)malloc(sizeof(int)*m);
    h->last_index = 1;
    return h;
}
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void insert(heap_t *h,int data){
    int now = h->last_index;
    h->data[now] = data;
    while(now > 1){
        if(h->data[now] > h->data[(now)/2]){
            swap(&h->data[now],&h->data[(now)/2]);
            now = (now)/2;
        }else{
            break;
        }
    }
    h->last_index++;
}
void delete_max(heap_t *h){
    h->data[1] = h->data[h->last_index];
    h->last_index--;
    int now = 1;
    while(now < h->last_index){
        if(h->data[now] < h->data[now*2] || h->data[now] < h->data[now*2+1]){
            if(h->data[now*2] > h->data[now*2+1]){
                swap(&h->data[now],&h->data[now*2]);
                now = now*2;
            }else{
                swap(&h->data[now],&h->data[now*2+1]);
                now = now*2+1;
            }
        }else{
            break;
        }
    }
}
int find_max(heap_t *h){
    if (h->last_index <= 1)
        return -1;
    return h->data[1];
}
void update_key(heap_t *h,int old,int new){
    int i;
    for(i=1;i<h->last_index;i++){
        if(h->data[i] == old){
            h->data[i] = new;
            break;
        }
    }
    while(i > 1){
        if(h->data[i] > h->data[(i)/2]){
            swap(&h->data[i],&h->data[(i)/2]);
            i = (i)/2;
        }else{
            break;
        }
    }
}
void bfs(heap_t *h){
    int i;
    for(i=1;i<h->last_index;i++){
        printf("%d ",h->data[i]);
    }
    printf("\n");
}
int main()
{
    heap_t *max_heap = NULL;
    int m,n,i;
    int command,data;
    int old_key,new_key;
    scanf("%d %d",&m,&n);
    max_heap = init_heap(m);
    for(i=0;i<n;i++){
        scanf("%d",&command);
        switch (command){
         case 1:
            scanf("%d",&data);
            insert(max_heap,data);
            break;
         case 2:
            delete_max(max_heap);
            break;
         case 3:
            printf("%d\n", find_max(max_heap));
            break;
         case 4:
            scanf("%d %d",&old_key,&new_key);
            update_key(max_heap,old_key,new_key);
            break;
         case 5:
            bfs(max_heap);
            break;
        }
    }
    return 0;
}