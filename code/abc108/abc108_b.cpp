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
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int width=x2-x1;
    int height=y2-y1;
    if(width==0){
        if(height<0){
            height*=-1;
            cout<<x2+height<<endl<<y2<<endl<<x1+height<<endl<<y1<<endl;
        }else{
            cout<<x2-height<<endl<<y2<<endl<<x1-height<<endl<<y1<<endl;
        }
    }else if(height==0){
       if(width<0){
            width*=-1;
            cout<<x2<<endl<<y2-width<<endl<<x1<<endl<<y1-width<<endl;
        }else{
            cout<<x2<<endl<<y2-width<<endl<<x1<<endl<<y1-width<<endl;
        } 
    }else if(width>0&&height>0){
        cout<<x2-height<<endl<<y2+width<<endl<<x1-height<<endl<<y1+width<<endl;
    }else if(width>0&&height<0){
        height*=-1;
        cout<<x2+height<<endl<<y2+width<<endl<<x1+height<<endl<<y1+width<<endl;
    }else if(width<0&&height>0){
        width*=-1;
        cout<<x2-height<<endl<<y2-width<<endl<<x1-height<<endl<<y1-width<<endl;
    }else{
        height*=-1;
        width*=-1;
        cout<<x2+height<<endl<<y2-width<<endl<<x1+height<<endl<<y1-width<<endl;
    }
    return 0;
}

//a=97,z=122