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
    int N,X;
    cin>>N>>X;
    vector<int> x(N+1);
    rep(i,N)cin>>x[i];
    x[N]=X;
    sort(x.begin(),x.end());
    vector<int> A(N);
    rep(i,N){
        A[i]=x[i+1]-x[i];
    }
    int ANS=A[0];
    for(int i=0;i<N-1;i++){
        ANS=GCD(ANS,A[i+1]);
    }
    cout<<ANS<<endl;
    return 0;
}

//a=97,z=122