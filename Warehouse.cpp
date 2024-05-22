#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, T, D;
    cin >> n >> T >> D;
    int a[n+1];
    int t[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> t[i];
    }
    int dp[n+1][T+1];

    // initialization
    for(int i=1;i<=n;i++){
        dp[i][0]=0;
    }

    for(int time=1;time<=T;time++){
        for(int i=1;i<=n;i++){
            if(time-t[i]<0){
                dp[i][time]=0;
            }
            else{
                int max_dp=0;
                for(int j=i-D;j<=i-1;j++){
                    if(j>0){
                        max_dp=max(max_dp, dp[j][time-t[i]]);
                    }
                }
                dp[i][time]=max_dp + a[i];
            }
            
        }
    }
    
    int res=dp[1][T];
    for(int i=1;i<=n;i++){
        res = max(res, dp[i][T]);
    }
    cout << res;
    return 0;
}