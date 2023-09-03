// http://drken1215.hatenablog.com/entry/2019/02/24/224100
//参考にさせて頂いた解説

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)
int N,A,B,C,INF=1e9+7;
vector<int> L;


//recで帰ってくるのはMP量である。したがって、chmin内の処理で二本結合の処理を行える。
int rec(int i,int a,int b,int c){
    if(i==N){
        if(!a || !b|| !c)return INF;//true,falseは0,1と同義であるため、判定できる
        //a,b,c,は竹の長さであり、そのどれかが0である時、一つも竹を選んでいないということになる。
        return abs(a-A)+abs(b-B)+abs(c-C); //a,b,cをA,B,Cにするコスト。10とかは別計算？
    }
    //今ある竹を採用しない場合なので、変化なし。
    int res=rec(i+1,a,b,c);

    //A,B,Cを使う場合。
    //(a? 10:0)  ←条件演算子というらしい！！！
    //条件演算子の一つ目はboolへ変換されて、評価される。その結果がtrueであれば二つ目が、そうでなければ、三つ目を値として出す？
    // (a ? 10 : 0)などは、最初の一本は合体コストなし、二本目からはコスト10がかかることを意味している。
    chmin(res,rec(i+1,a+L[i],b,c)+(a ? 10 : 0));
    chmin(res,rec(i+1,a,b+L[i],c)+(b ? 10 : 0));
    chmin(res,rec(i+1,a,b,c+L[i])+(c ? 10 : 0));

    return res;
}

int main(){
    cin>>N>>A>>B>>C;
    L.resize(N);
    rep(i,N)cin>>L[i];

    //再帰
    cout<<rec(0,0,0,0)<<endl;
    return 0;
}

//a=97,z=122