#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l1, l2;
    cin >> n >> l1 >>l2;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    deque<int> max_dp;
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(i<=l1){
            dp[i]=a[i];
        }
        else{
            while(!max_dp.empty() && max_dp.front()<i-l2){
                max_dp.pop_front();
            }

            while(!max_dp.empty() && dp[max_dp.back()] <= dp[i-l1]){
                max_dp.pop_back();
            }

            max_dp.push_back(i-l1);

            dp[i]=dp[max_dp.front()] + a[i];
        }
        
    }

    // for(int i=1;i<=n;i++){
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";

    int res=dp[n];
    for(int i=1;i<=n;i++){
        res=max(res,dp[i]);
    }
    cout << res;
    return 0;
}