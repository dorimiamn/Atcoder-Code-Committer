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
    int sx,sy,gx,gy;
    cin>>sx>>sy>>gx>>gy;
    int lx=gx-sx,ly=gy-sy;

    cout<<string(ly,'U')<<string(lx,'R');
    cout<<string(ly,'D')<<string(lx,'L');
    cout<<'L'<<string(ly+1,'U')<<string(lx+1,'R')<<'D';
    cout<<'R'<<string(ly+1,'D')<<string(lx+1,'L')<<'U'<<endl;//外側を回っているので移動距離は１伸びる……！

    return 0;
}

//a=97,z=122