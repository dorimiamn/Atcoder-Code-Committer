#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long ll;

const ll INF=1e13+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,M,max=0,L=0;
    int A[13][13]={0};
    cin>>N>>M;
    rep(i,M){
        int a,b;
        cin>>a>>b;
        A[a-1][b-1]=1;
    }
    for(int bit=0;bit<(1<<N);bit++){
        vector<int> B(0);
        for(int i=0;i<N;i++){
            if(bit&(1<<i)){
                B.push_back(i);
            }
        }
        bool ok=true;
        L=B.size();
        for(int i=0;i<L-1;i++){
            for(int j=i+1;j<L;j++){
                if(A[B[i]][B[j]]!=1){
                    ok=false;
                }
            }
            if(!ok)break;
        }
        if(ok&&L>max){
            max=L;
        }
    }
    cout<<max<<endl;
    return 0;
}

//a=97,z=122