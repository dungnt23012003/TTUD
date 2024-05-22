#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    long long s0[n+1], s1[n+1];
    s0[0]=1;
    s1[0]=1;
    

    for(int i=1;i<=n;i++){
        s0[i]=s1[i-1];
        long long sum_s0=0;//tong s0[i-k2] to s0[i-k1]
        for(int j=i-k2;j<=i-k1;j++){
            if(j>=0){
                 sum_s0 = sum_s0 + s0[j];
            }
        }
        s1[i]=sum_s0;
    }

    cout << (s0[n]+s1[n])%10000000007;
    return 0;
}