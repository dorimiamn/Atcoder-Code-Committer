//解説AC
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=10000000000;
const int INF=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){T c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    ll N;
    cin>>N;
    vector<tuple<ll,ll,ll>> points(N);

    rep(i,N){
        ll x,y,P;
        cin>>x>>y>>P;
        points[i]={x,y,P};
    }

    ll ok=LongINF,ng=-1;
    while(ok-ng>1){
        ll mid=(ok+ng)/2;

        bool allVisit=false;

        //全頂点ダイクストラ
        rep(i,N){
            vector<bool> dist(N,false);
            dist[i]=true;
            queue<ll>que;

            que.push(i);

            while(que.size()){
                ll ni=que.front();
                que.pop();
                auto [x,y,P]=points[ni];
                rep(j,N){
                    auto [nx,ny,nP]=points[j];
                    if(dist[j])continue;
                    if(P*mid>=abs(nx-x)+abs(ny-y)){
                        dist[j]=true;
                        que.push(j);
                    }
                }
            }
            ll cnt=0;
            rep(j,N)cnt+=dist[j];
            //ここが違いそう
            if(cnt>=N){
                allVisit=true;
                break;
            }
        }
        if(allVisit){
            ok=mid;
        }else{
            ng=mid;
        }
    }

    cout<<ok<<endl;

    return 0;
}
/*
二分探索で高橋くんの最低訓練回数を求める。
Nが小さいので結構派手にやっても問題はなさそう。
dijkstra的な考え方が役に立ちそう。
priority_queueで管理？
ある頂点から、他の頂点に行くのに必要な訓練回数を事前に求めておく？
二分探索の中で、全頂点を始点として探索を始めて行く？計算量足りるのかこれ
なんかいける気がするからこれで実装してみよう
素直に二分探索をしとけばいいのかー
ダイクストラとかいらなかった
*/