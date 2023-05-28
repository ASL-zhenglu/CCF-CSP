#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const ll N = 1e9+7;
ll n;

struct Pair {
	ll name, time;
};

struct Area {
	ll start, end; //end是指不是风险地区那一天，清空users 
	bool flag; // false代表不是，true代表时 
	vector<Pair> users;
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	map<int, Area> g;
	for (ll i = 0; i < n; i++) {
		// 改变 
		ll r, m;
		cin>>r>>m;
		for (ll j = 0; j < r; j++) {
			ll x;
			cin>>x;
			g[x].flag = true;
//			g[x].start = 
			if (g[x].end < i) {
				g[x].start = i;
			}
			g[x].end = i+7;
		}
		for (auto &kv : g) {
			ll j = kv.first;
			if (g[j].flag && g[j].end == i) {
				g[j].flag = false;
				g[j].users.clear();
				g[j].start = 0;
				g[j].end = 0;
			}
		}
		for (ll j = 0; j < m; j++) {
			ll d, u, r;
			cin>>d>>u>>r;
			if (g.count(r)) {
				if (g[r].flag && g[r].start <= d && d < g[r].end) { //加入 
					g[r].users.push_back(Pair{u, d});
				}
			}
			
		}
		set<ll> st;
		// 输出
		for (auto &kv : g) {
			auto p = kv.second;
			if (p.flag) {
				for (auto &y : p.users) {
					if (i-7 < y.time && y.time <= i) {
						st.insert(y.name);
					}
				}
			}
		}
		cout<<i<<" ";
		for (auto &x : st) {
			cout<<x<<" "; 
		}
		cout<<"\n";
	}
	return 0;
}
 
