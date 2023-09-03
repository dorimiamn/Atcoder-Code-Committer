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
    int N;
    cin>>N;
    vector<int> A(N);
    vector<stack<int> > que(N);
    rep(i,N){
        cin>>A[i];
        que[i].push(INF);
    }
    rep(i,N){
        rep(j,N){
            if(A[i]<=que[j].top()){
                que[j].push(A[i]);
                break;
            }
        }
    }
    int ANS=0;
    rep(i,N){
        if(que[i].top()!=INF)ANS++;
        else break;
    }
    cout<<ANS<<endl;
    return 0;
}

//a=97,z=122