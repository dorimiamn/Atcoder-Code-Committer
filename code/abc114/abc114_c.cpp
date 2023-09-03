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
int N;
vector<string> Key(3);

ll DFS(string S){
    ll C=stoll(S);
    if(C==0)S="";
    if(C>N)return 0;
    ll ret=0;
    if(S.find("3")!=-1&&S.find("5")!=-1&&S.find("7")!=-1){
        ret=1;
    }

    for(int i=0;i<3;i++){
        ret+=DFS(S+Key[i]);
    }

    return ret;
}

int main(){
    cin>>N;
    Key[0]="3";
    Key[1]="5";
    Key[2]="7";
    cout<<DFS("0")<<endl;
    return 0;
}

//a=97,z=122