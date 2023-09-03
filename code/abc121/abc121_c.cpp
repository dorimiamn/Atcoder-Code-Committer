#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const ll INF=1e13+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    ll N,M,ans=0,sum=0;
    cin>>N>>M;
    vector<pair<ll,ll> > AB(N);
    rep(i,N){
        ll a,b;
        cin>>a>>b;
        AB[i]=make_pair(a,b);
    }
    sort(AB.begin(),AB.end());
    for(ll i=0;i<N;i++){
        ll key=AB[i].first,value=AB[i].second;
        if(M>sum+value)ans+=key*value,sum+=value;
        else{
            ll a=M-sum;
            ans+=a*key;
            sum+=a;
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122