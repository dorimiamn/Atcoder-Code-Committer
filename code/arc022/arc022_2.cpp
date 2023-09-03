/*
https://qiita.com/drken/items/ecd1a472d3a0e7db8dce#%E5%95%8F%E9%A1%8C-3abc-032-c-%E5%88%97
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
    vector<int> A(N);
    rep(i,N)cin>>A[i];

    int right=0,res=0;
    set<int> member;

    rep(left,N){
        while(!member.count(A[right])&&right<N){
            member.insert(A[right]);
            right++;
        }
        res=max(res,right-left);
        if(left==right)right++;
        else{
            member.erase(A[left]);
        }
    }

    cout<<res<<endl;

    return 0;
}

//a=97,z=122