#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long a[n+1];

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    
    long long dp0_before, dp0_current, dp1_before, dp1_current, res;

    if(a[1]%2==0){
        dp0_before=a[1];
        dp1_before=LONG_LONG_MIN;
    }
    else{
        dp1_before=a[1];
        dp0_before=LONG_LONG_MIN;
    }
    res=dp0_before;

    for(int i=2;i<=n;i++){
        if(a[i]%2==0){
            if(dp0_before==LONG_LONG_MIN){
                dp0_current=a[i];
                dp1_current=dp1_before+a[i];
            }
            else if(dp1_before==LONG_LONG_MIN){
                dp1_current=LONG_LONG_MIN;
                dp0_current=max(a[i], dp0_before+a[i]);
            }
            else{
                dp0_current=max(a[i], dp0_before+a[i]);
                dp1_current=dp1_before+a[i];
            }

            dp0_before=dp0_current;
            dp1_before=dp1_current;
            res=max(res, dp0_current);
        }
        else{
            if(dp0_before==LONG_LONG_MIN){
                dp1_current=a[i];
                dp0_current=dp1_before+a[i];
            }
            else if(dp1_before==LONG_LONG_MIN){
                dp0_current= LONG_LONG_MIN;
                dp1_current=dp0_before+a[i];
            }
            else{
                dp0_current=dp1_before+a[i];
                dp1_current=max(a[i], dp0_before+a[i]);
            }

            dp0_before=dp0_current;
            dp1_before=dp1_current;
            res=max(res, dp0_current);
        }
    }

    
    // for(int i=1;i<=n;i++){
    //     cout << dp0[i] << " ";
    // }
    // cout << "\n";
    // for(int i=1;i<=n;i++){
    //     cout << dp1[i] << " ";
    // }
    // cout << "\n";

    if(res==LONG_LONG_MIN){
        cout << "NOT_FOUND";
    }
    else{
        cout << res;
    }
    
    return 0;
}