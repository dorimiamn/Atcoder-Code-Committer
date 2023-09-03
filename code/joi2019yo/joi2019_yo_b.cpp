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
vector<int> mas(2040,0);
vector<int> A(101,0);

int main(){
    int N,M;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A[i];
        mas[A[i] ]=1;
    }
    cin>>M;
    rep(i,M){
        int b;
        cin>>b;
        if(mas[A[b]+1]==0&&A[b]!=2019){
            mas[A[b] ]=0;
            mas[A[b]+1]=1;
            A[b]++;
        }
    }
    int Co=0;
    for(int i=1;i<=2019;i++){
        if(mas[i]==1){
            cout<<i<<endl;
            Co++;
            if(Co==N)return 0;
        }
    }
    return 0;
}

//a=97,z=122