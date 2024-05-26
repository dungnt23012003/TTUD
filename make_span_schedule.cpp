#include<bits/stdc++.h>
using namespace std;
vector<int> g[1001];
int n, m;
int d[1001];
int num_in[1001];
int earliest_time_to_start[1001];
int time_finish[1001];
int res;
int topo[1001];
void init(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> d[i];
    }

    for(int i=1;i<=n;i++){
        num_in[i]=0;
        earliest_time_to_start[i]=0;
        time_finish[i]=0;
    }

    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        num_in[v]=num_in[v]+1;
    }
}
void topo_sort(){
    init();
    queue<int> q;
    queue<int> answer;
    for(int i=1;i<=n;i++){
        if(num_in[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        answer.push(tmp);
        for(int i=0;i<g[tmp].size();i++){
            num_in[g[tmp][i]]=num_in[g[tmp][i]]-1;
            if(num_in[g[tmp][i]]==0){
                q.push(g[tmp][i]);
            }
        }
    }

    if(answer.size()<n){
        cout << "graph has cycle";
        return;
    }

    int cnt=0;
    while(!answer.empty()){
        cnt++;
        topo[cnt]=answer.front();
        answer.pop();
    }

}
int main(){
    topo_sort();
    for(int i=1;i<=n;i++){
        cout << topo[i] << " ";
    }
    return 0;
}