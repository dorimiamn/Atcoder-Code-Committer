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
    int N,A;
    ll ANS=1;
    cin>>N;
    bool c=(N%2==0);
    bool X=false;
    map<int,int> mp;
    rep(i,N){
        cin>>A;
        if(c){
            if(A%2==0)X=true;
        }else{
            if(A%2==1)X=true;
        }
        mp[A]++;
        if(mp[A]>2)X=true;
        if(X){
            cout<<0<<endl;
            return 0;
        }
    }
    
    for(auto x:mp){
        if(x.first==0){
            if(x.second!=1)X=true;
        }else if(x.second!=2){
            X=true;
        }else{
            ANS*=2;
            ANS%=INF;
        }
        if(X){
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<ANS<<endl;

    return 0;
}

//a=97,z=122