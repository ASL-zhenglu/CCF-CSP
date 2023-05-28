#include<bits/stdc++.h>

using namespace std;

//template <typename Tp>
//void read(Tp &x) {
//	x = 0;
//	int fh = 1;
//	char ch = 1;
//	while(ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
//	if(ch == '-') fh = -1, ch = getchar();
//	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
//	x *= fh;
//}
// 35·Ö 
typedef long long ll;
ll n, m, l, r;
 
set<pair<int,int>> a;

bool check(ll L, ll R) {
	vector<int> diff(R+2);
	for (auto &p : a) {
		ll l1 = p.first, r1 = p.second;
		if (L <= l1 && r1 <= R) {
			diff[l1]++;
			diff[r1+1]--;
		}
	}
	for (int i = L; i <= R; i++) {
		diff[i] += diff[i-1];
		if (diff[i] == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	cin>>n>>m;
	for(ll i = 0; i < m; i++) {
 
		cin>>l>>r;
		a.insert({l, r});
	}
	ll ans = 0;
	for (ll l = 1; l < n; l++) {
		for (ll r = l+1; r <= n; r++) {
			if (check(l, r)) {
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
