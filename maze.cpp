#include<bits/stdc++.h>
using namespace std;
struct step{
    int r;
    int c;
    int cost;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r, c;
    cin >> n >> m >> r >> c;
    cin.ignore();
    int maze[n+2][m+2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cin >> maze[i][j];
        cin.ignore();
    }
    
    queue<step> q;
    int res = -1;

    q.push(step{r, c, 0});
    maze[r][c]=1;

    while(!q.empty()){
        step tmp = q.front();
        q.pop();
        if(tmp.r > n or tmp.r < 1 or tmp.c > m or tmp.c < 1){
            res = tmp.cost;
            break;
        }
        else{
            if(maze[tmp.r+1][tmp.c]!=1){
                maze[tmp.r+1][tmp.c]=1;
                q.push(step{tmp.r+1, tmp.c, tmp.cost+1});
            }
            if(maze[tmp.r-1][tmp.c]!=1){
                maze[tmp.r-1][tmp.c]=1;
                q.push(step{tmp.r-1, tmp.c, tmp.cost+1});
            }
            if(maze[tmp.r][tmp.c+1]!=1){
                maze[tmp.r][tmp.c+1]=1;
                q.push(step{tmp.r, tmp.c+1, tmp.cost+1});
            }
            if(maze[tmp.r][tmp.c-1]!=1){
                maze[tmp.r][tmp.c-1]=1;
                q.push(step{tmp.r, tmp.c-1, tmp.cost+1});
            }       

        }
    }

    cout << res;
        
    return 0;
}