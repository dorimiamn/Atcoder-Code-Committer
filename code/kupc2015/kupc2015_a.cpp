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

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int T;
    cin>>T;
    queue<int> ANS;
    vector<string> S(T);
    string W="kyoto",E="tokyo",I="zzzzz";
    rep(i,T)cin>>S[i];
    rep(i,T){
        int ans=0;
        int L=S[i].length()-4;
        if(L<0)L=0;
        for(int j=0;j<L;j++){
            string C=S[i].substr(j,5);
            if(C==W||C==E){
                ans++;
                S[i].replace(j,5,I);
            }
        }
        ANS.push(ans);
    }
    rep(i,T){
        cout<<ANS.front()<<endl;
        ANS.pop();
    }
    return 0;
}

//a=97,z=122