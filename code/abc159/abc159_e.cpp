/*
https://drken1215.hatenablog.com/entry/2020/03/23/002300
https://www.hamayanhamayan.com/entry/2020/03/22/231629
勉強させていただいた記事
*/

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
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)


int main(){
    int H,W,K,res=1<<29;
    cin>>H>>W>>K;
    vector<string> S(H);
    rep(i,H)cin>>S[i];
    for(int bit=0;bit<(1<<(H-1));bit++){
        bool gok=true;
        int N=0;
        vi ord(H,0);//横線において、区切る物をcoする累積和を行うことで、面積分けをしている。
        rep(i,H-1){
            if(!(bit&(1<<i)))ord[i+1]=ord[i];
            else ord[i+1]=ord[i]+1,++N;
            //cout<<"ord:"<<ord[i+1]<<" N:"<<N<<" ";
        }
        //cout<<endl;
        int add=0;
        vi nums(N+1,0);
        rep(i,W){//縦ごとのカウント
            vi one(N+1,0);
            bool ok=true;
            rep(j,H){
                //ord[j]とすることで、横線の単位では異なっていても、同じエリアということでカウントできる。
                one[ord[j]]+=S[j][i]-'0';
                nums[ord[j]]+=S[j][i]-'0';
                if(one[ord[j]]>K)gok=false;
                if(nums[ord[j]]>K)ok=false;
                //cout<<"j:"<<j<<" one:"<<one[ord[j]]<<" nums:"<<nums[ord[j]]<<" ";
            }/*
            cout<<i<<endl;
            cout<<"one :";
            for(auto x:one)cout<<x<<" ";
            cout<<endl<<"nums:";
            for(auto x:nums)cout<<x<<" ";
            cout<<endl;
            */
            //oneでは縦列のみのカウントだが、numsでは、Kを超えるまでのカウントを保持している。
            //そのため、K>one[ord[j]] の時nums=oneでリセットしている。
            if(!ok)++add,nums=one;
        }
        if(gok)chmin(res,N+add);
    }

    cout<<res<<endl;

    return 0;
}

//a=97,z=122