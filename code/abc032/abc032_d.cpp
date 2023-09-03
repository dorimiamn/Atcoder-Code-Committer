//https://misora192.hatenablog.com/entry/2019/01/23/082925
//https://atcoder.jp/contests/abc032/submissions/1381183
//勉強させて頂いた記事、提出


#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
 
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	int n, max_w;
	cin >> n >> max_w;
 
	ll v[n], w[n];
	rep(i, n) cin >> v[i] >> w[i];
 
	ll mv = 0;
	ll mw = 0;
	rep(i, n){//場合分けのために最大値を取り出し
		mv = max(mv, v[i]);
		mw = max(mw, w[i]);
	}
 
	if(n <= 30){//半分全列挙
		if(n == 1){
			cout << (w[0] <= max_w ? v[0] : 0) << endl;//もし一つしかなかったらその一つが容量ないかを判定して出力
			return 0;
		}
 
		int n1 = n / 2;//Nを二分して探索する準備
		int n2 = n - n1;
 
		vector<pll> v1, v2;
		for(ll i = 0; i < (1 << n1); i++){//bit全探索
			ll tv = 0;
			ll tw = 0;
			for(ll j = 0; j < n1; j++){
				if((i >> j) & 1){//bit全探索で要素列挙。その時の重みと価値を計算
					tv += v[j];
					tw += w[j];
				}
 
				if(tw <= max_w){
					// cout << "push1: " << tw << " " << tv << endl;
					v1.push_back((pll){tw, tv});//容量内ならメモ
				}
			}
		}
 
		for(ll i = 0; i < (1 << n2); i++){//上記と同様だが、残り半分についての処理
			ll tv = 0;
			ll tw = 0;
			for(ll j = n1; j < n1 + n2; j++){
				if((i >> (j - n1)) & 1){
					tv += v[j];
					tw += w[j];
				}
 
				if(tw <= max_w){
					// cout << "push2: " << tw << " " << tv << endl;
					v2.push_back((pll){tw, tv});
				}
			}
		}
 
		sort(v1.begin(), v1.end());//ソート
		sort(v2.begin(), v2.end());
 
		ll m1 = v1.size();
		ll m2 = v2.size();
		ll ans = 0LL;
		ll ma = 0LL;
		ll j = 0LL;
		for(ll i = m1-1; i >= 0; i--){//重さが大きい方なので後ろから
			pll p1 = v1[i];
			while(j < m2 && p1.first + v2[j].first <= max_w){//jがm2の個数未満かつ、二つの重さが容量以下なら
				// if(p1.second + v2[j].second > ans) cout << p1.first << " " << p1.second << " " << v2[j].first << " " << v2[j].second << endl;
				ma = max(ma, v2[j].second);//最大値更新 p1の価値は決まっているため、p2の価値だけ更新すれば良い
				j++;
			}
			ans = max(ans, p1.second + ma);//p1と、p2の最大値を足して更新を図る
		}
 
		cout << ans << endl;
		return 0;
 
	}else if(mv <= 1000){//dp 価値を用いて更新する
 
		ll INF = 1e15;
		mv = 200010;
 
		ll dp2[mv+1];
		rep(j, mv+1) dp2[j] = INF;
		dp2[0] = 0;
 
		for(int i = 0; i < n; i++){
			for(int j = mv; j >= 0; j--){
				if(j - v[i] >= 0){
					dp2[j] = min(dp2[j], dp2[j-v[i]]+w[i]);
				}
			}
		}
 
		for(ll i = mv; i >= 0; i--){
			if(0 <= dp2[i] && dp2[i] <= max_w){//最大価値から見ていき、合致したものがあればそれが解
				cout << i << endl;
				return 0;
			}
		}
	}else{//上記の重さ版
		ll INF = 1e15;
		mw = 200010;
		ll dp3[mw+1];
		rep(j, mw+1) dp3[j] = 0;
		for(int i = 0; i < n; i++){
			for(int j = mw; j >= 0; j--){
				if(j - w[i] >= 0){
					dp3[j] = max(dp3[j], dp3[j-w[i]]+v[i]);
				}
			}
		}
 
		ll ans = 0;
		for(ll i = 0; i <= max_w; i++){//価値の最大値更新
			ans = max(ans, dp3[i]);
		}
 
		cout << ans << endl;
	}
}