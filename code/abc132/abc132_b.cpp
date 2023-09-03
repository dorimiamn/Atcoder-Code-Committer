#include <iostream>
using namespace std;

int count1=0;

int judge(int a,int b,int c){
    if(a>b && b>c){
        count1++;
    }else if(a<b &&b<c){
        count1++;
    }
}

int main(){
    int n;
    int p[20];
    cin >>n;
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=1;i<n-1;i++){
    judge(p[i-1],p[i],p[i+1]);
    }
    cout <<count1<<endl;
}