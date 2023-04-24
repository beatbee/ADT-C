/*
    Task	: insertionsort
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 27 September 2022 [21:24]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
int sort[110000];
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertionSort(int n){
    for(int i = 0;i<n;i++){
        for(int j = i-1 ; j>=0 ; j--){
            if(sort[j] > sort[j+1]){
                swap(&sort[j],&sort[j+1]);
            }
            else{
                break;
            }
        }
        if(i!=0){
            for(int k=0;k<n;k++){
                printf("%d ",sort[k]);
            }
            printf("\n");  
        }
        
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&sort[i]);
        printf("");
    }
    insertionSort(n);
    return 0;
}