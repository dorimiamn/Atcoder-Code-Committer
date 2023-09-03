#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF = 10000000000000;
const int INF = 1000000007;
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
} // queueの中身の型は適時変更を忘れない

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

    int N;
    string S;

    cin>>N>>S;

    stack<int> st;

    vector<int>dist(N+1,0);



    rep(i,N){
        if(S[i]=='(')st.push(i);
        if(S[i]==')'){
            if(st.empty())continue;
            int s=st.top();
            st.pop();
            dist[s]+=1,dist[i+1]-=1;
        }
    }
    REP(i,1,N+1){
        dist[i]+=dist[i-1];
        if(!dist[i-1])cout<<S[i-1];
    }
    cout<<endl;

    return 0;
}

/*

(()()
2 3
10 10
1 1
３は数を数えれば良い
*/