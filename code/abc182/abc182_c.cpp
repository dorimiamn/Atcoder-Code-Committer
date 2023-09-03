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

int dfs(int k,int sum,vi t){
    int ans=INF,l=t.size();
    if(sum%3==0||l==0){
        return k;
    }
    rep(i,l){
        if(t[i]%3!=0){
            vi u;
            rep(j,l){
                if(i==j)continue;
                u.push_back(t[j]);
            }
            ans=min(ans,dfs(k+1,sum-t[i],u));
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int l=s.length(),ans=INF,sum=0;
    vi arr(l);
    rep(i,l){
        arr[i]=s[i]-'0';
        sum+=arr[i];
        //cout<<arr[i]<<" ";
    }
    if(sum%3==0){
        cout<<0<<endl;
        return 0;
    }
    rep(i,l){
        if(arr[i]%3!=0){
            vi arr1;
            rep(j,l){
                if(i==j)continue;
                arr1.push_back(arr[j]);
            }
            ans=min(ans,dfs(1,sum-arr[i],arr1));
        }
    }
    if(ans==l)ans=-1;
    cout<<ans<<endl;
    return 0;
}

//a=97,z=122