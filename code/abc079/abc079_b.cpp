#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N;
    ll ANS=0,Lz=2,Lo=1;
    cin>>N;
    if(N==1){
        ANS=1;
        cout<<ANS<<endl;
        return 0;
    }

    for(int i=2;i<=N;i++){
        ANS=Lz+Lo;
        Lz=Lo,Lo=ANS;
    }
    cout<<ANS<<endl;

    return 0;
}

//a=97,z=122