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
    vector<pair<int,int> >A(N),B(N);
    rep(i,N){
        int a,b;
        cin>>a>>b;
        B[i]=make_pair(a,b);
    }
    rep(i,N){
        int a,b;
        cin>>a>>b;
        A[i]=make_pair(a,b);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int Co=0;

    for(int i=0;i<N;i++){
        int x=A[i].first,y=A[i].second;
        int by=INF,it;
        for(int j=0;j<N;j++){//青より左にある赤で、一番高いものを探索
            if(x<=B[j].first)break;
            if(y>B[j].second&&(by==INF||by<B[j].second))by=B[j].second,it=j;
        }
        if(by!=INF){
            Co++;
            B[it].second=INF;
        }
    }

    cout<<Co<<endl;

    return 0;
}

//赤<青の時であり、
/*
一番左にある、青と、そこから左にある中で、一番上のものをとればよい。
青、赤をxを基準としてソート。
解説より
*/

//a=97,z=122