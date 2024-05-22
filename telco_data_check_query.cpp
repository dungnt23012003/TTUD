#include<bits/stdc++.h>
using namespace std;
map<string, int> ncall;
map<string, int> tcall;

int readhms(){
	int hour, minute, second;
	cin >> hour;
	cin.ignore();
	cin >> minute;
	cin.ignore();
	cin >> second;
	return 3600*hour + 60*minute + second;
}
bool is_correct_phone_number(string phone_number){
    for(int i=0;i<phone_number.size();i++)
        if((phone_number[i]-48<=0) && (phone_number[i]-48>=9))
            return false;
    return true;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string check, from_number, to_number, date;
	int number_total_call = 0, from_time, to_time, check_phone_number = 1;
	cin >> check;
	while(check!="#"){
        cin >> from_number >> to_number >> date;
        if(!is_correct_phone_number(from_number) || !is_correct_phone_number(to_number))
            check_phone_number = 0;
        from_time = readhms();
        to_time = readhms();
        cin.ignore();
        number_total_call++;
        ncall[from_number]++;
        tcall[from_number] = tcall[from_number] +  to_time - from_time;
        cin >> check;
    }

    cin >> check;
    while(check!="#"){
        if(check=="?check_phone_number"){
            cout << check_phone_number << '\n';
        }
        else if(check=="?number_calls_from"){
            cin >> from_number;
            cin.ignore();
            cout << ncall[from_number] << '\n';
        }
        else if(check=="?number_total_calls"){
            cout << number_total_call << '\n';
        }
        else if(check=="?count_time_calls_from"){
            cin >> from_number;
            cin.ignore();
            cout << tcall[from_number] << '\n';
        }
        cin >> check;
    }
	return 0;
}