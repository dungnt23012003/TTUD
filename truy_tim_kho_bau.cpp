#include <bits/stdc++.h>
using namespace std;
#define int long long
struct treasure{
    int x=0;
    int y=0;
    int gold=0;
};

bool compare(treasure a, treasure b){
    if (a.x < b.x){
        return true;
    }
    else if(a.x==b.x){
        return a.y<b.y;
    }
    else 
        return false;
}

signed main(){
    int n;
    cin >> n;
    treasure treasures[n+1];
    for(int i=1;i<=n;i++){
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].gold;
    }
    sort(treasures, treasures+n+1, compare);
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int max_dp_before = -INT_MAX;
        for(int j=0;j<i;j++){
            if((treasures[j].x <= treasures[i].x)  && (treasures[j].y <= treasures[i].y)){
                if(max_dp_before < dp[j]){
                    max_dp_before = dp[j];
                }
            }
        }
        dp[i] = treasures[i].gold + max_dp_before;
        
    }

    int opt = -INT_MAX;
    for(int i=1;i<=n;i++){
        if(opt < dp[i]){
            opt = dp[i];
        }
    }

    cout << opt;

    return 0;
}