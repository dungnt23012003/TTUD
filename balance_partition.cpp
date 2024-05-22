#include<bits/stdc++.h>
using namespace std;
bool ispossible(int *a, int n, int k, int sum){
    int number_of_segment = 1;
    int current_sum = 0;
    for(int i=0;i<n;i++){
        if(a[i] > sum){
            return false;
        }
        else{
            if(current_sum + a[i] > sum){
                number_of_segment++;
                current_sum = a[i];
                if(number_of_segment>k)
                    return false;
            }
            else{
                current_sum = current_sum + a[i];
            }
        }
        
    }
    return true;
}
int balance_partition(int *a, int n, int k){
    int left = 1, right = 0, mid;
    for(int i=0;i<n;i++)
        right = right + a[i];
    int result = -1;
    while(left <= right){
        mid = (left + right)/2;
        if(ispossible(a, n, k, mid)){
            result = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return result;
}
int main(){
    int n, k;
    cin >> n >> k;
    int *a = new int[n-1];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << balance_partition(a, n, k);
    return 0;
}