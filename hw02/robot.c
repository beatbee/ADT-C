/*
    Task	: 02
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 05 July 2022 [13:41]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<math.h>
int main(){
    int i,n,ch = 0;
    double ans,x=0,y=0;
    char com;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c",&com);
        if(com == 'L'){
            ch += 90;
        }
        if(com == 'R'){
            ch-=90;
        }
        if(com == 'F'){
            ch %= 360;
            if (ch == 0){
                x+=1;
            }
            else if(ch == 90 || ch == -270){
                y+=1;
            }
            else if(ch == 180 || ch ==-180){
                x-=1;
            }
            else if(ch == 270 || ch == -90){
                y-=1;
            }
            
        }
    }
    ans = sqrt((x*x)+(y*y));
    printf("%.4lf",ans);
    return 0;
}