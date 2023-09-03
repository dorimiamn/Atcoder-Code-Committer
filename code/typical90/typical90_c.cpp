#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int n,ans=0;
    cin>>n;
    vii roads(n,vi(0));
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        roads[a].pb(b);
        roads[b].pb(a);
    }

    vector<bool> visited1(n,false);
    rep(i,n){
        if(visited1[i])continue;
        int point=0;
        queue<pair<int,int> > que;
        que.push({i,0});
        while(!que.empty()){
            int now=que.front().first,cnt=que.front().second;
            que.pop();
            visited1[now]=true;
            for(auto x:roads[now]){
                if(visited1[x])continue;
                que.push({x,cnt+1});
            }
            if(ans<cnt+1){
                point=now;
                chmax(ans,cnt);
            }
        }
        que.push({point,0});
        vector<bool> visited2(n,false);
        while(!que.empty()){
            int now=que.front().first,cnt=que.front().second;
            que.pop();
            visited2[now]=true;
            for(auto x:roads[now]){
                if(visited2[x])continue;
                que.push({x,cnt+1});
            }
            chmax(ans,cnt);
        }
    }
    cout<<ans+1<<endl;
    return 0;
}
/*
1番長い道＋1?
道が一つだけを選べばいいんじゃないかな。
添字間違いで遠回りしかけた……

4
1 2
3 4
1 3
は 2 1 3 4で4が答えとなるんじゃ？

私のやり方では抜けがあった
例えば
7
1 2
2 3
3 4
4 5
3 6
3 7
の時
6,7から探索を始めると最大値は4となるが、1から始めると5となる

*/