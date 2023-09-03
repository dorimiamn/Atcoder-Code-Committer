//https://pyteyon.hatenablog.com/entry/2018/09/02/094228
//参考にさせて頂いた記事

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
    ll N,K,Co=0,Co2=0;
    cin>>N>>K;
    int HK=K/2;
    if(K%2==1){
        for(int i=1;i<=N;i++){
            if(i%K==0)Co++;
        }
        cout<<Co*Co*Co<<endl;
    }else{
        for(int i=1;i<=N;i++){
            if(i%K==0)Co++;
            if(i%K==HK)Co2++;
        }
        cout<<Co*Co*Co+Co2*Co2*Co2<<endl;
    }
    return 0;
}

//a=97,z=122