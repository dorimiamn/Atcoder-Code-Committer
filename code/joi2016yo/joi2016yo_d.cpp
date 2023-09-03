#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll LongINF=1e18*9+1e17;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    ll N,T,Q;
    cin>>N>>T>>Q;
    vector<pair<ll,ll> > info(N);
    vector<ll> mp(N,LongINF);
    vector<ll> vip(Q);
    rep(i,N){
        ll a,b;
        cin>>a>>b;
        info[i]=make_pair(a,b);
    }
    rep(i,Q){
        ll a;
        cin>>a;
        a--;
        vip[i]=a;
    }
    ll t;
    for(int i=0;i<N;i++){
        if(info[i].second==2){
            mp[i]=-1*LongINF;
        }
    }

    for(int i=0;i<N-1;i++){
        if(info[i].second==1&&info[i+1].second==2){
            t=(info[i+1].first+info[i].first)/2;
            for(int j=i;j>=0;j--){
            if(info[j].second==2)break;
                mp[j]=t;
            }
            for(int j=i+1;j<N;j++){
                if(info[j].second==1)break;
                mp[j]=t;
            }
        }
    }

    rep(i,Q){
        ll vh=info[vip[i]].first,vd=info[vip[i]].second;
        if(vd==1){
            if(vh+T<mp[vip[i]]){
                cout<<vh+T<<endl;
            }else{
                cout<<mp[vip[i]]<<endl;
            }
        }else{
            if(vh-T>mp[vip[i]]){
                cout<<vh-T<<endl;
            }else{
                cout<<mp[vip[i]]<<endl;
            }
        }
    }

    return 0;
}

//a=97,z=122