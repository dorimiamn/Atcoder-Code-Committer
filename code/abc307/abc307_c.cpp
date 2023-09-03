//解説Submit
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

bool check(int x,int down,int up){
    if(down<=x&&x<up)return true;
    else return false;
}

int main()
{
    vi h(3), w(3);
    cin >> h[0] >> w[0];
    vector<string> a(h[0]);
    rep(i, h[0]) cin >> a[i];

    cin >> h[1] >> w[1];
    vector<string> b(h[1]);
    rep(i, h[1]) cin >> b[i];

    cin >> h[2] >> w[2];
    vector<string> c(h[2]);
    rep(i, h[2]) cin >> c[i];

    //基準点を決める
    REP(y1,-h[0]+1,h[2]){
        REP(x1,-w[0]+1,w[2]){
            REP(y2,-h[1]+1,h[2]){
                REP(x2,-w[1]+1,w[2]){
                    //問題文の条件を満たしているかを判定するには
                    //シートA、シートBの黒マスが全て含まれていること
                    //貼った後の黒マスがシートXと一致していることが必要。
                    //シートX'を作り、それがシートXと一致しているかをみる
                    string t="";
                    rep(i,w[2])t+='.';
                    vector<string> sheat(h[2],t);
                    
                    bool flag=true;

                    
                    rep(i,h[0]){
                        rep(j,w[0]){
                            if(a[i][j]=='#'){

                                if(check(i+y1,0,h[2])&&check(j+x1,0,w[2]))sheat[i+y1][j+x1]='#';
                                else {
                                    flag=false;
                                    break;
                                }
                            }
                        }
                        if(!flag)break;
                    }

                    rep(i,h[1]){
                        rep(j,w[1]){
                            if(b[i][j]=='#'){

                                if(check(i+y2,0,h[2])&&check(j+x2,0,w[2]))sheat[i+y2][j+x2]='#';
                                else {
                                    flag=false;
                                    break;
                                }
                            }
                        }
                        if(!flag)break;
                    }

                    rep(i,h[2]){
                        rep(j,w[2]){
                            if(c[i][j]!=sheat[i][j]){
                                flag=false;
                                break;
                            }
                        }
                        if(!flag)break;
                    }
                    if(flag){
                        cout<<"Yes"<<endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}

/*
条件を箇条書きで抜き出して考察した方が良さそう。
頭の中で完結させない。書き出して考える。
こういう重実装系は頭の中のふんわりとしたイメージで行くには難しい。
書き出して自分が描いている処理が何かをきちんと把握できるようにしておきたい。

AtCoderでは実装系の問題は珍しいので、他のサイトで練習するのもあり
ICPCだと重実装は普通に出るらしいし。

シートAとシートBの位置をそれぞれ動かしながらやってもいい？

シートを固定するとき
シートXは縦横最大10マス分でシートCは30マスほど見れば良いように見えるが、これは誤り。
シートAの右下とシートBの左上に#がある時を考えると、シートの基準点(シートの左上)の位置は18マスほど離れることになり、
シートCは50マス確保する必要がある。
https://prd-xxx.hateblo.jp/entry/2023/06/25/001304
*/

