#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int a,h;
    struct node *parent;
	struct node *first;
    struct node *last;
    struct node *next;
    struct node *prev;
} node_t;
typedef node_t tree_t;

typedef struct St{
	struct node *a;
	struct St *prev;
}St_t;
typedef St_t stacks_t;
typedef struct queue{
	struct node *a;
	struct queue *next;
} queue_t;
typedef queue_t queue_t;

queue_t* enqueue(queue_t* queue,node_t* a){
	queue_t* new = (queue_t*)malloc(sizeof(queue_t));
	new->a = a;
	new->next = NULL;
	if(queue == NULL){
		return new;
	}
	queue_t* temp = queue;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new;
	return queue;
}

node_t* front(queue_t* queue){
	return queue->a;
}

queue_t* dequeue(queue_t* queue){
	return queue->next;
}

St_t* push(stacks_t *s,node_t* a){
	St_t *new=(St_t*)malloc(sizeof(St_t));
	new->a=a;
	new->prev= s;
	return new;
}
node_t* top(stacks_t *s){
	return s->a;
}
St_t* pop(stacks_t *s){
	St_t *temp=s;
	s=s->prev;
	free(temp);
	return s;
}
node_t* createNode(int a){
	node_t* new = (node_t*)malloc(sizeof(node_t));
	new->a = a;
	new->h = 0;
	new->first = NULL;
    new->last = NULL;
    new->next = NULL;
    new->prev = NULL;
    new->parent = NULL;
	return new;
}
node_t* attach(node_t* now, int parent, int a){
	if(now == NULL){
		return createNode(a);
	}
	if(now->a == parent){
		node_t* new = createNode(a);
		new->parent = now;
		new->h = now->h + 1;
		if(now->first == NULL){
			now->first= new;
			now->last = new;
		}
        else{
			now->last->next = new;
			new->prev = now->last;
			now->last = new;
		}
		return now;
	}
	if(now->next != NULL)
		attach(now->next, parent, a);
	if(now->first != NULL)
		attach(now->first, parent, a);
	return now;
}
node_t* detach(node_t* now, int a){
	if(now->a == a){
		if(now->prev != NULL)
			now->prev->next = now->next;
		else
			now->parent->first = now->next;
		if(now->next != NULL)
			now->next->prev = now->prev;
		else
			now->parent->last = now->prev;
		return NULL;
	}
	if(now->next != NULL)
		detach(now->next, a);
	if(now->first != NULL)
		detach(now->first, a);
	return now;
}
int search(node_t* now,int a){
	if(now->a == a)	return 1;
	if(now->next != NULL && search(now->next,a))
		return 1;
	if(now->first != NULL && search(now->first,a))
		return 1;
	return 0;
}
int degree(node_t* now, int a){
	if(now->a == a){
		node_t* child = now->first;
		int count = 0;
		while(child != NULL){
			count++;
			child = child->next;
		}
		return count;
	}
    if(now->first != NULL){
		int t = degree(now->first, a);
		if(t != -1)
			return t;
	}
	if(now->next != NULL){
		int t = degree(now->next, a);
		if(t != -1)
			return t;
	}
	
	return -1;
}
int is_root(node_t* now, int a){
	return (now->a == a);
}
int is_leaf(node_t* now, int a){
	if(now->a == a)
		return (now->first == NULL);
	if(now->next != NULL){
		int t = is_leaf(now->next, a);
		if(t != -1)
			return t;
	}
	if(now->first != NULL){
		int t = is_leaf(now->first, a);
		if(t != -1)
			return t;
	}
	return -1;
}
void siblings(node_t* now, int a){
	if(now->a == a){
		if(now->parent == NULL)	return ;
		node_t* sibling = now->parent->first;
		while(sibling != NULL){
			if(sibling != now)
				printf("%d ",sibling->a);
			sibling = sibling->next;
		}
		printf("\n");
		return;
	}
	if(now->next != NULL){
		siblings(now->next, a);
	}
	if(now->first != NULL){
		siblings(now->first, a);
	}
}
int depth(node_t* now, int a){
	if(now->a == a)
		return now->h;
	if(now->next != NULL){
		int t = depth(now->next, a);
		if(t != -1)
			return t;
	}
	if(now->first != NULL){
		int t = depth(now->first, a);
		if(t != -1)
			return t;
	}
	return -1;
}
void print_path(node_t* now, int start, int end){
	if(now->a == end){
		stacks_t* stacks = NULL;
		node_t* node = now;
		while(node->a != start){
			stacks = push(stacks,node);
			node = node->parent;
		}
		stacks = push(stacks,node);
		while(stacks!=NULL){
			printf("%d ",top(stacks)->a);
			stacks = pop(stacks);
		}
		printf("\n");
		return ;
	}
    if(now->first != NULL){
		print_path(now->first, start, end);
	}
	if(now->next != NULL){
		print_path(now->next, start, end);
	}
	
}
int path_length(node_t* now, int start,int end){
	if(now->a == end){
		int e = now->h;
		node_t* node = now;
		while(node->a != start)
			node = node->parent;
		int ss = node->h;
		return e - ss + 1;
	}
	if(now->next != NULL){
		int t = path_length(now->next, start, end);
		if(t != -1)
			return t;
	}
	if(now->first != NULL){
		int t = path_length(now->first, start, end);
		if(t != -1)
			return t;
	}
	return -1;
}
void ancestor(node_t* now, int a){
	if(now->a == a){
		node_t* ancestor = now;
		stacks_t* stacks = NULL;
		while(ancestor != NULL){
			stacks = push(stacks,ancestor);
			ancestor = ancestor->parent;
		}
		while(stacks != NULL){
			printf("%d ",top(stacks)->a);
			stacks = pop(stacks);
		}
		printf("\n");
	}
	if(now->next != NULL){
		ancestor(now->next, a);
	}
	if(now->first != NULL){
		ancestor(now->first, a);
	}
}
void bfs(node_t* now){
	queue_t* queue = NULL;
	queue = enqueue(queue,now);
	while(queue != NULL){
		node_t* node = front(queue);
		queue = dequeue(queue);
		printf("%d ",node->a);
		node_t* child = node->first;
		while(child != NULL){
			queue = enqueue(queue,child);
			child = child->next;
		}
	}
	printf("\n");
}
void descendant(node_t* now, int a){
	if(now->a == a){
		bfs(now);
		return ;
	}
	if(now->next != NULL){
		descendant(now->next, a);
	}
	if(now->first != NULL){
		descendant(now->first, a);
	}
}

void dfs(node_t* now){
	stacks_t* stacks = NULL;
	stacks = push(stacks,now);
	while(stacks != NULL){
		node_t* node = top(stacks);
		stacks = pop(stacks);
		printf("%d ",node->a);
		if(node->next != NULL)
			stacks = push(stacks,node->next);
		if(node->first != NULL)
			stacks = push(stacks,node->first);
	}
}
void print_tree(node_t* now){
	stacks_t* stacks = NULL;
	stacks = push(stacks,now);
	while(stacks != NULL){
		node_t* node = top(stacks);
		stacks = pop(stacks);
		int i=0;
		for(i=0;i<4*node->h;i++)
			printf(" ");
		printf("%d\n",node->a);
		if(node->next != NULL)
			stacks = push(stacks,node->next);
		if(node->first != NULL)
			stacks = push(stacks,node->first);
	}
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
			case 2:
				scanf("%d", &node);
				t = detach(t, node);
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
			case 7:
				scanf("%d", &node);
				siblings(t, node);
				break;
			case 8:
				scanf("%d", &node);
				printf("%d\n", depth(t, node));
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
			case 13:
				bfs(t);
				break;
			case 14:
				dfs(t);
				break;
			case 15:
				print_tree(t);
				break;
		}
	}
	return 0;
}