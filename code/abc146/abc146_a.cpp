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
    string a;
    cin>>a;
    if(a=="SUN")cout<<7<<endl;
    else if(a=="MON")cout<<6<<endl;
    else if(a=="TUE")cout<<5<<endl;
    else if(a=="WED")cout<<4<<endl;
    else if(a=="THU")cout<<3<<endl;
    else if(a=="FRI")cout<<2<<endl;
    else if(a=="SAT")cout<<1<<endl;

    return 0;
}

//a=97,z=122