/*
    Task	: tree
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 24 August 2022 [23:11]
    Algo	: 
    Status	: 
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *first;
    struct node *sibling;
} node_t;
typedef node_t tree_t;
typedef struct node1{
    tree_t *data;
    struct node1 *next;
}node1_t;
typedef node1_t queue_t;
queue_t *enqueue(queue_t *now,tree_t *a){
    node1_t *node = (node1_t *)malloc(sizeof(node1_t));
    node1_t *new = (node1_t *)malloc(sizeof(node1_t));
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
    node1_t *node = now;
    now = now -> next;
    free(node);
    return now;
}
tree_t *attach(tree_t *now,int parent,int child){
    tree_t *new = (tree_t *)malloc(sizeof(tree_t));
    new->data = child;
    new->first = NULL;
    new->sibling = NULL;
    if(parent == -1){
        now = new;
        return now;
    }
    if(now->data == parent){
        if(now->first == NULL){
            now->first = new;
        }else{
            tree_t *temp = now->first;
            while(temp->sibling != NULL){
                temp = temp->sibling;
            }
            temp->sibling = new;
        }
    }else{
        tree_t *temp = now->first;
        while(temp->sibling != NULL){
            if(temp->data == parent){
                if(temp->first == NULL){
                    temp->first = new;
                }else{
                    tree_t *temp2 = temp->first;
                    while(temp2->sibling != NULL){
                        temp2 = temp2->sibling;
                    }
                    temp2->sibling = new;
                }
                break;
            }
            temp = temp->sibling;
        }
    }
    return now;    
}
int search(tree_t *now,int a){
    queue_t *q = NULL;
    if(now == NULL) return 0;
    q = enqueue(q,now);
    while (q != NULL){
        now = q->data;
        q = dequeue(q);
        if(now-> data == a){
          return 1;
        }
        if(now->sibling != NULL){
            q = enqueue(q,now->sibling);
        }
        if(now->first != NULL){
            q = enqueue(q,now->first);
        }
    }
    return 0;
}
int degree(tree_t *now,int a){
    int count = 0;
    queue_t *q = NULL;
    if(now == NULL) return 0;
    q = enqueue(q,now);
    while (q != NULL){
        now = q->data;
        q = dequeue(q);
        if(now-> data == a){
          now  =now ->first;
           while(now != NULL){
               count++;
               now = now->sibling;
           }
           return count;
        }
        if(now->sibling != NULL){
            q = enqueue(q,now->sibling);
        }
        if(now->first != NULL){
            q = enqueue(q,now->first);
        }
    }
    return 0;
    
}
int is_root(tree_t *now,int a){
    if(now == NULL) return 0;
    if(now->data == a){
        return 1;
    }
    return 0;
}
int is_leaf(tree_t *now,int a){
  if(degree(now,a) == 0){
      return 1;
  }
  return 0; 
}
int depth(tree_t *now,int a){
    int count = 0;
    queue_t *q = NULL;
    if(now == NULL) return 0;
    q = enqueue(q,now);
    while (q != NULL){
        now = q->data;
        q = dequeue(q);
        if(now-> data == a){
          return count;
        }
        if(now->sibling != NULL){
            q = enqueue(q,now->sibling);
        }
        if(now->first != NULL){
            q = enqueue(q,now->first);
        }
        count++;
        printf("%d\n",count);
    }
    return 0;
}
void *bfs(tree_t *now){
    queue_t *q = NULL;
    if(now == NULL) return NULL;
    q = enqueue(q,now);
    while (q != NULL){
        now = q->data;
        q = dequeue(q);
        printf("%d ",now->data);
        if(now->sibling != NULL){
            q = enqueue(q,now->sibling);
        }
        if(now->first != NULL){
            q = enqueue(q,now->first);
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
int main(void) {
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
      */
      case 13:
        bfs(t);
        break;
      case 14:
        dfs(t);
        break;
      /*
      case 15:
        print_tree(t);
        break;
      */
    }
  }
  return 0;
}