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
    int N,ANS=0;
    cin>>N;
    vector<int> A(N);
    rep(i,N)cin>>A[i];
    map<int,int> O;
    map<int,int> E;
    for(int i=0;i<N;i++){
        if(i%2==0){
            E[A[i]]++;
        }else{
            O[A[i]]++;
        }
    }
    int numO=0,numE=0,CE=0,CO=0,Ose,Ese,CEse,COse;
    for(auto x:E){
        if(x.second>=CE){
            Ese=numE,CEse=CE;
            numE=x.first,CE=x.second;
        }
    }
    for(auto x:E){
        if(x.first!=numE&&CEse<x.second){
            Ese=x.first,CEse=x.second;
        }
    }
    for(auto x:O){
        if(x.second>=CO){
            Ose=numO,COse=CO;
            numO=x.first,CO=x.second;
        }
    }
    for(auto x:O){
        if(x.first!=numO&&COse<x.second){
            Ose=x.first,COse=x.second;
        }
    }
    N/=2;
    int a,b;
    if(numE==numO){
        a=N-CO+N-CEse;
        b=N-CE+N-COse;
        ANS=min(a,b);
    }else{
        ANS=N*2-(CO+CE);
    }
    cout<<ANS<<endl;
    return 0;
}

//a=97,z=122