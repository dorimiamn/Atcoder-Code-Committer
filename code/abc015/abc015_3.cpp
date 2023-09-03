#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()

int main(){
    int N,K;
    cin>>N>>K;
    vector<vector<int>> T(N,vector<int> (K,0));
    rep(i,N){
        rep(j,K)cin>>T[i][j];
    }

    queue<pair<int,int>> que;
    if(N==1){
        rep(j,K)if(T[0][j]==0){
            cout<<"Found"<<endl;
            return 0;
        }
        cout<<"Nothing"<<endl;
        return 0;
    }
    rep(i,K)que.push(make_pair(0,T[0][i]));
    

    while(!que.empty()){
        int x=que.front().second;
        int times=que.front().first+1;
        que.pop();

        for(auto y:T[times]){
            if(times+1==N&&(x^y)==0){
                cout<<"Found"<<endl;
                return 0;
            }
            if(times+1==N)continue;
            que.push(make_pair(times,x^y));
        }
    }

    cout<<"Nothing"<<endl;

    return 0;
}

//a=97,z=122

/**
 * 
 * 
 * 
5 5
0 1 2 5 1
1 2 4 9 0
0 2 5 1 2
1 5 9 2 0
127 0 0 0 0
*/