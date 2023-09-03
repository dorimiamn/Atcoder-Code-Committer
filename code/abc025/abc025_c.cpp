//http://mio-hirona.hatenablog.com/entry/2016/05/07/010749
//勉強させていただいた記事
//Minimax法というものを使うらしい

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

typedef vector<vector<int>> mad;

int x[2][3],y[2][3];
map<mad,int> memo;

int calc_point(mad fld){
    int res=0;
    rep(i,2){
        rep(j,3){
            if(fld[i][j]==fld[i+1][j])
            res+=x[i][j];
        }
    }
    rep(i,3){
        rep(j,2){
            if(fld[i][j]==fld[i][j+1]){//タイプミス注意 "=" => "=="
                res+=y[i][j];
            }
        }
    }
    return res;
}

int dfs(mad fld,int turn){
    if(turn==9)return memo[fld]=calc_point(fld);
    if(memo.count(fld))return memo[fld];//すでに探索済みであるならば
    int tm=turn %2;//どちらの番か
    int res=tm ? INF :-1;
    rep(i,3)rep(j,3){
        if(fld[i][j]!=-1)continue;
        mad temp=fld;
        temp[i][j]=tm;//boardの状態更新
        if(tm){
            res=min(res,dfs(temp,turn+1));
        }
        else
            res=max(res,dfs(temp,turn+1));
    }
    return memo[fld]=res;
}

int main(){
    int sum=0;

    rep(i,2){
        rep(j,3){
            cin>>x[i][j];
            sum+=x[i][j];
        }
    }
    rep(i,3){
        rep(j,2){
            cin>>y[i][j];
            sum+=y[i][j];
        }
    }

    mad fld(3,vector<int> (3,-1));
    int ans=dfs(fld,0);

    cout<<ans<<endl<<sum-ans<<endl;

    return 0;
}

//a=97,z=122