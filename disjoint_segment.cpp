#include<bits/stdc++.h>
using namespace std;
struct segment{
    int head;
    int tail;
};
bool compare(segment a, segment b){
    return a.tail<b.tail;
}
int main(){
    int n, count=1;
    cin >> n;
    cin.ignore();
    segment a[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i].head >> a[i].tail;
        cin.ignore();
    }
    sort(a+1,a+n,compare);
    int previous_segment=1;
    cout << '\n';
    cout << a[1].head << ' ' << a[1].tail << '\n';
    for(int i=2;i<=n;i++){
        if(a[i].head > a[previous_segment].tail){
            count++;
            previous_segment=i;
            cout << a[i].head << ' ' << a[i].tail << '\n';
        }
    }
    cout << count;
    return 0;
}