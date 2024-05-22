#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    int* sparse_table[(int)log2(n)+1];
    for(int i=0;i<=(int)log2(n);i++){
        sparse_table[i]= new int[n-(1<<i)+1];
    }

    for(int j=0;j<n;j++){
        cin >> sparse_table[0][j];
    }
    cin.ignore();
  
    for(int i=1;(1<<i)<=n;i++){
        for(int j=0;(j+(1<<i)-1)<n;j++){
            sparse_table[i][j]=min(sparse_table[i-1][j], sparse_table[i-1][(1<<(i-1))+j]);
        }
    }

    
    int m, sum=0;
    cin >> m;
    cin.ignore();
    int i, j, k;
    for(int num=1;num<=m;num++){
        cin >> i >> j;
        cin.ignore();
        k=(int)(log2(j-i+1));
        sum = sum + min(sparse_table[k][i], sparse_table[k][j-(1<<k)+1]);
    }

    cout << sum;
    return 0;
}