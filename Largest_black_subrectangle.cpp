#include<bits/stdc++.h>
using namespace std;
int largest_row_subrectangle(int row[], int m){
    int max_left[m];
    int max_right[m];
    stack<int> st_left;
    stack<int> st_right;

    for(int i=0;i<m;i++){
        while(!st_left.empty() && row[st_left.top()]>=row[i]){
            st_left.pop();
        }
        if(st_left.empty()){
            max_left[i]=0;
            st_left.push(i);
        }
        else{
            max_left[i]=st_left.top()+1;
            st_left.push(i);
        }
    }


    for(int i=m-1;i>=0;i--){
        while(!st_right.empty() && row[st_right.top()]>=row[i]){
            st_right.pop();
        }
        if(st_right.empty()){
            max_right[i]=m-1;
            st_right.push(i);
        }
        else{
            max_right[i]=st_right.top()-1;
            st_right.push(i);
        }
    }
    int max_value = 0;
    for(int i=0;i<m;i++){
        max_value = max((max_right[i]-max_left[i]+1)*row[i], max_value);
    }

    return max_value;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n, m;
    cin >> n >> m;
    cin.ignore();
    int mt[n][m];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mt[i][j];
    
    int max_value = largest_row_subrectangle(mt[0], m);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++)
            if(mt[i][j]==0)
                mt[i][j]=0;
            else
                mt[i][j] = mt[i][j] + mt[i-1][j];
        max_value = max(max_value, largest_row_subrectangle(mt[i], m)) ;
            
    }

    cout << max_value;
    return 0;
} 