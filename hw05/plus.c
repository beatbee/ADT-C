/*
    Task	: plus
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 28 July 2022 [16:15]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
    
};
struct node* reverseint(struct node* head)
{
    if(head == NULL) return head;
    struct node* current = NULL;
    struct node* next = head -> link;
    head -> link = NULL;
    while(next != NULL){
        current = next;
        next = next -> link;
        current -> link = head;
        head = current;
    }
    return head;
}

struct node* add_node(struct node* head,int value)
{
    struct node* new = malloc(sizeof(struct node));
    new -> data =value;
    new -> link = NULL;
    new -> link = head;
    head = new;
    return head;
}
struct node* createint(struct node* head,int n){
 while(n!=0){
    head = add_node(head,n%10);
    n=n/10;
 } 
 return head;  
}


int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    struct node* x = NULL;
    x = createint(x,a);
    struct node* y =NULL;
    y = createint(y,b);
    return 0;
}
    /*
    int i,s = 0,d,l1,l2,sum = 0,j = 0,ch = 0;
    scanf(" %s",x);
    scanf(" %s",y);
    if(strlen(x)>=strlen(y)){
        l1 = strlen(y); l2 =strlen(x);d=l2-l1;
        for(i=l1-1;i>=0;i--){
            sum = y[i] - '0' + x[i+d] - '0' + s;
            ans[j] = sum%10;
            s = sum/10;
            sum = 0;
            j++;
        }
        for(i=d-1;i>=0;i--){
            sum = x[i] -'0' + s;
            ans[j] = sum%10;
            s = sum/10;
            sum = 0;
            j++;
        }
        if(s != 0 ){ans[j] = s;}
    }
    else{
        l1 = strlen(x); l2 = strlen(y);
        if(strlen(x)>strlen(y)){
        l1 = strlen(y); l2 =strlen(x);d=l2-l1;
        for(i=l2-1;i>=0;i--){
            sum = x[i] - '0' + y[i+d] - '0' + s;
            ans[j] = sum%10;
            s = sum/10;
            sum = 0;
            j++;
        }
        for(i=d-1;i>=0;i--){
            sum = y[i] -'0' + s;
            ans[j] = sum%10;
            s = sum/10;
            sum = 0;
            j++;
        }
        if(s != 0 ){ans[j] = s;}
        }
    }
    if(ans[j] == 0){ch = j-1;}
    else{ch = j;}
    for(i=ch;i>=0;i--){
         printf("%d",ans[i]);
    }
    return 0;
    */