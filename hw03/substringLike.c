/*
    Task	: substringLike
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 14 July 2022 [00:10]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include<string.h>
char word[100000],sub[100000];
int main(){
    int i=0,n,p,m,j=0,ch = 0,k,pt = 0;
    scanf("%d %d %d",&m,&p,&n);
    scanf("%s",word);
    scanf("%s",sub);
    while(i<strlen(word)){
        pt = 0;
        for(j=i;j<i+strlen(sub);j++){
            if(word[j] == sub[pt]){ch+=1;}
            pt+=1;
        }
        if(ch == strlen(sub)){
            printf("[");
            for(k=i;k<i+ch;k++){printf("%c",word[k]);}
            printf("]");
            i+=ch;
            ch =0;
        }
        else if(ch < strlen(sub) && n !=0 && ch>=strlen(sub)-n && i<=strlen(word)-strlen(sub)){
            j = 0;
            printf("[");
            for(k=i;k<i+strlen(sub);k++){
                if(word[k] == sub[j]){printf("%c",word[k]);}
                else{printf("?");}
                j++;
            }
            printf("]");
            i+=strlen(sub);
            ch =0;        
            }
        else{
            printf("%c",word[i]);
            i+=1;
            ch = 0;
        }
    }
    return 0;
}
/*
18 3 0
acabababababcbabab
aba
18 3 1
acabababababcbabab
aba
18 3 1
acabababababcabbab
abc
15 4 2
AAAGTGTGTCTGATT
GTAT
*/