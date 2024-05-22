#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int trap(vector<int>& height){
            int right=0, left=0, n=height.size();
            vector<int> maxleft, maxright;

            for(int i=0;i<n;i++){
                if(height[i]<left){
                    maxleft.push_back(left);
                }
                else{
                    left=height[i];
                    maxleft.push_back(height[i]);
                }
            }

            for(int i=n-1;i>=0;i--){
                if(height[i]<right){
                    maxright.push_back(right);
                }
                else{
                    right=height[i];
                    maxright.push_back(height[i]);
                }
            }
            
            int sum=0;
            for(int i=0;i<n;i++){
                sum = sum + min(maxleft[i], maxright[n-1-i]) - height[i];
            }

            return sum;
        }

};

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    
    
    Solution solution;
    cout << solution.trap(a);
}