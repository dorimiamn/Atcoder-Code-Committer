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

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse

int main(){
    int N;
    cin>>N;
    vector<double> MX(N),MN(N);
    rep(i,N)cin>>MX[i]>>MN[i];

    vector<int> Co(6,0);

    rep(i,N){
        if(MN[i]>=25.0){
            Co[3]++;
            if(MX[i]<30.0)Co[2]++;
            else if(MX[i]<35.0)Co[1]++;
            else Co[0]++;
        }
        else if(MX[i]<0.0) Co[5]++;
        else{
            if(MX[i]>=0.0&&MN[i]<0.0)Co[4]++;
            if(MX[i]<25.0)continue;
            else if(MX[i]<30.0)Co[2]++;
            else if(MX[i]<35.0)Co[1]++;
            else Co[0]++;
        }
    }

    rep(i,5)cout<<Co[i]<<" ";
    cout<<Co[5]<<endl;

    return 0;
}

//a=97,z=122