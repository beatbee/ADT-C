/*
    Task	: test
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 08 July 2022 [23:31]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
void func(int a[]){
    a[3]*=2;
}
int main(){
    int a[5] = {1,2,3,4,5};
    int i;
    func(a);
    for(i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return 0;
}