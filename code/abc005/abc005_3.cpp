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
    int T,N,M;
    cin>>T>>N;
    vector<int> A(N);
    vector<int> LA(N);
    rep(i,N){
        cin>>A[i];
        LA[i]=A[i]+T;
    }
    cin>>M;
    vector<int> B(M);
    rep(i,M){
        cin>>B[i];
    }
    rep(i,M){
        bool ok=false;
        for(int j=0;j<N;j++){
            if(A[j]<=B[i]&&B[i]<=LA[j]){
                A[j]=0,LA[j]=0;
                ok=true;
                break;
            }
        }
        if(!ok){
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    return 0;
}

//a=97,z=122