//http://gotto.hatenablog.com/entry/2012/12/23/194004
//勉強させて頂いた記事

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

//Mの倍数か否かはbooleanでもてばいい
//k%M==0なら1,
/*
ジグザグはどうしたものか？
条件として、増加したか、減少したかを記録する必要がある
dp[i][j][k] とdptableを定義して、iは桁数,jはN以下かどうか、
kは(k%M==0)&&前と違う値か、?bit……？
五つ添字を用意するというものだった……
柔軟さ大切
*/

//i桁目,a桁をMで割った余り,Xと同値であるか,aは増減どちらか,i桁目はcである


//dp[何文字目か][直前の数字][上下][自由に選べるか][余り]
//      n        be       ud        ok       md
//上:0 下:1
int m;
string s;
char z[555];
int dp[501][10][3][2][500];
int solve(int n, int be, int ud, int ok, int md)
{
    if (n == (int)s.size())//最後の桁にきたら
    {
        return md ? 0 : 1;
    }
    if (dp[n][be][ud][ok][md] >= 0)//すでにメモしていたら、
        return dp[n][be][ud][ok][md];

    int ret = 0;
    for (int i = 0; i <= ((ok) ? 9 : (int)(s[n] - '0')); i++)//okがtrue(自由に選べる)だったら9まで、そうでない時は桁限界に従う
    {
        if (ud == 0 && be <= i)//前も増加、対象直前の桁と対象桁から増加と判断できる時
            continue;
        if (ud == 1 && be >= i)//上記の減少 v
            continue;
        if (ud == 2 && be != 0 && be == i)//上下が決まってない時は、同値の時弾く
            continue;
        int u;//updownを決める
        if (ud == 2)//弾かれなかった時の処理
        {
            if (be == 0)
                u = 2;
            else if (be > i)
                u = 1;
            else
                u = 0;
        }
        else//増減が決まっていた時、
        {
            u = (ud + 1) % 2;
        }
        ret += solve(n + 1, i, u, (ok || i != (int)(s[n] - '0')) ? 1 : 0, (md * 10 + i) % m);
    }//ok||i!=(int)(s[n]-'0)は自由に決められるかどうか
    return dp[n][be][ud][ok][md] = ret % 10000;
}

int main(void)
{
    string c, d;
    cin >> c >> d >> m;
    for (int i = (int)c.size() - 1; i >= 0; i--)//Aを-1して答えを出すための処理f(B)-f(A-1)が答えであるため
    {
        if (c[i] == '0')
        {
            c[i] = '9';
        }
        else
        {
            c[i]--;
            break;
        }
    }
    s = c;
    memset(dp, -1, sizeof(dp));
    int a = solve(0, 0, 2, 0, 0);
    s = d;
    memset(dp, -1, sizeof(dp));
    int b = solve(0, 0, 2, 0, 0);
    cout << (b + 10000 - a) % 10000 << endl;
}

//a=97,z=122