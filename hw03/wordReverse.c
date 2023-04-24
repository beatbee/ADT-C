/*
    Task	: wordReverse
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 14 July 2022 [00:11]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<string.h>
char word[200000],k[60];
int main(){
    int i,j,ch = 0;
    scanf("%[^\n]s",word);
    for(i=strlen(word)-1;i>=0;i--){
        if(word[i] == ' ' || i == 0){
            sscanf(word+i,"%s",k);
            for(j=0;j<strlen(k);j++){
                printf("%c",k[j]);
                k[j] = ' ';
            }
        if(i!=0){
        printf(" ");
        }
        }
    }
    return 0;

}