//  https://www.ioi-jp.org/joi/2018/2019-yo/2019-yo-t4-sample.cpp
//　フラグ管理の大切さを学んだ。
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const ll INF=1e13+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,bh=0,h,p,Co=0;
    cin>>N;
    vector<ll> A(N);
    vector<bool> sea(N+3);
    sea[0]=sea[N+1]=true;//trueは海を表す。
    map<int,int> answers;
    rep(i,N)cin>>A[i];
    vector<pair<int ,int> > B(N);
    rep(i,N){
        B[i]=make_pair(A[i],i+1);
    }
    sort(B.begin(),B.end());
    bool ok=false;
    for(int i=0;i<N;i++){
        if(A[i]>0&&!ok){
            ok=true;
            Co++;
        }else if(A[i]==0){
            ok=false;
            sea[i+1]=true;
        }
    }

    answers[0]=Co;
    for(auto x:B){
        h=x.first,p=x.second;
        sea[p]=true;
        if(h==0)continue;
        if(sea[p-1]&&sea[p+1]){
            Co--;
        }else if(!sea[p-1]&&!sea[p+1]){
            Co++;
        }
        answers[h]=Co;
    }
    int ANS=0;
    for(auto x:answers){
        ANS=max(ANS,x.second);
    }
    cout<<ANS<<endl;
    return 0;
}

//a=97,z=122