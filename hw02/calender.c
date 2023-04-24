/*
    Task	: calender
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 07 July 2022 [12:30]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
int main(){
    int y,m,i,ans,j,ch = 1,day = 0,k,cnt=1;
    printf("Enter year: ");
    scanf("%d",&y);
    printf("Enter month: ");
    scanf("%d",&m);
    printf("====================\n");
    if(m==1){printf("January"); day = 31;}
    else if(m==2){printf("February");
        if (y%4 ==0 && y%100 != 0 || y%400 == 0 ){day = 29;}
        else{day = 28;}
    }
    else if(m==3){printf("March"); day = 31;}
    else if(m==4){printf("April"); day = 30;}
    else if(m==5){printf("May"); day = 31;}
    else if(m==6){printf("June"); day = 30;}
    else if(m==7){printf("July"); day = 31;}
    else if(m==8){printf("August"); day = 31;}
    else if(m==9){printf("September"); day = 30;}
    else if(m==10){printf("October"); day = 31;}
    else if(m==11){printf("November"); day = 30;}
    else if(m==12){printf("December"); day = 31;}
    printf(" %d",y);
    printf("\nSun Mon Tue Wed Thu Fri Sat\n");
    for(i=1990;i<y;i++){
        if (i%4 ==0 && i%100 != 0 || i%400 == 0 ){ ch += 366; }
        else{ch += 365;}
    }
    for(k=1;k<m;k++){
        if(k==1){ch+=31;}
        if(k==2){
        if(y%4 ==0 && y%100 != 0 || y%400 == 0 ){ch+=29;}
        else{ch+=28;}}
        if(k==3){ch+=31;}
        if(k==4){ch+=30;}
        if(k==5){ch+=31;}
        if(k==6){ch+=30;}
        if(k==7){ch+=31;}
        if(k==8){ch+=31;}
        if(k==9){ch+=30;}
        if(k==10){ch+=31;}
        if(k==11){ch+=30;}
    }
    for(j=0;j<ch%7;j++){printf("    ");}
    cnt+=ch%7;
    for(i=1;i<=day;i++){
        if(i<10){
        if(cnt == 7){printf("  %d\n",i); cnt = 0;}
        else{printf("  %d ",i);}
        }
        else{
        if(cnt == 7){printf(" %d\n",i); cnt = 0;}
        else{printf(" %d ",i);}    
        }
        cnt++;
    }
    return 0;
}