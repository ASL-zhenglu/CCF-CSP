#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
const ll N = 1e5+5;
const ll mod = 1e9+7;
const ll INF = 1e10;
ll n, m;
// 4分，根本不会 
//非递归快速幂
 
ll qpow(ll a, ll p) {
	ll ans = 1;
	while (p > 0) {
		if (p & 1) {
			ans = ans  * a;
		}
		a = a  * a ;
		p >>= 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	vector<vector<ll>> d(n+1, vector<ll>(n+1, INF));
	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	} 
	while (m--) {
		ll l1, r1, l2, r2, a, b, t;
		cin>>l1>>r1>>l2>>r2>>a>>b;
		t = (a * qpow(2, b))%mod; 
		for (ll j = l1; j <= r1; j++) {
			for (ll k = l2; k <= r2; k++) {
				d[j][k] = t; //环？ 
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], (d[i][k] + d[k][j]));
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (d[1][i] == INF || d[i][1] == INF) {
			cout<<-1<<" ";
		} else {
			cout<<(d[1][i]+d[i][1])%mod<<" ";
		}
		
	}
	return 0;
}
