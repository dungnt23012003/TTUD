#include<bits/stdc++.h>
using namespace std;
void DFS(int* num, int* low,vector<int> edge[], int current_node, int cnt, int &num_bridge, int &num_articulation){
    num[current_node]=cnt+1;
    //cout << "\n" << num[current_node] << "\n";
    low[current_node]=num[current_node];
    for(int i=0;i<edge[current_node].size();i++){
        if(num[edge[current_node][i]]==-1){
            DFS(num, low, edge, edge[current_node][i], cnt+1, num_bridge, num_articulation);
        }
        if(edge[current_node][i]!=current_node){
            low[current_node]=min(low[current_node], num[edge[current_node][i]]);
        }
        
    }

    if(low[current_node] >= num[current_node]){
        num_bridge = num_articulation + 1;
    }

    for(int i=0;i<edge[current_node].size();i++){
       if(low[edge[current_node][i]] > num[current_node]){
            num_bridge = num_bridge + 1;
       }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //input
    int n, m;
    cin >> n >> m;

    vector<int> edge[n+1];

    for(int i=1;i<=m;i++){
        int first, second;
        cin >> first >> second;
        edge[first].push_back(second);
        edge[second].push_back(first);
    }
    //DFS
    int num[n+1];
    int low[n+1];
    int num_bridge = 0, num_articulation = 0;
    for(int i=1;i<=n;i++){
        num[i]=-1;
    }

    for(int current_node=1;current_node<=n;current_node++){
        if(num[current_node]==-1){
            num[current_node]=1;
            low[current_node]=1;
            for(int i=0;i<edge[current_node].size();i++){
                if(num[edge[current_node][i]]==-1){
                    DFS(num, low, edge, edge[current_node][i], 1, num_bridge, num_articulation);
                }
                if(edge[current_node][i]!=current_node){
                    low[current_node]=min(low[current_node], num[edge[current_node][i]]);
                }
            }
            if(edge[current_node].size()>=2){
                num_articulation = num_articulation + 1;
            }
            for(int i=0;i<edge[current_node].size();i++){
                if(low[edge[current_node][i]] > num[current_node]){
                    num_bridge = num_bridge + 1;
                }
            }
            
        }
    }

    for(int current_node=1;current_node<=n;current_node++){
        cout << num[current_node] << " ";
    }

    cout << "\n";
    for(int current_node=1;current_node<=n;current_node++){
        cout << low[current_node] << " ";
    }

    cout << "\n";
    cout << num_articulation << " " << num_bridge;



    return 0;
}