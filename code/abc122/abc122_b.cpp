#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <sstream>

using namespace std;

typedef long long ll;

const ll INF=1e9+7;

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string S;
    int count=0,MAX=0;
    cin>>S;
    bool check=true;
    for(int i=0;i<S.length();i++){
        if(S[i]=='A'||S[i]=='C'||S[i]=='G'||S[i]=='T'){
            if(check!=false){
                check=false;
                count=1;
            }else{
                count+=1;
            }
        }else if(!check){
            MAX=max(count,MAX);
            check=true;
        }
    }
    MAX=max(count,MAX);
    cout<<MAX<<endl;
    return 0;
}