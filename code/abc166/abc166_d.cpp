#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF = 1e13 + 7;
const ll INF = 3981;
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
} //queueの中身の型は適時変更を忘れない

using vi = vector<int>;
using vii = vector<vi>;

#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) REP(i, 0, n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(), (a).end()
#define decimal(x) fixed << setprecision(x)

/*
a^n-b^n=(a-b)...より、
*/

int main()
{
    ll x;
    cin >> x;
    for (ll a = -INF; a < INF + 1; a++)
    {
        ll c;
        for (ll b = -INF; b < INF + 1; b++)
        {
            c=-b;
            if (a - b == 0)
                continue;
            if (x == (a - b) * (a * a * a * a + a * a * a * b + a * a * b * b + a * b * b * b + b * b * b * b))
            {
                cout << a << " " << b << endl;
                return 0;
            }
            else if (x == (a - c) * (a * a * a * a + a * a * a * c + a * a * c * c + a * c * c * c + c * c * c * c))
            {
                cout << a << " " << c << endl;
                return 0;
            }
        }
    }
    return 0;
}

//a=97,z=122