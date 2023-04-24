/*
    Task	: tree1
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 27 August 2022 [21:16]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *first;
    struct node *sibling;
} node_t;
typedef struct S{
    int data;
    struct S *next;
}S_t;
typedef S_t stack_t;
stack_t *push(stack_t *now,int a){
    S_t *node = (S_t *)malloc(sizeof(S_t));
    node -> data = a;
    node -> next = NULL;
    node -> next = now;
    now = node;
    return now;
}
void top(stack_t *now){
    if(now == NULL){
        printf("Stack is empty.\n");
    }
    else{
        printf("%d\n",now -> data);
    }
}
stack_t *pop(stack_t *now){
    if(now == NULL){
        return now;
    }
    S_t *node = now;
    now = now -> next;
    free(node);
    return now;
}
typedef node_t tree_t;
typedef struct N{
    tree_t *data;
    struct N *next;
}N_t;
typedef N_t queue_t;
queue_t *enqueue(queue_t *now,tree_t *a){
    N_t *node = (N_t *)malloc(sizeof(N_t));
    N_t *new = (N_t *)malloc(sizeof(N_t));
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
        return now;
    }
    N_t *node = now;
    //printf("%d\n",now -> data);
    now = now -> next;
    free(node);
    return now;
}
int empty(queue_t *now){
    if(now == NULL){
        return 0;    
    }
    else{
       return 1; 
    } 
}
tree_t *find(tree_t *now,int a){
    if(now == NULL){
        return now;
    }
    if(now -> data == a){
        return now;
    }
    tree_t *tmp = find(now->first,a);
    if(tmp != NULL){
        return tmp;
    }
    else{
        return find(now->sibling,a);
    }
}
tree_t *attach(tree_t *now,int parent,int child){
    tree_t *node = (tree_t *)malloc(sizeof(tree_t));
    tree_t *tmp = find(now,parent);
    node -> data = child;
    node -> first = NULL;
    node -> sibling = NULL;
    if(now == NULL){
        tree_t *new = (tree_t *)malloc(sizeof(tree_t));
        new -> data = parent;
        new -> first = node;
        new -> sibling = NULL;
        return new -> first;
    }
    if(tmp->first == NULL){
        tmp -> first = node;
    }
    else{
        tmp = tmp -> first;
        while(tmp -> sibling != NULL){
            tmp = tmp -> sibling;
        }
        tmp -> sibling = node;
    }
    return now;
}
int search(tree_t *now,int a){
    if(find(now,a) != NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int degree(tree_t *now,int a){
    int count = 0;
    tree_t *tmp = find(now,a);
    if(tmp == NULL){
        return 0;
    }
    tmp = tmp -> first;
    while(tmp != NULL){
        tmp = tmp -> sibling;
        count++;
    }
    return count;
}
int is_root(tree_t *now,int a){
    if(now == NULL){
        return 0;
    }
    if(now -> data == a){
        return 1;
    }
    return 0;
}
int is_leaf(tree_t *now,int a){
    tree_t *tmp = find(now,a);
    if(tmp == NULL){
        return 0;
    }
    if(tmp -> first == NULL){
        return 1;
    }
    return 0;
}
int depth(tree_t *now,int a){
    if(now == NULL){
        return -1;
    }
    int h = -1;
    if((now -> data == a) || (h = depth(now->first,a)) >= 0){
        return h+1;
    }
    else{
        h = depth(now->sibling,a);
    }
    return h;
}
void *bfs(tree_t *now){
    queue_t *q = NULL;
    //tree_t *tmp = now;
    if(now == NULL) return NULL;
    q = enqueue(q,now);
    while (empty(q) == 1){
        now = q->data;
        q = dequeue(q);
        printf("%d ",now->data);
        if(now->first != NULL && now->sibling != NULL){
            q = enqueue(q,now->first->sibling);
        }
        if(now->sibling != NULL){
            q = enqueue(q,now->sibling);
        }
    }
    return NULL;
}
void *dfs(tree_t *now){
    if(now == NULL) return NULL;
    printf("%d ",now->data);
    tree_t *temp = now->first;
    while(temp != NULL){
        tree_t *node = dfs(temp);
        if(node != NULL) return node;
        temp = temp->sibling;
    }
    return NULL;
}
int main(){
    tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d %d", &parent, &child);
        t = attach(t, parent, child);
        break;
       case 3:
        scanf("%d", &node);
        printf("%d\n", search(t, node));
        break; 
       case 4:
        scanf("%d", &node);
        printf("%d\n", degree(t, node));
        break;
       case 5:
        scanf("%d", &node);
        printf("%d\n", is_root(t, node));
        break;
       case 6:
        scanf("%d", &node);
        printf("%d\n", is_leaf(t, node));
        break;
       case 8:
        scanf("%d", &node);
        printf("%d\n", depth(t, node));
        break;
       case 13:
        bfs(t);
        break;
       case 14:
        dfs(t);
        break;    
        /*
      case 2:
        scanf("%d", &node);
        t = detach(t, node);
        break;
      case 7:
        scanf("%d", &node);
        siblings(t, node);
        break;
      case 9:
        scanf("%d %d", &start, &end);
        print_path(t, start, end);
        break;
      case 10:
        scanf("%d %d", &start, &end);
        printf("%d\n", path_length(t, start, end));
        break;
      case 11:
        scanf("%d", &node);
        ancestor(t, node);
        break;
      case 12:
        scanf("%d", &node);
        descendant(t, node);
        break;
      
      
      case 15:
        print_tree(t);
        break;
    */
    }
  }
  return 0;
}
/*
20
1 -1 1
1 1 2
1 1 3
1 2 4
1 2 5
1 3 6
1 3 7
1 4 8
1 5 9
1 5 10
1 6 11
1 6 12
1 6 13
1 13 14
22
1 -1 1
1 1 2
1 1 3
1 2 4
1 2 5
1 3 6
1 3 7
1 6 11
1 6 12
1 6 13
1 13 14
*/