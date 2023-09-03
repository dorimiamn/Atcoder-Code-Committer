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
    int N,M;
    cin>>N>>M;
    bool ans=true;
    vector<string> P(10,"-1");
    string S;
    rep(i,N){
        S.pb('n');
    }
    rep(i,M){
        int s;
        string c;
        cin>>s>>c;
        s--;
        if((s==0&&N!=1&&c=="0")||(P[s]!=c&&P[s]!="-1")){
            ans=false;
        }
        P[s]=c;
        S.erase(S.begin()+s);
        S.insert(S.begin()+s,c[0]);
    }
    if(S[0]=='n'&&N!=1){
        S[0]='1';
    }
    rep(i,N){
        if(S[i]=='n')S[i]='0';
    }
    if(!ans){
        cout<<-1<<endl;
        return 0;
    }
    cout<<S<<endl;

    return 0;
}

//a=97,z=122