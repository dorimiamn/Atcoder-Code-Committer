/*
https://drken1215.hatenablog.com/entry/2020/03/08/020200
とても勉強させていただいた記事
*/

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

ll N;
int P;
string S;

//整数の性質大切

ll solve(){
    if(P==2||P==5){
        ll res=0;
        //[l,r)の区間なので、rがわかれば、そのrを持つlはrから左側全てなので、N-iを加算することでもとまる
        //また、P==2||P==5の時、合同式の性質に引っかかるので、例外。
        //また、解説中の2,5の時の条件を満たすものはS[r-1]%P==0を満たすときと言い換えられるため、以下の式となる
        rep(i,N)if((S[N-i-1]-'0')%P==0)res+=N-i;
        return res;
    }
    vector<ll> val(P,0);//持つのはP以下の数となるので
    ll tenfactor=1;//何桁目か
    ll cur=0;//余り
    val[cur]++;
    rep(i,N){
        //N-i-1で右側から探索
        //tenfactorを用いることで文字列を数値に変換するのを早く行っている？
        //文字列操作にかかる計算量は大きいと聞く
        //llの範囲超えないか？と思ったが、Pで余りを取っているのでその心配はない
        //curの状態が法Pで保たれているならば、桁を付けていく操作に問題はないんだろうか……？
        //合同式の性質的に、同じ法の中での足し算は大丈夫……だったからだと思う。
        cur=(cur+(S[N-i-1]-'0')*tenfactor)%P;
        tenfactor=(tenfactor*10)%P;
        val[cur]++;//余りの数をカウント
    }
    ll res=0;
    rep(p,P)res+=val[p]*(val[p]-1)/2;//同じ余りが条件を満たすので、余りの組み合わせを求める。
    return res;
}

int main(){
    cin>>N>>P>>S;

    cout<<solve()<<endl;

    return 0;
}

//a=97,z=122