#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, f, k, step, number_refueling = 0;
    cin >> a >>  b >>  f >>  k;
    int current_liters_of_gasoline = b;
    for(step=1;step<=k;step++){
        if(step<k){
            if(step%2==1){
                if(current_liters_of_gasoline < f || b < (a-f)){
                    number_refueling = -1;
                    break;
                }
                if((current_liters_of_gasoline - f - 2*(a-f))>=0){
                    current_liters_of_gasoline = current_liters_of_gasoline - a;
                }
                else{
                    current_liters_of_gasoline = b - (a-f);
                    number_refueling = number_refueling + 1;
                }
            }
            else{
                if(current_liters_of_gasoline < (a-f) || b < f){
                    number_refueling = -1;
                    break;
                }
                if((current_liters_of_gasoline - (a-f) - 2*f )>=0){
                        current_liters_of_gasoline = current_liters_of_gasoline - a;
                }
                else{
                    current_liters_of_gasoline = b - f;
                    number_refueling = number_refueling + 1;
                }
            }
        }
        else{
            if(step%2==1){
                if(current_liters_of_gasoline < f || b < (a-f)){
                    number_refueling = -1;
                    break;
                }
            }
            else{
                if(current_liters_of_gasoline < (a-f) || b < f){
                    number_refueling = -1;
                    break;
                }
            }
            if((current_liters_of_gasoline - a)<0){
                number_refueling = number_refueling + 1;
            }
        }
    }
    cout << number_refueling;
    return 0;
}