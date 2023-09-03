#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll LongINF=1e13+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> X(M);
    rep(i,M)cin>>X[i];
    if(N>=M){
        cout<<0<<endl;
        return 0;
    }
    sort(X.begin(),X.end());
    int Sec=X[M-1]-X[0];
    priority_queue<int> L;
    rep(i,M-1){
        L.push(X[i+1]-X[i]);
    }
    int dif=0;
    rep(i,N-1){
        dif+=L.top();
        L.pop();
    }
    cout<<Sec-dif<<endl;
    return 0;
}

//a=97,z=122