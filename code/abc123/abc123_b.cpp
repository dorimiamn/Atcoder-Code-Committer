#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>

using namespace std;

int main(){
    int A[6],B[6],j=0,min=0;
    B[0]=0;
    string checker("9");
    for(int i=0;i<5;i++){
        cin>>A[i];
    }
    int time=0;
    for(int i=0;i<5;i++){
        if(A[i]%10==0){
            time+=A[i];
        }else{
            string S=to_string(A[i]);
            reverse(S.begin(),S.end());
            int check1=S[0]-48;
            int check2=stoi(checker);
            if(check2>check1){
                checker.pop_back();
                checker.push_back(S[0]);
                min=j;
            }
            B[j]=A[i];
            j++;
        }
    }
    for(int i=0;i<j;i++){
        if(i!=min){
            for(int k=0;k<=13;k++){
                if(time+k*10>time+B[i]){
                    time+=k*10;
                    break;
                }
            }
        }
    }
    time+=B[min];
    cout<<time<<endl;
    return 0;
}