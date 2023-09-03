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

//末桁の1~5に注目するのは？
//5000000max
//1000回が限度

int main(){
    int X;
    int KK=1000;
    cin>>X;
    rep(i,KK){
        ll a=i*100;
        if(a>X)break;
        rep(j,KK){
            ll b=(j*101);
            if(a+b>X)break;
            rep(k,KK){
                ll c=(k*102);
                if(a+b+c>X)break;
                rep(l,KK){
                    ll d=(l*103);
                    if(a+b+c+d>X)break;
                    rep(m,KK){//節約できそう
                        ll e=(m*104);
                        if(a+b+c+d+e>X)break;
                        ll O=X-(a+b+c+d+e);
                        if(O%105==0){
                            //cout<<i<<endl<<j<<endl<<k<<endl<<l<<endl<<m<<endl<<a<<endl<<a+b+c+d+e<<endl;
                            //if(i*100+j*101+k*102+l*103+m*104==a+b+c+d+e)cout<<"AWAW"<<endl;
                            cout<<1<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<0<<endl;

    return 0;
}

//a=97,z=122