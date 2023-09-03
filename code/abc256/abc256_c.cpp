#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF = 1e13 + 7;
const int INF = 1e9 + 7;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T, class Y>
T GCD(T a, Y b)
{
    if (a < b)
    {
        int c = a;
        a = b;
        b = c;
    }
    if (a % b == 0)
    {
        return b;
    }
    return GCD(b, a % b);
}
template <class T, class Y>
T LCM(T a, Y b) { return (a * b) / GCD(a, b); }
void clear(queue<pair<int, int>> &q)
{
    queue<pair<int, int>> empty;
    swap(q, empty);
} // Don't forget changing Type inside Queue

using vi = vector<ll>;
using vii = vector<vi>;

#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) REP(i, 0, n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(), (a).end()
#define decimal(x) fixed << setprecision(x)

int main()
{
    vi h(3), w(3);
    rep(i, 3) cin >> h[i];
    rep(i, 3) cin >> w[i];
    ll cnt = 0,n=31;
    REP(a1, 1, n){
        REP(a2,1,n){
            REP(b1,1,n){
                REP(b2,1,n){
                    bool ok=true;
                    vii arr={{a1,b1},{a2,b2},{}};
                    arr[2].pb(h[0]-a1-a2);
                    arr[2].pb(h[1]-b1-b2);
                    rep(i,3){
                        arr[i].pb(w[i]-arr[i][0]-arr[i][1]);
                    }
                    rep(i,3)rep(j,3){
                        if(arr[i][j]<=0)ok=false;
                    }
                    rep(i,3){
                        if(w[i]!=arr[i][0]+arr[i][1]+arr[i][2])ok=false;
                        if(h[i]!=arr[0][i]+arr[1][i]+arr[2][i])ok=false;
                    }
                    if(ok)cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
/*

*/