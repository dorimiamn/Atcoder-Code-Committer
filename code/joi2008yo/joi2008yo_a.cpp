#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll LongINF=1e13+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int A,ans=0;
    cin>>A;
    int N=1000-A;
    while(N>0){
        if(N>=500){
            ans++;
            N-=500;
        }
        else if(N>=100){
            ans++;
            N-=100;
        }
        else if(N>=50){
            ans++;
            N-=50;
        }
        else if(N>=10){
            ans++;
            N-=10;
        }
        else if(N>=5){
            ans++;
            N-=5;
        }
        else{
            ans+=N;
            N-=N;
        }
    }
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122