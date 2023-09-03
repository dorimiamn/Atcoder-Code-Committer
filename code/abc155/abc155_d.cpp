/*
https://algo-logic.info/abc155d/
勉強させていただいたサイト
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll LongINF=1e18;
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

int N;
ll K;
vector<ll> P,M,Z;

bool judge_m(ll mid){
    ll sum=0;
    rep(i,int(P.size())){
        ll d=(mid-P[i]+1)/P[i];
        //cout<<d<<" ";
        sum+=upper_bound(M.begin(),M.end(),d)-M.begin();
    }
    //cout<<sum<<" ";
    return sum>=K;
}

bool judge_p(ll mid)
{
    ll sum=0;
    rep(i,P.size()){
        ll d=mid/P[i];
        ll tmp=upper_bound(ALL(P),d)-P.begin();
        if(i<tmp)tmp--;
        sum+=tmp;
    }
    rep(i,M.size()){
        ll d=mid/M[i];
        ll tmp=upper_bound(ALL(M),d)-M.begin();
        if(i<tmp)tmp--;
        sum+=tmp;
    }
    sum/=2;
    return sum>=K;
}

int main(){
    cin>>N>>K;
    rep(i,N){
        ll x;
        cin>>x;
        if(x>0)P.pb(x);
        else if(x<0)M.pb(x);
        else Z.pb(x);
    }

    ll p=P.size(),m=M.size(),z=Z.size();
    ll minus=p*m,zero=z*(z-1)/2+z*p+z*m,plus=p*p+m*m;
    //cout<<minus<<" "<<zero<<" "<<plus<<endl;
    if(K<=minus){
        sort(ALL(M));
        ll l=-LongINF,u=-1;
        while(u-l>1){
            ll mid=(u+l)/2;
            if(judge_m(mid)){
                u=mid;
            }else{
                l=mid;
            }
            //cout<<u<<" "<<l<<" "<<mid<<endl;
        }
        cout<<u<<endl;
    }else if(K<=minus+zero){
        cout<<0<<endl;
    }else{
        K-=(minus+zero);
        rep(i,m)M[i]=abs(M[i]);
        sort(ALL(P));
        sort(ALL(M));
        ll l=-1,u=1e18;
        while(u-l>1){
            ll mid=(u+l)/2;
            if(judge_p(mid)){
                u=mid;
            }else{
                l=mid;
            }
        }
        cout<<u<<endl;
    }

    return 0;
}

//a=97,z=122