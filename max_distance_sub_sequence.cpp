#include<bits/stdc++.h>
using namespace std;
bool compare(int a, int b){
    return a<b;
}
bool check(int *arr, int n, int k, int distance){
    int previous_element = 0;
    int count = 1;
    for(int i=1;i<n;i++){
        if((arr[i] - arr[previous_element]) >= distance){
            previous_element = i;
            count++;
            if(count == k){
                return true;
            }
        }
    }
    return false;
}

int max_distance(int *arr, int n, int k){
    sort(arr, arr+n, compare);
    int min_distance = 0, max_distance = arr[n-1], distance, res = -1;
    while(min_distance<=max_distance){
         
        distance = (min_distance + max_distance)/2;
        if(check(arr, n, k, distance)){
            res = max(res, distance);
            min_distance = distance + 1;
        }
        else{
            max_distance = distance - 1;
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int number_of_testcase;
    cin >> number_of_testcase;
    int n, k;
    for(int i=1;i<=number_of_testcase;i++){
        cin >> n >> k;
        int *a = new int[n];
        for(int j=0;j<n;j++){
            cin >> a[j];
        }
        cout << max_distance(a, n, k) << '\n';
        delete[] a;
    }
    return 0;
}