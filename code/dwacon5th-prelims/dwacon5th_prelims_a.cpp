#include <iostream>

using namespace std;

int main(){
    int N,ans=101,sum=0,A[101];
    cin>>N;
    for(int i=0;i<N;i++){
        cin >>A[i];
        sum+=A[i];
    }
    double average=(double)sum/N,min=999,a,b;//int,intの計算では値はintにしかならず、doubleにはならない:sum/N
    for(int i=0;i<N;i++){
        if(A[i]<average){
            a=average;
            b=A[i];
        }else{
            a=A[i];
            b=average;
        }
        if(min>a-b){
            min=a-b;
            ans=i;
        }
    }
    cout <<ans;
    return 0;
}