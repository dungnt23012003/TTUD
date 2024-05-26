#include<bits/stdc++.h>
using namespace std;
int cnt;
void DFS(int num[], int low[],vector<int> edge[], int current_node, int previous_node, int &num_bridge, int articulation[]){
    low[current_node]=num[current_node]=++cnt;
    for(int i=0;i<edge[current_node].size();i++){
        if(edge[current_node][i]==previous_node){
            continue;
        }
        if(num[edge[current_node][i]]==-1){
            DFS(num, low, edge, edge[current_node][i], current_node, num_bridge, articulation);
            low[current_node]=min(low[current_node], low[edge[current_node][i]]);
            if(low[edge[current_node][i]] >= num[current_node]){
                articulation[current_node] = 1;
            }
            if(low[edge[current_node][i]] > num[current_node]){
                num_bridge = num_bridge + 1;
            }
        }
        else{
            low[current_node]=min(low[current_node], num[edge[current_node][i]]);
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
    int num_bridge = 0, num_articulation = 0, articulation[n+1];
    for(int i=1;i<=n;i++){
        num[i]=-1;
        articulation[i]=0;
    }

    for(int current_node=1;current_node<=n;current_node++){
        int child=0;
        if(num[current_node]==-1){
            cnt=0;
            low[current_node]=num[current_node]=++cnt;
            for(int i=0;i<edge[current_node].size();i++){
                if(num[edge[current_node][i]]==-1){
                    DFS(num, low, edge, edge[current_node][i], current_node, num_bridge, articulation);
                    child++;
                }
            }

            if(child>=2){
                articulation[current_node] = 1;
            }

            for(int i=0;i<edge[current_node].size();i++){
                if(low[edge[current_node][i]] > num[current_node]){
                    num_bridge = num_bridge + 1;
                }
            }
            
        }
    }

    for(int i=1;i<=n;i++){
        num_articulation = num_articulation + articulation[i];
    }
    cout << num_articulation << " " << num_bridge;



    return 0;
}