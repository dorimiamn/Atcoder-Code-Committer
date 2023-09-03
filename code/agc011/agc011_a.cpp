#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int N,C,K,Cnum=0,count=1,ans=1;
    cin>>N>>C>>K;
    int T[N];
    for(int i=0;i<N;i++)cin>>T[i];
    sort(T,T+N);
    int min=T[0]+K;//時刻
    for(int i=1;i<N;i++){
        if(min>=T[i]&&count<C){
            count++;
        }else{
            ans++;
            count=1;
            min=T[i]+K;
        }
    }
    cout<<ans<<endl;
    return 0;
}