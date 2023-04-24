#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TEXTSIZE 21
typedef struct item {
    char *text;
    struct item *next;
}item_t;
typedef struct hash{
    item_t **table;
    int size;
    int hash_key;
}hash_t;
hash_t *init_hashtable(int size, int hash_key){
    hash_t *hash = (hash_t *)malloc(sizeof(hash_t));
    hash->table = (item_t **)malloc(sizeof(item_t *)*size);
    hash->size = size;
    hash->hash_key = hash_key;
    for(int i=0; i<size; i++){
        hash->table[i] = NULL;
    }
    return hash;
}
unsigned int f(char *text,int i,int hash_key){
    if(i == 0){
        return text[0];
    }
    else{
        return (hash_key*f(text,i-1,hash_key) + text[i]);
    }
}
int hashf(char *text, int table_size, int hash_key){
    return f(text,strlen(text)-1,hash_key) % table_size;
}
void insert(hash_t *hash, char *text){
    int index = hashf(text,hash->size,hash->hash_key);
    item_t *new = (item_t *)malloc(sizeof(item_t));
    new->text = (char *)malloc(sizeof(char)*TEXTSIZE);
    strcpy(new->text,text);
    new->next = NULL;
    if(hash->table[index] == NULL){
        hash->table[index] = new;
    }
    else{
        item_t *temp = hash->table[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
    }
}
int search(hash_t *hash, char *text){
    int index = hashf(text,hash->size,hash->hash_key);
    item_t *temp = hash->table[index];
    while(temp != NULL){
        if(strcmp(temp->text,text) == 0){
            return index;
        }
        temp = temp->next;
    }
    return -1;
}
int main(){
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m,n,i,hash_key;
    int command;
    scanf("%d %d %d",&m,&n,&hash_key);
    hashtable = init_hashtable(m,hash_key);
    text = (char *)malloc(sizeof(char)*TEXTSIZE);
    for(i=0;i<n;i++){
        scanf("%d %s",&command,text);
        switch(command){
            case 1:
                insert(hashtable,text);
                break;
            case 2:
                printf("%d\n",search(hashtable,text));
                break;
        }
    }
    return 0 ;
}