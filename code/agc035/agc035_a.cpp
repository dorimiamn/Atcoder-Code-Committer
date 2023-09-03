//解説Submit
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
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
    int n;
    cin>>n;
    vi a(n);
    map<ll,ll>mp;
    rep(i,n){
        ll a;
        cin>>a;
        mp[a]++;
    }
    int l=mp.size();
    if(mp[0]!=0&&l==1){
        cout<<"Yes"<<endl;
    }else if(l==2){
        ll cnt=0;
        for(auto x:mp){
            if(x.first==0&&x.second*3==n)cnt++;
            else if(x.first!=0&&x.second*3==2*n)cnt++;
            else{
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
    }else if(l==3&&mp[0]==0){
        ll xr=0;
        bool ok=true;
        for(auto x: mp){
            if(x.first==0)continue;
            xr^=x.first;
            if(x.second*3!=n){
                ok=false;
                break;
            }
        }
        if(xr!=0||!ok){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}

//a=97,z=122