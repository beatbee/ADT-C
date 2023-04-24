/*
    Task	: anagram
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 27 September 2022 [22:46]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void swap(char *a,char *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertionSort(char sort[],int n){
    for(int i = 0;i<n;i++){
        for(int j = i-1 ; j>=0 ; j--){
            if(sort[j] > sort[j+1]){
                swap(&sort[j],&sort[j+1]);
            }
            else{
                break;
            }
        }
    }
}
char *copyword(char word[],int n){
    char *copy = (char*)malloc(n*sizeof(char));
    for(int i=0;i<n;i++){
        copy[i] = word[i];
    }
    return copy;
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    char *word = (char *)malloc(sizeof(char *) * 51);
    char *x = (char *)malloc(sizeof(char *) * 51);
    char **list = (char **)malloc(sizeof(char *) * m); 
    for(int i=0;i<m;i++){
        list[i] = (char *)malloc(sizeof(char *) * 51);
        scanf("%s",list[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%s",word);
        insertionSort(word,strlen(word));
        for(int j=0;j<m;j++){
            if(strlen(word) == strlen(list[j])){
                x = copyword(list[j],strlen(list[j]));
                insertionSort(x,strlen(x));
                if(strcmp(word,x) == 0){
                    printf("%s ",list[j]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}