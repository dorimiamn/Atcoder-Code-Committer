#include <iostream>
#include <string>
using namespace std;


int Array_digit[2];//桁を各個保管する

int division_digit(int num){
    string digit_chalacter=to_string(num);
    int digit_num=digit_chalacter.length();
    for(int i=0;i<digit_num;i++){
        string a;
        a+=digit_chalacter[i];
        Array_digit[i]=stoi(a);
    }
    return digit_num;
}

int main(){
    int M,D,count=0;
    cin >>M>>D;
    division_digit(D);
    if(Array_digit[1]==0){
        Array_digit[1]=10;
    }
    for(int i=1;i<=M;i++){
        for(int j=22;j<=D;j++){
            division_digit(j);
            if(Array_digit[0]*Array_digit[1]==i&&Array_digit[0]>1&&Array_digit[1]>1){
                count++;
            }
        }
    }
    cout <<count<<endl;
    return 0;
}