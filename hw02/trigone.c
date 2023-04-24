/*
    Task	: trigone
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 06 July 2022 [18:34]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<math.h>
double facs(int n){
    if (n==1){
        return 1;
    }
    else{
        return(n*facs(n-1));
    }
}
int main(){
    int i;
    double ans,x,temp,cos,tan,f;
    scanf("%lf",&x);
    ans = (M_PI/180.0)*x;
    temp = (M_PI/180.0)*x;
    for(i=1;i<10;i++){
        if (i%2 != 0){
            f = facs(2*i+1);
            ans -= pow(temp,2*i+1)/f;
        }
        else{
            f = facs(2*i+1);
            ans += pow(temp,2*i+1)/f;
        }
    }
    cos = sqrt(1-(ans*ans));
    tan = ans/cos;
    printf("%.14lf %.14lf %.14lf",ans,cos,tan);
    return 0;
}