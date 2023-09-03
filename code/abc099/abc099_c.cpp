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
    int N;
    cin>>N;
    int res=N;
    for(int i=0;i<=N;i++){
        int cc=0;
        int t=i;
        while(t>0)cc+=t%6,t/=6;
        t=N-i;
        while(t>0)cc+=t%9,t/=9;
        if(res>cc)res=cc;
    }
    cout<<res;
    return 0;
}
//37076,29300,21524,13748,5972,4676,3380,2084,788,59,23,14,5,4,3,2,1,0;
//7776,7776,1296,729,36,9
//6の乗数を6で割るとあまりは0であり、解は6の乗数であり続けるため。