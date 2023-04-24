/*
    Task	: maze
    Author	: Belle
    School	: Kasetsart University
    Language	: C
    Created	: 14 July 2022 [22:43]
    Algo	: 
    Status	: 
*/
#include<stdio.h>
#include <stdlib.h>
char maze[110][110];
int n,x,y,xe,ye,stx,sty;
void traverseMaze(int x,int y){
    int i,j;
    if(x == xe && y == ye){
        maze[x][y] = 'G';
        maze[stx][sty] = 'S';
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
            printf("%c",maze[i][j]);
            }
        printf("\n");
        }
    exit(0);
    }
    if(x+1<n && maze[x+1][y] != '#' && maze[x+1][y] != '.'){maze[x][y] = '.'; traverseMaze(x+1,y); maze[x][y] = ' ';}
    if(x-1>=0 && maze[x-1][y] != '#' && maze[x-1][y] != '.'){maze[x][y] = '.'; traverseMaze(x-1,y); maze[x][y] = ' ';}  
    if(y+1<n && maze[x][y+1] != '#' && maze[x][y+1] != '.'){maze[x][y] = '.'; traverseMaze(x,y+1); maze[x][y] = ' ';}  
    if(y-1>=0 && maze[x][y-1] != '#' && maze[x][y-1] != '.'){maze[x][y] = '.'; traverseMaze(x,y-1); maze[x][y] = ' ';}   
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %[^\n]s",maze[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(maze[i][j] == 'S'){x=i;y=j;}
            if(maze[i][j] == 'G'){xe = i;ye = j;}
        }
    }
    stx = x;sty = y;
    traverseMaze(x,y);
    return 0;
}
/*
12
############
#   #      #
S # # #### #
### #    # #
#    ### # G
#### # # # #
#  # # # # #
## # # # # #
#        # #
###### ### #
#      #   #
############
############
#...#......#
S.#.#.####.#
###.#....#.#
#  ..###.#.G
####.# #.# #
#  #.# #.# #
## #.# #.# #
#   .....# #
###### ### #
#      #   #
############
*/