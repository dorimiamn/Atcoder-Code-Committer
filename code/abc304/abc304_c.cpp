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
template <class T, class Y>T GCD(T a, Y b){if(a<b){T c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int N;
    double D;
    cin>>N>>D;
    vector<pair<double,double>> points(N);
    rep(i,N){
        double x,y;
        cin>>x>>y;
        points[i]={x,y};
    }

    vector<bool> isPoison(N,false);
    isPoison[0]=true;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int i=que.front();
        que.pop();
        auto [x1,y1]=points[i];
        rep(j,N){
            if(isPoison[j])continue;
            if(i==j)continue;
            auto [x2,y2]=points[j];
            // cout<<sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))-D<<endl;
            if(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<=D){
                if(isPoison[i]){
                    que.push(j);
                    isPoison[j]=true;
                }
            }
        }
    }
    rep(i,N){
        if(isPoison[i]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
/*

*/