//http://drken1215.hatenablog.com/entry/2018/08/13/123600
//参考にさせて頂いた解説

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
#define pb push_back

int main(){
    int N;
    cin>>N;
    string A;
    if(N==0)A="0";
    while(N!=0){
        int r=N%2;
        if(r<0)r+=2;//rのあまりは0,1なので2を足すことで正の1にできる
        //二進数への変換と同じことをするが、-2なので一部手順を変える必要がある？
        //-9を例に考えると、(-9-1)/(-2)=5,(5-1)/(-2)=-2,(-2-0)/(-2)=1,(1-1)/(-2)=0;
        //二進数の変換で必要なのは余りなので、1,1,0,1となる、これを反転させたのが答え。反転させる行為は自明として、
        //なぜ-rをするのか。二進法変換のコードを書くのと同じことで、/2をするために、数を整える必要があるため、

        //Nから余りを取り除いて -2 で割る。
        N=(N-r)/(-2);

        //答えに追加
        A+=(char)('0'+r);//stringに数を付け加えるにはこうしないと正常に行われない……
    }
    reverse(A.begin(),A.end());
    cout<<A<<endl;

    return 0;
}

//a=97,z=122