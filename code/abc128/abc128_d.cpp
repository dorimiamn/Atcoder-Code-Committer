//http://drken1215.hatenablog.com/entry/2019/06/15/142900
//参考にさせて頂いた解説

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
#define pb push_back

int main(){
    int N,K;
    cin>>N>>K;
    vector<ll> V(N);

    for(int i=0;i<N;i++){
        cin>>V[i];
    }
    ll res=0;

    for(int p=0;p<=min(K,N);p++){
        for(int q=0;q+p<=min(K,N);q++){
            //forを二重に回すことで、右と左からの取り出し全探索ができる。総和をmin(K,N)にすることでmin(N,K)-a=bとなるのでも一方の全探索の回す回数がわかる
            vector<ll> v;
            ll cur=0;
            for(int i=0;i<p;i++)v.pb(V[i]),cur+=V[i];//p,qの回数分操作を行う
            for(int i=0;i<q;i++)v.pb(V[N-1-i]),cur+=V[N-1-i];

            sort(v.begin(),v.end());
            for(int i=0;i<min(K-p-q,(int)v.size());i++){//p,qの余った回数分捨てる
                if(v[i]<0)cur-=v[i];
            }
            res=max(res,cur);
        }
    }

    cout<<res<<endl;

    return 0;
}

//a=97,z=122