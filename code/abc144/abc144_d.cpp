//解説AC

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

const long double PI=(acos(-1));//円周率
const long double EPS=0.0000000001;

long double f(long double a,long double b,long double theta){//theta角時の水筒内の体積を求める
    if(theta>PI/2.0-EPS){//PI/2は度数法で180度、thetaが180度を超えたら0return
        return 0.0;
    }
    long double ret;
    if(a*tan(theta)<=b){//a*tanθは、水筒の縦を表し、その長さがbを超えたら不可である
        ret=a*a*b-a*a*a*tan(theta)/2.0;//水の面積が長方形+三角形である時、三角形となっている空白を水筒の体積から差し引き水の体積を求めている
    }else{
        ret=b*b/tan(theta)*a/2.0;//水の部分が三角形onlyである時
    }
    return ret;
}

int main(){
    double a,b,x;
    cin>>a>>b>>x;
    long double ok=PI/2.0;
    long double ng=0.0;
    for(int _=1;_ <=100000;_++){
        long double mid=(ok+ng)/2.0;
        if(f(a,b,mid)<x)ok=mid;//体積より下回ったら、midは有効な数字のため、okに、もしダメだったらngに
        else ng=mid;//にぶたん
    }
    cout<<fixed<<setprecision(10)<<ok/PI*180<<endl;//180=πなので、πで割り、180をかけることで度数法に変換できる。
    
    return 0;
}

//a=97,z=122
/*

*/