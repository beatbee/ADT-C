/*
    Task	: estateplanner
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 22 July 2022 [23:26]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<math.h>
int cnt = 0;
void plan(int x,int y,int mx){
    int i;
    for(i=mx;i>0;i--){
        if(pow(2,i)<=x && pow(2,i)<=y){
            cnt+=1;
            plan((x-pow(2,i)),y,mx);
            plan((y-pow(2,i)),pow(2,i),mx);
            break;  
        }
        if(y == 1){cnt+=x;break; }
        if(x == 1){cnt+=y;break; }
    }
}
int main(){
    int m,n,x,y,mx = -1;
    scanf("%d %d",&m,&n);
    x = log(m)/log(2);
    y = log(n)/log(2);
    if(x>y){
        mx = x;
    }
    else{mx = y;}
    plan(m,n,(int)mx);
    printf("%d",cnt);
    return 0;
}
//O(log(n))