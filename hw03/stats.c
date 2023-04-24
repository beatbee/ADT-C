/*
    Task	: stats
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 13 July 2022 [23:38]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<stdlib.h>
void findStats(double *avg,int *maxi,int *mini,int nums[],int *n){
    int i;
    *maxi = -1000,*mini = 1000;
    *avg = 0;
    for(i=0;i<*n;i++){
        if (nums[i]>*maxi){
            *maxi = nums[i];
        }
        if (nums[i]<*mini){
            *mini = nums[i];
        }
        *avg+=nums[i];
    }
    *avg/=*n;
}
int main(){
    int n,i,maxi,mini;
    double avg;
    int *nums;
    scanf("%d",&n);
    nums = (int *)malloc(sizeof(int) *n);
    for(i=0;i<n;i++){
        scanf("%d",nums+i);
    }
    findStats(&avg,&maxi,&mini,nums,&n);
    printf("%.2f %d %d",avg,maxi,mini);
    
    return 0;
}