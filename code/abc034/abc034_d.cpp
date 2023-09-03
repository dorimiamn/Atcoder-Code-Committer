//解説Submit
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1000000000000000000;
const int INF=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
template<class T>T modpow(T a,T n,T mod){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int N,K;
    cin>>N>>K;
    vector<pair<double,double>>saltWater(N);
    rep(i,N){
        cin>>saltWater[i].second>>saltWater[i].first;
    }

    // sort(ALL(saltWater),greater<pair<double,double>>());

    double ok=0,ng=100;
    rep(_,200){
        double md=(ok+ng)/2;

        int cnt=0;
        double water=0,salt=0;
        priority_queue<pair<double,int>> que;
        rep(i,N){
            //条件のよさそうなものから採用していきたいので、選ぶ、選ばないの択をするのは望ましくない
            //priority_queue に突っ込んでく
            que.push({saltWater[i].second*(saltWater[i].first-md),i});
        }
        rep(i,K){
            int index=que.top().second;
            que.pop();
            water+=saltWater[index].second;
            salt+=saltWater[index].second*saltWater[index].first;
        }
        if((salt)/water>=md){
            // cout<<"ok"<<water<<" "<<salt<<" "<<md<<endl;
            ok=md;
        }else{
            // cout<<"ng"<<water<<" "<<salt<<" "<<md<<endl;
            ng=md;
        }
    }

    cout<<decimal(10)<<ok<<endl;

    return 0;
}
/*
二分探索
濃度の高い方から、条件を満たせるかを見ていって、K個選ぶ
濃度を決め撃つことによって、混ぜる容器の優先度がわかる
*/