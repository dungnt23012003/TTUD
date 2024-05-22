#include<bits/stdc++.h>
using namespace std;
int n, K, Q;
int c[20][20];
int d[20];
int y[10];
int x[20];
int trace_x[20];
int trace_y[10];
bool visited[20];
int load[10];
int segment = 0;
int number_truck = 0;
int f=0;
int f_min=INT_MAX;
int cmin=INT_MAX;
bool check(int next_hub, int k){
    if(next_hub > 0 && visited[next_hub])
        return false;
    if(load[k] + d[next_hub] > Q )
        return false;
    return true;
}
void backtrack_x(int current_hub, int k){
    if(current_hub==0){
        if(k<K){
            backtrack_x(y[k+1],k+1);
        }
    }
    else{
        for(int value=0;value<=n;value++){
        if(check(value, k)){
            x[current_hub] = value;
            visited[value]= true;
            segment = segment + 1;
            load[k]=load[k]+d[value];
            f = f + c[current_hub][value];
            if(value>0){
                if((f + (n + number_truck - segment)*cmin) < f_min)
                    backtrack_x(value, k);
            }
            else{
                if(k<K){
                    if((f + (n + number_truck - segment)*cmin) < f_min)
                        
                        backtrack_x(y[k+1], k+1);
                }
                else
                    if(segment == n + number_truck ){

                        if(f<f_min){
                            f_min = f;
                            for(int i=1;i<=n;i++){
                                trace_x[i]=x[i];
                            }
                            for(int i=1;i<=K;i++){
                                trace_y[i]=y[i];
                            }
                                
            
                        }
                    }
                        
            }
            visited[value]=false;
            segment = segment - 1;
            load[k]=load[k] - d[value];
            f = f - c[current_hub][value];
        }
    }
    }
    

}

void backtrack_y(int k){
    int start = y[k-1] + 1;
    for(int value = start; value<=n;value++){
        if(check(value, k)){
            y[k]=value;
            visited[value] = true;
            load[k] = load[k] + d[value];
            f = f + c[0][value];
            if(value>0){
                segment = segment + 1;
            }
            if(k < K) {
            
                backtrack_y(k+1);
            }
                
            else{
                number_truck = segment;
             
                backtrack_x(y[1], 1);
            }
            if(value>0){
                segment = segment - 1;
            }
            visited[value] = false;
            load[k] = load[k] - d[value];
            f = f - c[0][value];
        }
    }
}


int main(){
    cin >> n >> K >> Q;
    cin.ignore();

    d[0]=0;
    for(int i=1;i<=n;i++){
        cin >> d[i];
    }
    cin.ignore();
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin >> c[i][j];
            if(i!=j){
                cmin = min(cmin, c[i][j]);
            }
        }   
    }
    
    y[0]=0;
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
    
    for(int i=1;i<=K;i++){
        load[i]=0;
    }

    backtrack_y(1);
    for(int i=1;i<=K;i++){
        cout << "0" << ' ';
        int current_hub = trace_y[i];
        cout << current_hub << ' ';
        while(current_hub!=0){
            current_hub = trace_x[current_hub];
            cout << current_hub << ' ';
        }
        cout << '\n';
    }
    cout << f_min;
    
    return 0;
}