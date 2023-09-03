//http://drken1215.hatenablog.com/entry/2019/06/15/135300
//↑参考にさせて頂いた解説。




#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <cstring>
#include <iomanip>

using namespace std;

typedef long long ll;

const ll INF=1e13+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int N,M,k[20],s[20][20],p[20];
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            int a;
            cin>>a;
            a--;
            s[i][j]=a;
        }
    }
    ll res=0;
    for(int i=0;i<M;i++) cin>>p[i];
    for(int bit=0;bit<(1<<N);bit++){//bitで、押されたスイッチを全列挙
        bool check=true;//全部のライトがついている状態把握用？
        for(int i=0;i<M;i++){
            int  con=0;//カウントの初期化。
            for(int j=0;j<k[i];j++){
                if(bit&(1<<s[i][j]))con++;//スイッチが押された状態をカウント。
            }
            if(con%2!=p[i])check=false;//i番のライトがついているか。
        }
        if(check)++res;
    }
    cout<<res<<endl;
    return 0;
}

//a=97,z=122