//https://qiita.com/nomikura/items/0fab4cd893333c76981d
//勉強させていただいた記事

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
void clear(queue<pair<int, int>> &q)
{
    queue<pair<int, int>> empty;
    swap(q, empty);
} //queueの中身の型は適時変更を忘れない

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) REP(i, 0, n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(), (a).end()

int main()
{
    ll N, depth = 0;
    cin >> N;
    for (;; depth++)
    {
        if ((1LL << depth) <= N + 1 && 2 * (1LL << depth) - 1 >= N + 1)
        {
            break;
        }
    }
    ll x = 1, cnt = 0;
    while (1)
    {
        if (depth % 2)
        {
            x = x * 2;
            cnt++;
            if (x >= N + 1)
                break;
            x = x * 2 + 1;
            cnt++;
            if (x >= N + 1)
                break;
        }
        else
        {
            x = x * 2 + 1;
            cnt++;
            if (x >= N + 1)
                break;
            x = x * 2;
            cnt++;
            if (x >= N + 1)
                break;
        }
    }
    if (cnt & 1)
    {
        puts("Aoki");
    }
    else
    {
        puts("Takahashi");
    }
    return 0;
}

//a=97,z=122