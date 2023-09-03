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
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

vii calc_next(const string&S){
    int N=(int)S.size();

    vii res(N+1,vi(26,N));

    for(int i=N-1;i>=0;i--){
        res[i]=res[i+1];
        res[i][S[i]-'a']=i;
    }
    return res;
}

int main(){
    int N,K;
    string S;
    cin>>N>>K>>S;

    string res="";
    auto next=calc_next(S);

    int j=-1;
    rep(i,K){
        for(char c='a';c<='z';c++){
            int k=next[j+1][c-'a'];

            //N-kは文字列-j+1以降にある文字があるインデックス、K-iは指定された文字数-現在探索中の文字数
            //K-iは埋めるべき残りの文字数、N-kは文字列から取れる残りの文字数
            if(N-k>=K-i){
                res+=c;
                j=k;
                break;
            }
        }
    }
    cout<<res<<endl;

    return 0;
}
/*
https://drken1215.hatenablog.com/entry/2021/10/10/195200
見させていただいた解説

前計算はわかるんだけど、それをどう使ったらいいのかわからない。
a始まりじゃ規定の文字数を満たさないかったらbに行くけどその処理どうするの？
埋められない時は文字をどんどん下げていくことで対応可能なんだ。
元の文字列から取れる文字が残っているかも判定しているからできる。
*/