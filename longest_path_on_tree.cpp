#include<bits/stdc++.h>
using namespace std;
struct edge{
    int next;
    int weight;
};
vector<edge> tree[100001];
int d[100001];

void DFS(int x){
    for(int i=0;i<tree[x].size();i++){
        if (d[tree[x][i].next] == 0){
            d[tree[x][i].next] = d[x] + tree[x][i].weight;
            DFS(tree[x][i].next);
        }
    }
}

void init(){
    for(int i=0;i<=100001;i++){
        d[i] = 0;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n-1;i++){
        edge edge_tmp, edge_tmp2;
        int head;
        cin >> head >> edge_tmp.next >> edge_tmp.weight;
        edge_tmp2.next = head;
        edge_tmp2.weight = edge_tmp.weight;
        tree[head].push_back(edge_tmp);
        tree[edge_tmp.next].push_back(edge_tmp2);
    }

    init();
    DFS(1);
    int index_max = 1;
    int max = d[1];
    for(int i=2;i<=n;i++){
        if(max<d[i]){
            max = d[i];
            index_max = i;
        }
    }

    init();
    DFS(index_max);
    max = d[1];
    for(int i=2;i<=n;i++){
        if(max<d[i]){
            max = d[i];
        }
    }

    cout << max;
    return 0;
}
