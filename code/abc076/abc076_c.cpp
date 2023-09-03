//https://qiita.com/hkrutknouch/items/910c371e2828787e4292
//https://ikatakos.com/pot/programming_algorithm/contest_history/atcoder/2017/1028_abc076#c_-_dubious_document_2
//参考にさせて頂いた解説

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
    string I,T;
    string NA="UNRESTORABLE";
    cin>>I>>T;
    int L=T.length();
    int Sec=I.length()-L+1;
    vector<string> S;
    for(int i=0;i<Sec;i++){
        string Cut=I.substr(i,L);
        bool ok=true;
        for(int j=0;j<L;j++){
            if(Cut[j]!=T[j]&&Cut[j]!='?'){
                ok=false;
                break;
            }
        }
        if(ok){
            string A=I;
            A.replace(i,L,T);
            S.push_back(A);
        }
    }
    if(S.size()==0){
        cout<<NA<<endl;
        return 0;
    }
    sort(S.begin(),S.end());
    I=S[0];
    rep(i,I.length()){
        if(I[i]=='?')I[i]='a';
    }
    cout<<I<<endl;
    return 0;
}

//a=97,z=122