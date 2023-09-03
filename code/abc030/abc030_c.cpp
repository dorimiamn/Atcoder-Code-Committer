//http://mmxsrup.hatenablog.com/entry/2016/09/22/155347
//勉強させていただいた記事

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

bool isOK(int index,int key,vector<int> a){
    if(a[index]>=key)return true;
    else return false;
}

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template <class T,class Y> T BS(T key,Y arr){
    T left=-1;
    T right=(T)arr.size();
    while(right-left>1){
        T mid=left+(right-left)/2;
        
        if(isOK(mid,key,arr))right=mid;
        else left=mid;
    }

    return right;
}

void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()

int main(){
    int N,M,X,Y;
    cin>>N>>M>>X>>Y;
    vector<int> A(N),B(M);
    rep(i,N)cin>>A[i];
    rep(i,M)cin>>B[i];

    int T=0,P=0,C=0;
    while(1){
        if(T){
            auto it=lower_bound(ALL(B),P);
            if(it==B.end())break;
            P=*it+Y;
            C++;
            T=0;
        }else{
            auto it=lower_bound(ALL(A),P);
            if(it==A.end())break;
            P=*it+X;
            C++;
            T=1;
        }
    }
    cout<<C/2<<endl;
    return 0;
}

//a=97,z=122

