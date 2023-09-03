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
#include <unordered_map>
#include <cstring>
#include <iomanip>

using namespace std;

typedef long long ll;

const ll INF=1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,a,b,c;
    cin>>N;
    int L[N],count=0;
    rep(i,N) cin>>L[i];
    sort(L,L+N);
    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            for(int k=j+1;k<N;k++){
                a=L[i];
                b=L[j];
                c=L[k];
                if(a<b+c&&b<a+c&&c<a+b){
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}

//a=97,z=122
// 1,2,3,4,5   1,2,3 1,2,4 1,2,5, 1,3,4 1,3,5, 1,4,5, 2,3,4, 2,3,5 2,4,5 3,4,5