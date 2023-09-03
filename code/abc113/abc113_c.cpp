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
    int N,M;
    cin>>N>>M;
    string Zero="000000";
    vector<pair<int,pair<int,int> > > PY(M);
    vector<string> ANS(M);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        PY[i]=make_pair(a,make_pair(b,i));
    }
    sort(PY.begin(),PY.end());
    int c=PY[0].first,Co=0;
    rep(i,M){
        string A=Zero;
        string num=to_string(PY[i].first);
        A.replace(6-num.length(),num.length(),num);

        if(c!=PY[i].first){
            Co=1;
            c=PY[i].first;
        }
        else Co++;

        string B=Zero;
        num=to_string(Co);
        B.replace(6-num.length(),num.length(),num);
        A+=B;
        ANS[PY[i].second.second]=A;
    }
    rep(i,M)cout<<ANS[i]<<endl;
    return 0;
}

//a=97,z=122