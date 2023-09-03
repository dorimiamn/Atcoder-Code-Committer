//https://qiita.com/drken/items/56a6b68edef8fc605821#%E5%95%8F%E9%A1%8C-3-atcoder-abc-122-c---get-ac
//参考にさせて頂いている記事

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
    vector<vector<int> > D(N,vector<int> (N)),S(N+1,vector<int>(N+1,0));
    rep(i,N){
        rep(j,N)cin>>D[i][j];
    }
    //累積和
    rep(i,N){
        rep(j,N){
            S[i+1][j+1]=S[i][j+1]+S[i+1][j]-S[i][j]+D[i][j];
        }
    }

    vector<int> val(N*N+1,0);
    for(int x1=0;x1<N;x1++){
        for(int x2=x1+1;x2<=N;x2++){
            for(int y1=0;y1<N;y1++){
                for(int y2=y1+1;y2<=N;y2++){
                    int area=(x2-x1)*(y2-y1);
                    int sum=S[x2][y2]-S[x2][y1]-S[x1][y2]+S[x1][y1];
                    val[area]=max(sum,val[area]);
                }
            }
        }
    }

    //v以下であり、「v」の時ではない。
    for(int v=0;v<N*N;v++)val[v+1]=max(val[v+1],val[v]);//以下なので、それよりも前に大きな値がないかを更新

    int Q;
    cin>>Q;
    rep(i,Q){
        int a;
        cin>>a;
        cout<<val[a]<<endl;
    }

    return 0;
}

//a=97,z=122