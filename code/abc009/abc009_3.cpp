/*
http://hidollara.hatenablog.com/entry/2017/07/28/194620
https://abc009.contest.atcoder.jp/submissions/1456758
勉強させていただいた提出,及び記事
*/

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

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()

int main(){
    int N,K;
    cin>>N>>K;
    string S;
    cin>>S;
    vector<int> abc(26,0);
    rep(i,N){
        abc[S[i]-'a']++;
    }
    string T;
    rep(i,N){
        rep(j,26)if(abc[j]){
            int diff=0;
            vi tmp=abc;tmp[j]--;
            REP(k,i+1,N){//iをjと決めた時、それ以降の文字列でdiffを最小にできる物を探す
                if(tmp[S[k]-'a']==0)diff++;//S内の文字が使えなかったら。
                else tmp[S[k]-'a']--;
            }
            //S[i]と探索しているalphabetが違かったらK-1,
            //iについて決めている最中なのでiと同じであればdiffはそのまま、出なければ、diffを加算
            //diffが小さければ、Tに足していく
            if(diff<=K-(S[i]!=char('a'+j)?1:0)){
                T+='a'+j;
                abc[j]--;
                if(S[i]!='a'+j)K--;
                break;
            }
        }
    }
    cout<<T<<endl;
    return 0;
}

//a=97,z=122