#include<bits/stdc++.h>
using namespace std;
vector<int> g[100001];
int num[100001], low[100001];
int n, m, num_scc=0;
int cnt=0;
stack<int> st;
bool deleted[100001];
void SCC(int current_node){
    st.push(current_node);
    cnt++;
    num[current_node]=low[current_node]=cnt;
    for( auto x:g[current_node]){
        if(deleted[x]){
            continue;
        }
        if(num[x]==-1){
            SCC(x);
            low[current_node]=min(low[current_node], low[x]);
        }
        else{
            low[current_node]=min(low[current_node], num[x]);
        }
    }
    if(num[current_node]==low[current_node]){
        num_scc++;
        while(true){
            int tmp_node = st.top();
            st.pop();
            deleted[tmp_node]=true;
            // cout << tmp_node << " ";
            if(tmp_node==current_node){
                break;
            }
        }
        // cout << "\n";
    }
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        num[i]=-1;
        low[i]=-1;
        deleted[i]=false;
        }

    for(int i=1;i<=n;i++){
        if(num[i]==-1){
            SCC(i);
        }
    }

    cout << num_scc;
    return 0;
}