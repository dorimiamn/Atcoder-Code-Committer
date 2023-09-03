/*
https://drken1215.hatenablog.com/entry/2020/01/22/114900
勉強させていただいた記事
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;


const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()

int main(){
    int N;
    cin>>N;
    ll res=0;
    vector<vector<ll>> num(10,vector<ll>(10,0));
    REP(n,1,N+1){
        vector<int> d;
        int nn=n;
        while(nn){//桁を後ろから配列につめる
            d.push_back(nn%10);
            nn/=10;
        }
        int a=d[0];//nの一番後ろ
        int b=d.back();//nの一番前
        if(!a||!b)continue;//a,bのどちらかが0での場合飛ばす
        ++num[a][b];
    }
    REP(a,1,10){
        REP(b,1,10){
            //Aの末桁がBの先桁と、Bの末桁がAの先桁に一致する物を求めたいため
            //aとbをひっくり返した物をかけて、その通りの数を答えに足す
            res+=num[a][b]*num[b][a];
        }
    }

    cout<<res<<endl;

    return 0;
}

//a=97,z=122