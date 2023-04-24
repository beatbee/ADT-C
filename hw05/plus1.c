/*
    Task	: plus1
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 28 July 2022 [16:58]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<string.h>
char x[10100],y[10100];
int ans[101000];
int main(){
    int i,j,cnt = 0,sum = 0,s = 0,k=0,ch = 0;
    scanf(" %s",x);
    scanf(" %s",y);
    i = strlen(x)-1;
    j = strlen(y)-1;
    while(i>=0 && j>=0){
        sum  = x[i] - '0' + y[j] - '0' + s;
        ans[cnt] = sum%10;
        s = sum/10;
        sum = 0;
        cnt++; i--; j--;
    }
    while(i>=0){
        sum = x[i] - '0' +s;
        ans[cnt] = sum%10;
        s = sum/10;
        cnt++; i--;
        sum = 0;
    }
     while(j>=0){
        sum = y[j] - '0' +s;
        ans[cnt] = sum%10;
        s = sum/10;
        cnt++; j--;
        sum = 0;
    }
    if(s){ans[cnt] = s;}
    if(ans[cnt] == 0){cnt = cnt-1;}
    for(k=cnt;k>=0;k--){printf("%d",ans[k]);}
}