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

bool isTen(ll T){
    bool ok;
    if(T==0)return true;
    if(T%10==0)ok=isTen(T/10);
    else return false;

    return ok;
}

int main(){
    ll A,B,X,L=1;
    cin>>A>>B>>X;
    ll ANS=0,high=1000000001,low=0;

    if(A*1000000000+B*10<=X){
        cout<<1000000000<<endl;
        return 0;
    }

    while(high-low>1){
        ll mid=(high+low)/2;
        string S=to_string(mid);
        L=S.length();
        if((A*mid+B*L)<=X){
            low=mid;
        }else{
            high=mid;
        }
    }
    ANS=low;
    if(ANS>1e9)ANS=1e9;
    cout<<ANS<<endl;

    return 0;
}

//a=97,z=122