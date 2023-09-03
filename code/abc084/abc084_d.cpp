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
    int MAX=101000;
    vector<int> Prime(MAX,1);
    Prime[1]=0,Prime[0]=0;
    //素数を求める。
    for(int i=2;i<MAX;i++){
        for(int j=i*2;j<MAX;j+=i){
            Prime[j]=0;
        }
    }
    vector<int> A(MAX,0);
    for(int i=3;i<MAX;i++){
        if(i%2==0)A[i]=A[i-1];
        if(Prime[i]&&Prime[(i+1)/2])A[i]=A[i-1]+1;
        else A[i]=A[i-1];
    }
    int Q;
    cin>>Q;
    rep(i,Q){
        int a,b;
        cin>>a>>b;
        cout<<A[b]-A[a-1]<<endl;
    }
    return 0;
}

//a=97,z=122