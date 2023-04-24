#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TEXTSIZE 21
typedef char* item_t;
typedef struct hash{
    item_t *table;
    int size;
    int hash_key;
}hash_t;
hash_t *init_hashtable(int size, int hash_key){
    hash_t *hash = (hash_t*)malloc(sizeof(hash_t));
    hash->table = (item_t*)malloc(sizeof(item_t)*size);
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
    item_t new = (item_t)malloc(sizeof(char)*TEXTSIZE);
    strcpy(new,text);
    int i,k,ans = 0;
    for(i=0; ;i++){
        k = (i+(i*i))/2;
        ans = index + k;
        if(hash->table[ans%hash->size] == NULL){
            hash->table[ans%hash->size] = new;
            break;
        }
    }
}
int search(hash_t *hash, char *text){
    int index = hashf(text,hash->size,hash->hash_key);
    int k = 0,ans = 0,i;
    for(i=0; ;i++){
        k = (i+(i*i))/2;
        ans = index + k;
        if(hash->table[ans%hash->size] == NULL){
            return -1;
        }
        if(strcmp(hash->table[ans%hash->size],text) == 0){
            return ans%hash->size;
        }
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
    text = (char*)malloc(sizeof(char)*TEXTSIZE);
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