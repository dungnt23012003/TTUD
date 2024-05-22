#include<bits/stdc++.h>
using namespace std;
int k, n, load=0;
int a[30][30];
int visited[30];
int solution[30];
int cmin = INT_MAX;
int f_min= INT_MAX;
int f=0;
bool check(int v){
    if (visited[v]) return false;
    if(v>n){
        if (!visited[v-n]) return false;
    }
    else{
        if(load + 1 > k) return false;
    }
    return true;
}

void backtracking(int step){
    for(int v=1;v<=2*n;v++){
        if (check(v)){
            solution[step]=v;
            f = f + a[solution[step-1]][solution[step]];
            visited[v]= true;
            if (v<=n)
                load = load + 1;
            else load = load - 1;
            if(step == 2*n){
                if(f+a[solution[step]][0]<f_min)
                    f_min = f+a[solution[step]][0];
            }
            else{
                if (f + cmin*(2*n+1-step)< f_min){

                    backtracking(step+1);
                }
            }

            if (v<=n){
                load = load - 1;
            }
            else{
                load = load + 1;
            }
            f = f - a[solution[step-1]][solution[step]];
            visited[v]=false;
        }

    }
}
int main(){
    cin >> n >> k;
    for(int i=0;i<=2*n;i++)
        for(int j=0;j<=2*n;j++){
            cin >> a[i][j];
            if(i!=j){
                cmin = min(cmin, a[i][j]);
            }
            
        }

    solution[0]=0;  
    backtracking(1);

    cout << f_min;
    return 0;
}
