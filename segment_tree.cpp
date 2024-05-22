#include<bits/stdc++.h>
using namespace std;
#define inf 1000000007
#define maxN 100007

class ST{
    public:
    int st[4*maxN];
    ST(int n){
        for(int i=1;i<=4*n;i++)
            st[i]=0;
    }
    void update(int id, int L, int R, int index, int value){
        if(L>R) return;
        if(index < L || index > R) return;
        if(L == R) {
            st[id] = value;
            return;
        }
        int mid = (L + R)/2;
        int LC = 2*id, RC = 2*id + 1;
        update(LC, L, mid, index, value);
        update(RC, mid+1, R, index, value);
        st[id] = max(st[LC], st[RC]); 
    }
    int getmax(int id, int L, int R, int i, int j){
        if(i>R || j<L) return -inf;
        if(i<=L && j>=R) return st[id];
        int mid = (L + R)/2;
        int LC = 2*id, RC = 2*id + 1;
        return max(getmax(LC, L, mid, i, j), getmax(RC, mid+1, R, i, j)); 
    }
    
};
int main(){

    int n;
    cin >> n;
    cin.ignore();
    int a[n+1];
    ST st(n);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    cin.ignore();
    for(int i=1;i<=n;i++){
        st.update(1, 1, n, i, a[i]);
    }

    int m;
    cin >> m;
    cin.ignore();
    string command;
    for(int i=1;i<=m;i++){
        cin >> command;
        if(command=="update"){
            int index, value;
            cin >> index >> value;
            cin.ignore();
            st.update(1, 1, n, index, value);
        }
        else if(command=="get-max"){
            int i, j;
            cin >> i >> j;
            cin.ignore();
            cout << st.getmax(1, 1, n, i, j) << '\n';
        }
    }
    
    return 0;
}