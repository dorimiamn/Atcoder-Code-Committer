#include <iostream>

using namespace std;

int Array_digit[5];//桁を各個保管する

int division_digit(int num){
    string digit_chalacter=to_string(num);
    int digit_num=digit_chalacter.length();
    for(int i=0;i<digit_num;i++){
        string a;
        a+=digit_chalacter[i];
        Array_digit[i]=stoi(a);
    }
    return digit_num;//returnは桁数とする
}

int main(){
    int N,A,B,num,ans=0;
    cin>>N>>A>>B;
    for(int i=1;i<=N;i++){
        int a=0;
        num=division_digit(i);
        for(int j=0;j<num;j++){
            a+=Array_digit[j];
        }
        if(A<=a&&a<=B){
            ans+=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}