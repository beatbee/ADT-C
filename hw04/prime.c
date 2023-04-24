/*
    Task	: prime
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 21 July 2022 [22:46]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<math.h>
int main(){
    int num,n,i,ch = 0;
    scanf("%d",&num);
    n = sqrt(num);
    if(num == 2){
        printf("1");
        ch = 2;
    }
    else if(num == 1 || num%2 == 0){
        printf("0");
        ch = 2;
    }
    else{
        for(i=3;i<=n;i+=2){
            if(num%i == 0){ch=1;break;}
        }
    }
    if(ch ==0){
        printf("1");
    }
    else if(ch==1){
        printf("0");
    }
    return 0;
}
// O(sqrt(n))