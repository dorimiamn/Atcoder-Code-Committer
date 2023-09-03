//https://atcoder.jp/contests/abc135/submissions/8198071
//何度も提出しても通らなかったため、原文ママで提出させていただきました……
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long
#define INF 10e9
#define PI 3.14159265359
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll int, ll int>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

template<class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int N;
int a[110000];
int b[110000]; 
ll int ans;

int main () {
  cin >> N;

  Rep(i, N+1) cin >> a[i];
  Rep(i, N) cin >> b[i];

  ans = 0;

  Rep(i, N) {
    if (a[i] >= b[i]) {
      ans += b[i];
    } else {
      int diff = b[i] - a[i];
      
      if (diff > a[i+1]) {
        ans += a[i] + a[i+1];
        a[i+1] = 0;
      } else {
        ans += a[i] + diff;
        a[i+1] -= diff;
      }
    }
  }

  printf("%lld\n",ans);
}
