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
    string S,Sound="WBWBWWBWBWBWWBWBWWBWBWBW";
    vector<string> SA={"Do","Re","Mi","Fa","So","La","Si"};
    cin>>S;
    string A=S.substr(0,13);
    rep(i,12){
        bool ok=true;
        rep(j,12-i){
            if(Sound[i+j]!=S[j])ok=false;
        }
        if(ok){
            string ANS;
            if(i==0||i==1)ANS=SA[0];
            else if(i==2||i==3)ANS=SA[1];
            else if(i==4)ANS=SA[2];
            else if(i==5||i==6)ANS=SA[3];
            else if(i==7||i==8)ANS=SA[4];
            else if(i==9||i==10)ANS=SA[5];
            else ANS=SA[6];
            cout<<ANS<<endl;
            return 0;
        }
    }
    return 0;
}

//a=97,z=122