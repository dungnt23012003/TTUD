#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define base 311
long long hash_func(const string& s){
    long long c=0;
    for(int i=0;i<s.length();i++){
        c=c*base + s[i];
        c=c%MOD;
    }
    return c;
}
long long hash_func(const string& s, int start, int end){
    long long c=0;
    for(int i=start;i<=end;i++){
        c=c*base + s[i];
        c=c%MOD;
    }
    return c;
}

int rabinKarp(const string& P, const string& T){
    int cnt = 0;
    int T_len=T.length();
    int P_len=P.length();
    bool is_match = false;
    long long e=1;
    for(int i=1;i<=P_len-1;i++){
        e=e*base;
        e=e%MOD;
    }

    long long codeP = hash_func(P), codeT = hash_func(T, 0, P_len-1), t;
    for(int i=0;i<=T_len-P_len;i++){
        if(codeP==codeT){
            is_match = true;
            for(int j=0;j<=P_len-1;j++){
                if(P[j]!=T[i+j]){
                    is_match = false;
                    break;
                }
            }
            if(is_match){
                cnt++;
            }
        }

        t = (T[i]*e)%MOD;
        t=(codeT-t+MOD)%MOD;
        codeT = (t*base+ T[i+P_len])%MOD;
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string P, T;
    getline(cin, P);
    getline(cin, T);

    cout << rabinKarp(P, T);
    
    return 0;
}