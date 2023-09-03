//http://drken1215.hatenablog.com/entry/2018/11/06/120500
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
void clear(queue<int> &q){queue<int> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,l,si=-1;
    cin>>N;
    vector<pair<int,int> > XY(N);
    vector<int> H(N);
    rep(i,N){
        int a,b;
        cin>>a>>b>>H[i];
        XY[i]=make_pair(a,b);
        if(H[i]>0)si=i;
    }
    rep(i,101){
        rep(j,101){
            bool ok=true;
            int x=XY[si].first,y=XY[si].second;//任意のsiを使うのは、中心点は一意に求められるという題意から。
            int l=H[si]+abs(x-i)+abs(y-j);
            rep(k,N){           
                int x=XY[k].first,y=XY[k].second;
                if(H[k]>0&&l-H[k]!=abs(x-i)+abs(y-j))ok=false;//条件文の後ろの式二つは、問題文に記載されている式を変形させたもの？  
                if(H[k]==0 && l>abs(x-i)+abs(y-j))ok=false;
                }
            if(ok){
                cout<<i<<" "<<j<<" "<<l<<endl;
                return 0;
            }
        }
    }
    return 0;
}

//a=97,z=122