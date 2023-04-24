/*
    Task	: countgame
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 28 July 2022 [23:49]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
struct countgame
{
    int l;
    int r;
    int shot;
}person[10000001];

int main(){
    int i,n,k,j,cnt = 1,ch = 0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&person[i].shot);
        if(i == 0){
            person[i].l = n-1;
        }
        else{
            person[i].l = i-1;
        }
        if(i==n-1){
            person[i].r = 0;
        }
        else{
            person[i].r = i+1;
        }

    }
    j = 0;
    while(person[j].r != j){
        ch =cnt;
        while(ch!=0){
            if(ch%10 == k){
                ch = 1;
                break;
            }
            else{
                ch/=10;   
            }
        }
        
        if(cnt%k ==0 || cnt/10 == k || ch==1){
            person[j].shot-=1;
            if(person[j].shot<0){
                person[person[j].l].r = person[j].r;
                person[person[j].r].l = person[j].l;
            }
        }
        j = person[j].r;
        cnt+=1;
    }
    printf("%d",j+1);
    return 0;
}