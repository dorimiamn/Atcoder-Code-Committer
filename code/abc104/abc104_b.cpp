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

//a=97,z=122

int main(){
    string S;
    cin>>S;
    int last=S.length()-1,countC=0,Cnum;
    for(int i=2;i<last;i++){
        if(S[i]=='C')countC++,Cnum=i;
    }
    rep(i,last+1){
        if(i!=0&&i!=Cnum){
            if(int(S[i])<97){
                cout<<"WA"<<endl;
                return 0;
            }
        }
    }
    if(S[0]=='A'&&countC==1){
        cout<<"AC"<<endl;
    }else{
        cout<<"WA"<<endl;
    }
    return 0;
}