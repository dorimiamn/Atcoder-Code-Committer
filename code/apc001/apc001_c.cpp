/*
https://ferin-tech.hatenablog.com/entry/2018/02/06/164811
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

int query(string s){
    if(s=="Male")return 1;
    if(s=="Female")return 2;
    return -1;
}

int main(){
    int N;
    cin>>N;
    int ok=N-1,ng=0;
    vi table(N,0);
    string s;
    cout<<ok<<endl;
    cin>>s;
    if(s=="Vacant"){
        return 0;
    }
    table[ok]=query(s);
    cout<<ng<<endl;
    cin>>s;
    if(s=="Vacant"){
        return 0;
    }
    table[ng]=query(s);

    while(ok-ng>0){
        // cout<<ok<<" "<<ng<<endl;
        int mid=(ok+ng)/2;
        cout<<mid<<endl;
        cin>>s;
        table[mid]=query(s);
        if(table[mid]==-1)return 0;
        if((ok-mid)%2){
            if(table[ok]==table[mid]){
                ng=mid;
                continue;
            }
        }
        if((ok-mid)%2==0){
            // cout<<ok<<":"<<mid<<endl;
            if(table[ok]!=table[mid]){
                ng=mid;
                continue;
            }
        }
        ok=mid;
    }
    return 0;
}

/*
二分探索問題なんだろうけど、最初をどうしたら良いかわからなかった。
空席がない区間とある区間で、探索範囲を空席がある区間にしたいのない区間を探索してしまうのではないかと悩んだ。
解説読んで書き出して理解できたので、ちゃんと書き出すことは大事…
11
MFMFVMFMFMF
性別以外にも条件が必要で、区間の偶奇が関与してくる。
横着せずに配列で管理したらよかったね。
*/