//https://ferin-tech.hatenablog.com/entry/2017/11/13/232545
//勉強にさせて頂いた記事
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back

//桁ごとに一番近いものを選ぶ？
//左の桁から埋めていく？？
//左の桁から選択するものを決めたとして、右でその洗濯の中から最善を選ぶ必要がある。
//決定の仕方がわからない

//桁DPの時はllを基本にしとく
//制約もちゃんと見る


//bit演算要精進
ll dp[30][1LL<<10][4];
//dpテーブルの鍵は桁、使った数の集合、大小フラグである
//なぜ使った数の集合で良い？
//ループの構造的に1~9を回せるため？
//値の中身はできた数

int main()
{
    ll N;
    int K;
    cin >> N >> K;

    memset(dp, -1, sizeof(dp));

    dp[0][0][0] = 0;
    string A=to_string(N);
    int L = A.length();

    dp[0][0][0] = 0;
    //数値の大小フラグを用いて、DPしている
    //大小を用いることで、整数の差をより少なくできる
    //bitを用いることで、使った数字を効率よく管理できる！！！！
    //1<<10というのも、10シフトの意味である、はずなので、これが表すのは、bitの各位が0~9対応していること
    //配列サイズもそれにあわせて用意する必要があった！
    rep(i, L)
    {
        rep(j, 1 << 10) rep(k, 3)
        {
            if (dp[i][j][k] == -1)
                continue;
            rep(d, 10)
            {
                ll tmp = j;
                if (!(j & (1 << d)))//bitフラグ判定
                    tmp |= 1 << d;//d番にフラグ立て
                // tmpで桁が1の中からどれを選ぶのが最善か？
                if (k == 0)//大小フラグなので、決定していないときの処理
                {
                    if (tmp & 1 << (A[i] - '0'))//判定
                        dp[i + 1][tmp][0] = dp[i][j][k] * 10 + A[i] - '0';
                    rep(l, A[i] - '0') if (tmp & 1 << l)//A[i]-'0'で桁の数字を回している
                    {
                        chmax(dp[i + 1][tmp][1], dp[i][j][k] * 10 + l);
                    }
                    for (int l = 9; l > A[i] - '0'; --l)
                        if (tmp & 1 << l)
                        {
                            if (dp[i + 1][tmp][2] == -1)
                                dp[i + 1][tmp][2] = dp[i][j][k] * 10 + l;
                            chmin(dp[i + 1][tmp][2], dp[i][j][k] * 10 + l);
                        }
                        //未確定なので、二回回して、大小をつけている。
                }
                // 小さいのが確定
                else if (k == 1)//確定しているので一回だけ
                {
                    rep(l, 10) if (tmp & 1 << l)
                    {
                        chmax(dp[i + 1][tmp][1], dp[i][j][k] * 10 + l);
                    }
                }
                // 大きいのが確定
                else if (k == 2)//確定しているので一回
                {
                    for (int l = 9; l >= 0; --l)
                    {
                        if (tmp & 1 << l)
                        {
                            if (dp[i + 1][tmp][2] == -1)
                                dp[i + 1][tmp][2] = dp[i][j][k] * 10 + l;
                            chmin(dp[i + 1][tmp][2], dp[i][j][k] * 10 + l);
                        }
                    }
                }
            }
        }
    }

    ll ans = LongINF;
    rep(i, 1 << 10) rep(k, 3)
    {
        int cnt = 0;
        rep(j, 10) if (i & (1 << j)) cnt++;
        if (cnt <= K)
        {
            if (dp[L][i][k] != -1 && abs(ans - N) > abs(dp[L][i][k] - N))
            {
                ans = dp[L][i][k];
            }
        }
    }
    ll r = 0;
    rep(i, L - 1) r *= 10, r += 9;
    cout << min(abs(N - ans), abs(N - r)) << endl;

    return 0;
}
//stoiには注意

//a=97,z=122