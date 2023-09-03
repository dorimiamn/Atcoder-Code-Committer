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

    ll H,W,ANS=INF;
    cin>>H>>W;
    if(H%3==0||W%3==0){
        cout<<0<<endl;
        return 0;
    }
    REP(h,1,H){
        ll Sa=h*W,Sb,Sc;
        ll bc=H-h;
        if(bc%2==0){
            Sc=Sb=bc/2*W;
        }else{
            Sb=(bc-(bc+1)/2)*W;
            Sc=(bc+1)/2*W;
        }
        ANS=min(ANS,max(Sa,max(Sb,Sc))-min(Sa,min(Sb,Sc)));
        ll w=W/2;
        Sb=(H-h)*w;Sc=(H-h)*(W-w);
        ANS=min(ANS,max(Sa,max(Sb,Sc))-min(Sa,min(Sb,Sc)));
    }
    REP(w,1,W){
        ll Sa=w*H,Sb,Sc;
        ll bc=W-w;
        if(bc%2==0){
            Sc=Sb=bc/2*H;
        }else{
            Sb=(bc-(bc+1)/2)*H;
            Sc=(bc+1)/2*H;
        }
        ANS=min(ANS,max(Sa,max(Sb,Sc))-min(Sa,min(Sb,Sc)));
        ll h=H/2;
        Sb=(W-w)*h;Sc=(W-w)*(H-h);
        ANS=min(ANS,max(Sa,max(Sb,Sc))-min(Sa,min(Sb,Sc)));
    }
    cout<<ANS<<endl;

    return 0;
}

//a=97,z=122