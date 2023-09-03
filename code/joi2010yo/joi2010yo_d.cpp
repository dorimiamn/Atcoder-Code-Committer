#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll LongINF=1e13+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define rep(i,n) for(int i=0;i<(n);i++)
vector<string> card;
map<string,int> storeN;
int N,K;

int main(){
    cin>>N>>K;
    card.resize(N);
    rep(i,N)cin>>card[i];

    if(K==2){
        rep(i,N){
            rep(j,N){
                if(i==j)continue;
                string num=card[i]+card[j];
                storeN[num]=1;
            }
        }
    }else if(K==3){
        rep(i,N){
            rep(j,N){
                rep(k,N){
                    if(i==j||j==k||i==k)continue;
                    string num=card[i]+card[j]+card[k];
                    storeN[num]=1;
                }
            }
        }
    }else if(K==4){
        rep(i,N){
            rep(j,N){
                rep(k,N){
                    rep(l,N){
                        if(i==j||j==k||k==l||i==k||i==l||j==l)continue;
                        string num=card[i]+card[j]+card[k]+card[l];
                        storeN[num]=1;
                    }
                }
            }
        }
    }
    cout<<storeN.size()<<endl;
    return 0;
}

//a=97,z=122