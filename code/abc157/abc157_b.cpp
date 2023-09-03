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
    int A[3][3];
    rep(i,3){
        rep(j,3){
            cin>>A[i][j];
        }
    }
    int N;
    cin>>N;
    vector<int> B(N);
    rep(i,N)cin>>B[i];
    bool ss[3][3]={false};
    for(auto x:B){
        rep(i,3){
            rep(j,3){
                if(A[i][j]==x)ss[i][j]=true;
            }
        }
    }

    if((ss[0][0]&&ss[1][1]&&ss[2][2])||(ss[2][0]&&ss[1][1]&&ss[0][2])){
        cout<<"Yes"<<endl;
        return 0;
    }
    rep(i,3){
        bool c=true;
        rep(j,3){
            if(!ss[i][j])c=false;
        }
        if(c){
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    rep(i,3){
        rep(j,3){
        bool c=true;
        rep(j,3){
            if(!ss[j][i])c=false;
        }
        if(c){
            cout<<"Yes"<<endl;
            return 0;
        } 
        }
    }

    cout<<"No"<<endl;

    return 0;
}

//a=97,z=122
/*
  0 1 2
0  
1
2



*/