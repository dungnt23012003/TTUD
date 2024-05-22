#include<bits/stdc++.h>
using namespace std;
int c[2000][2000];
int cal_distance(int* route, int n){
    int distance = 0;
    for(int i=2;i<=n;i++){
        distance = distance + c[route[i-1]][route[i]];
    }
    distance = distance + c[route[n]][route[1]];
    return distance; 
}

void opt_func(int *a, int n, int i, int j, int* new_route){
    for(int index=1;index<=i;index++)
        new_route[index] = a[index];
    for(int index = i+1;index<=j;index++)
        new_route[i+1+j-index] = a[index];
    for(int index = j+1;index<=n;index++)
        new_route[index] = a[index];
}
int main(){

    // freopen("tsp_input.txt", "r", stdin);
    // freopen("tsp_output.txt", "w", stdout);
    int n;
    cin >> n;
    bool visited[n+1];
    for(int i=1;i<=n;i++){
        visited[i] = false;
    }

    int solution[n+1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin >> c[i][j];
    }
    
    int opt = 0;
    solution[1] = 1;
    visited[1] = true;
    for(int i=2;i<=n;i++){
        int min = INT_MAX;
        int min_index;
        for(int j=1;j<=n;j++){
            if(!visited[j] && c[solution[i-1]][j] < min ){
                min = c[solution[i-1]][j];
                min_index = j;
            }
        }
        solution[i] = min_index;
        visited[min_index] = true;
        opt = opt + c[solution[i-1]][min_index];
    }

    opt = opt + c[solution[n]][1];


    // cout << '\n' << opt << '\n';

    int new_route[n+1];
    int dis_current = 0;
    bool is_improve = true;
    int best_i, best_j;
    int temp;
    while(is_improve){
        is_improve = false;
        for(int i=1;i<=n-2;i++){
            for(int j=i+2;j<=n;j++){
                opt_func(solution , n, i, j, new_route);
                dis_current = cal_distance(new_route, n);
                //cout << dis_current << ' ' << opt << '\n';
                if(dis_current < opt){
                    is_improve = true;
                    opt = dis_current;
                    best_i = i;
                    best_j = j;
                }
            }    
        }

        
        if(is_improve){
            while(best_i+1<best_j){
                temp = solution[best_i+1];
                solution[best_i+1] = solution[best_j];
                solution[best_j] = temp;
                best_i++;
                best_j--;
            }
        }
        
    }
    


    cout << n << '\n';
    for(int i=1;i<=n;i++){
        cout << solution[i] << ' ';
    }
    cout << "\n" << opt;
    return 0;
}

