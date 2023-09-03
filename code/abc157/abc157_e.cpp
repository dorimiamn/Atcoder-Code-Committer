/*
https://drken1215.hatenablog.com/entry/2020/03/03/071000
勉強させていただいた記事
*/

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
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)


int main(){
    int N,Q;
    string S;
    cin>>N>>S>>Q;
    vector<set<int>> pls(26,set<int>({INF}));
    rep(i,N)pls[S[i]-'a'].insert(i);
    rep(i,Q){
        int t;
        cin>>t;
        if(t==1){
            int i;
            char c;
            cin>>i>>c;
            i--;
            //文字列Sの更新処理
            auto p=S[i];
            S[i]=c;
            //変更前の文字から、その位置のフラグを消し、代わりに変更後の文字の位置にフラグをつける
            pls[p-'a'].erase(i);
            pls[c-'a'].insert(i);
        }else{
            int l,r;
            cin>>l>>r;
            //[l,r)のため、lだけデクリメント
            l--;
            int res=0;
            rep(c,26){
                if(pls[c].empty())continue;
                int lid=*pls[c].lower_bound(l);
                int rid=*pls[c].lower_bound(r);
                //[l,r)の範囲にあるならば、lidはridよりも小さくなるはず
                //ridはrではダメなんだろうか
                if(r>lid)++res;
            }
            cout<<res<<endl;
        }
    }

    return 0;
}

//a=97,z=122