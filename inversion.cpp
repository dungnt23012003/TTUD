#include<bits/stdc++.h>
using namespace std;
#define module_num 1000000007
long long count_inversion = 0;
void merge(int *arr, int left, int mid, int right){
    int *temp = new int[right-left+1];
    int first = left, second=mid+1;
    int index=0;
    while(first<=mid && second<=right){
        if(arr[first] > arr[second]){
            temp[index++]=arr[first++];
            count_inversion = count_inversion + (right-second+1);
        }
        else{
            temp[index++]=arr[second++];
        }
    }

    while(first <= mid){
        temp[index++]=arr[first++];
    }

    while(second <= right){
        temp[index++]=arr[second++];
    }

    for(int i=0;i<right-left+1;i++){
        arr[left+i] = temp[i];
    }

    delete[] temp;
}

void merge_sort(int *arr, int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
int main(){
    int n;
    cin >> n;
    cin.ignore();
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i]; 
    }
    
    merge_sort(a, 0, n-1);
    cout << count_inversion%module_num;
    
    return 0;
}