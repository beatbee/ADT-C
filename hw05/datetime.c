#include<stdio.h>
typedef struct datetime{
    int date; //1-30
    int month; //1-12
    int year; //1970-..
    int dayOfWeek; // 0-6
    int hour;//0-23
    int minute;//0-59
    int second;//0-60
} datetime_t;
datetime_t createDate(int t){
    datetime_t ans;
    int sty = 1970,i,m[] = {0,31,28,31,30,31,30,31,31,30,31,30,31},j,ch = 0;
    ans.second = t%60; t/=60;
    ans.minute = t%60; t/=60;
    ans.hour = t%24; t/=24;
    ans.dayOfWeek = (t+4)%7;
    t+=1;
    for(i=sty;t > 365 ;i++){
        if (i%4 ==0 && i%100 != 0 || i%400 == 0 ){t-=366;}
        else{t-=365;}
    }
    if (i%4 ==0 && i%100 != 0 || i%400 == 0 ){m[1]+=1;}
    ans.year = i;
    for(j=0;t>m[j];j++){
        t-=m[j];
        ch = 1;
    }
    //if(ch == 0){ans.month = j;}
    ans.month = j-1;
    ans.date = t;
    return ans;
}
void printDate(datetime_t ans){
    char d[8][4] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    char mo[14][4] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    printf("%s %d %s %d %02d:%02d:%02d",d[ans.dayOfWeek],ans.date,mo[ans.month],ans.year,ans.hour,ans.minute,ans.second);
}
int main(void){
    datetime_t inputDate;
    int timestamp;
    scanf("%d",&timestamp);
    inputDate = createDate(timestamp);
    printDate(inputDate);
    return 0;
}
/*
1528374628
1597436869
382763892
50
*/