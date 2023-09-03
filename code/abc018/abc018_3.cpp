/*
公式解説より実装
いろいろバグらせて大変だった……
こういう問題に置いて端は例外として飛ばす時のデクリメント、インクリメントが
ごっちゃになりやすいなと感じた。。
*/
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
    int R,C,K,ans=0;
    cin>>R>>C>>K;
    vector<string>S(R);
    int check[R][C]={0},recheck[R][C]={0};
    rep(i,R){
        cin>>S[i];
        rep(j,C){
            if(i==0)check[i][j]=(S[i][j]=='o');
            else{
                if(S[i][j]=='o')check[i][j]=check[i-1][j]+1;
            }
        }
    }
    for(int i=R-1;i>=0;i--){
        rep(j,C){
            if(i==R-1){
                if(S[i][j]=='o')recheck[i][j]=1;
            }else{
                if(S[i][j]=='o')recheck[i][j]=recheck[i+1][j]+1;
            }
        }
    }
    //確認用
    /*
    rep(i,R){
        rep(j,C){
            cout<<check[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    rep(i,R){
        rep(j,C)cout<<recheck[i][j]<<" ";
        cout<<endl;
    }
    */
    rep(i,R){
        rep(j,C){
            //探査したいマスが端だった時例外として飛ばす
            if((i-K+1<0)||(j-K+1<0)||(i+K-1>=R)||(j+K-1>=C))continue;
            //cout<<i<<" "<<j<<endl;
            bool ok=true;
            rep(l,K){
                //探査しているマスから離れていくごとに上下に必要なoマスは減るのでK-l
                if(check[i][j+l]<K-l||recheck[i][j+l]<K-l)ok=false;
                if(check[i][j-l]<K-l||recheck[i][j-l]<K-l)ok=false;
            }
            if(ok){
                ans++;
                //cout<<i<<" "<<j<<endl;
            }
       }
    }

    cout<<ans<<endl;
    return 0;
}

//a=97,z=122