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

//データ格納の仕方がおかしい


int main(){
    int N,ANS=0;
    cin>>N;
    vector<vector<pair<int,int> > > XY(N,vector<pair<int,int> >());
    vector<int> A(N);
    rep(i,N){
        cin>>A[i];
        rep(j,A[i]){
            int a,b;
            cin>>a>>b;
            a--;
            XY[i].pb(make_pair(a,b));
        }
    }

    for(int bit=0;bit<(1<<N);bit++){
        bool ok=true;
        int Co=0;

        vector<int> honest(N,0);

        rep(i,N){
            if(bit&(1<<i)){
                honest[i]=1;
                Co++;
            }
        }
        rep(i,N){
            if(honest[i]){
                rep(j,A[i]){//証言
                    int a=XY[i][j].first,b=XY[i][j].second;
                    if(honest[a]!=b)ok=false;
                    if(honest[a]==1){
                        rep(k,A[a]){
                            int c=XY[a][k].first,d=XY[a][k].second;
                            if(honest[c]!=d)ok=false;
                            if(!ok)break;
                        }
                        if(!ok)break;
                    }
                }
                if(!ok)break;
            }
        }
        if(ok)ANS=max(ANS,Co);
    }
    cout<<ANS<<endl;

    return 0;
}

//a=97,z=122