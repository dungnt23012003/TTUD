#include<bits/stdc++.h>
using namespace std;
int k, n, load=0;
int a[2200][2200];
int visited[2200];
int solution[2200];
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

void CBUS(){
    for(int step=1;step<=2*n;step++){
        int hub;
        int min_distance = INT_MAX;
        for(int value=1;value<=2*n;value++){
            if(check(value) && a[solution[step-1]][value] < min_distance){
                hub = value;
                min_distance = a[solution[step-1]][value];
            }
        }
        solution[step] = hub;
        f = f + min_distance;
        visited[hub] = true;
        if (hub<=n)
            load = load + 1;
        else load = load - 1;
    }
}
int main(){
    cin >> n >> k;
    
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            cin >> a[i][j];
        }
    }
    

    for(int i=1;i<=2*n;i++){
        visited[i]=false;
    }

    solution[0]=0;  
    CBUS();

    
    cout << n << '\n' ;
    for(int i=1;i<=2*n;i++){
        cout << solution[i] << ' ';
    }
    cout  << '\n' << f;
    return 0;
}