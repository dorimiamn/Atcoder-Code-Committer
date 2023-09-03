//https://atcoder.jp/contests/abc145/submissions/8631213
//参考にさせて頂いたもの

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

//フェルマーの小定理を用いて逆元を求める関数?
ll power(ll a,ll b,ll c){
    ll res=1;
    a=a%c;
    while(b>0){
        if(b%2==1)res=(res*a)%c;
        b/=2;
        a=(a*a)%c;
    }
    return res;
}


int main(){
    ll X,Y;
    cin>>X>>Y;
    if((X+Y)%3!=0){
        cout<<0<<endl;
        return 0;
    }

    ll m=(2*X-Y)/3;
    ll n=(2*Y-X)/3;
    if(m<0||n<0){
        cout<<0<<endl;
        return 0;
    }

    vector<ll>fact(m+n+1);
    fact[0]=1;
    for(int i=1;i<=n+m;i++){
        fact[i]=(i*fact[i-1])%INF;
    }
    ll num=fact[n+m];
    ll den=(fact[n]*fact[m])%INF;
    den=power(den,INF-2,INF);

    
    //cout<<"m:"<<m<<"n:"<<n<<endl;
    //debugに使ったコードは消そう……

    cout<<(num*den)%INF<<endl;

    return 0;
}

//a=97,z=122