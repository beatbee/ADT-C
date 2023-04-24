/*
    Task	: intregrate
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 06 July 2022 [22:37]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<math.h>
int main(){
    double i;
    double a,b,A,B,n,x,h1,h2,ans = 0,two;
    scanf("%lf %lf %lf %lf %lf",&a,&b,&A,&B,&n);
    x = (b-a)/n;
    for(i=0;i<n;i++){
        h1 = A*sin((M_PI*(a+(x*i)))/B);
        two = a+(x*(i+1));
        h2 = A*sin((M_PI*two)/B);
        ans += (h1+h2)*(x)/2;
    }
    printf("%.5lf",ans);
    return 0;
}