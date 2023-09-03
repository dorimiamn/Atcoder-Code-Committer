#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <cstring>
#include <iomanip>

using namespace std;

typedef long long ll;

const ll INF=1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string S;
    ll A,count=0,num=0,sum=0,check=0;
    cin>>S>>A;
    ll L=S.length();
    if(L==1){
        ll c,d;
        if(A%2==0){
            c=A/2;
            d=A-c;
        }else{
            d=floor(A/2);
            c=A-d;
        }
        cout<<d<<endl;
    return 0;
    }
    string O(S);
    if(S[0]==S[L-1]&&A!=1){//1回の時は末尾を考慮する必要はない
        rep(i,L-1){
            if(S[i]==S[i+1]){
            count++;
            S.erase(S.begin()+i+1);
            S.insert(S.begin()+i+1,num);
            num++;
            }
            if(O[i]==O[i+1])check++;
        }
        if(check==L-1){
            cout<<(L*A)/2<<endl;
            return 0;
        }
        sum+=count;
        if(S[L-1]==O[0]){
            O.erase(O.begin());//Sの長さを逐一取得するコードによって文字の挿入位置にズレが生じた？
            O.insert(O.begin(),num);
            count=1;
        }else count=0;
        rep(i,L-1){
            if(O[i]==O[i+1]){
                count++;
                O.erase(O.begin()+i+1);
                O.insert(O.begin()+i+1,num);
                num++;
            }
        }
        sum+=count*(A-1);
        cout<<sum<<endl;
        return 0;
    }
    rep(i,L-1){
        if(S[i]==S[i+1]){
            count++;
            S.erase(S.begin()+i+1);
            S.insert(S.begin()+i+1,num);
            num++;
        }
    }
    cout<<count*A<<endl;
    return 0;
}

//abaaa 2 のパターンで最適解ではない
//abaaa 3 の時一番目以降は同じ変更回数である。
//4以降はについても同様のことが言える。
//aaa 4 で最適解が出なかった。