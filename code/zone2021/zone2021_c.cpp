//解説AC
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
template<class T>T modpow(T a,T n,T mod){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //Don't forget changing Type inside Queue

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int N;
    cin>>N;

    vii A(N,vi(5,0));
    
    //範囲 for 分でアドレスを渡すと入力をより楽に描けるんだね。
    for(auto& a:A){
        for(int& i:a)cin>>i;
    }

    int ok=0,ng=INF;

    while(abs(ok-ng)>1){
        int md=(ok+ng)/2;
        //条件を単純化することで、計算量が大幅に減少
        set<int>s;
        for(auto& a:A){
            int bit=0;
            for(int i:a){
                bit<<=1;//bit を左シフト
                bit |= i>=md;//最下位 bit と論理和をとっている。
            }
            s.insert(bit);
        }
        bool isOK=false;
        for(int x: s)for(int y:s)for(int z:s){
            if((x|y|z)==31){
                isOK=true;
            }
        }
        if(isOK){
            ok=md;
        }else{
            ng=md;
        }
    }

    cout<<ok<<endl;

    return 0;
}
/*
三人チームを作る
総合力について全探索

O(N^3) で通るんじゃないか？

候補者の能力を全て見て、総合力が成立するかを判定する
計算量は O(N^2logN)

二分探索が成立するような線形性がなくないか？
どこに線形性を認めればいいんだろう。

2人まで選んだ時に、あと一人を選ぶとなったら、見れば良いのはその人の最大能力値だけで
各種能力値について見ていく必要はない?

bitで能力値が設定した値を超えているかで二分探索をすれば良いらしい。
bitを使うのかー！
こういう近い方は知っていたけどこうやって使うんだなぁ。
*/