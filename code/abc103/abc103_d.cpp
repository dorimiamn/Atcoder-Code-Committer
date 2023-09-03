/*
解説として拝見した記事
http://drken1215.hatenablog.com/entry/2018/07/21/224200
https://creep06.hatenablog.com/entry/2018/07/21/232414
http://tutuz.hateblo.jp/entry/2018/07/22/084326
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

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,M,ans=0;
    cin>>N>>M;
    vector<pair<int,int> > AB(M);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--,b--;
        AB[i]=make_pair(b,a);
    }
    sort(AB.begin(),AB.end());
    int end=0;//右端がどこかをメモる
    for(int i=0;i<M;i++){
        if(AB[i].second>=end)ans++,end=AB[i].first;
        //橋を無くす島の区間で右端の位置と、AB[i]のaを比較して、aが右端よりも左にあればそれは区間が被っていることと同義である。
        //そのため、end(橋をなくす区間の右端)よりも、右側に橋をなくさねばならない区間が来たら二つを同じ橋を無くして要望を満たすことはできない。
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122