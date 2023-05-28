#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAX = 1010;
ll n, m, g;
ll node[MAX];
ll task[MAX]; //任务数量 
ll fi, ai, nai, pai, paai, paari;
unordered_map<ll, vector<ll>> mp; //应用对应的节点
bool f_node[MAX];
bool f_area[MAX]; 

ll helper() {
	memset(f_node, false, sizeof(f_node));
	memset(f_area, false, sizeof(f_area));
	if (pai != 0) {
		vector<ll> v = mp[pai];
		for (auto &x : v) {
			f_area[node[x]] = true;
		}
	}
	if (paai != 0) {
		vector<ll> v = mp[paai];
		for (auto &x : v) {
			f_node[x] = true;
		}
	}
	ll res = -1;
	ll mn = 0x3f3f3f3f;
//	cout<<nai<<"???"<<"\n";
	for (ll i = 1; i <= n; i++) {
		
		
		if (task[i] < mn && (nai == 0 || node[i] == nai) && (pai == 0 || f_area[node[i]]) && (paai == 0 || !f_node[i])) {
			mn = task[i];
			res = i;
		}
	}
//	cout<<res<<endl;
//	cout<<"\n";
	if (paari == 0) { //尽量满足 
		if (res == -1) {
			for (ll i = 1; i <= n; i++) {
				if (task[i] < mn && (nai == 0 || node[i] == nai) && (pai == 0 || f_area[node[i]])) {
					mn = task[i];
					res = i;
				}
			}
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for (ll i = 1; i <= n; i++) {
		ll x;
		cin>>x;
		node[i] = x;
	} 
	cin>>g;
	for (ll i = 0; i < g; i++) {
		cin>>fi>>ai>>nai>>pai>>paai>>paari;
		// 输出
		for (ll i = 0; i < fi; i++) {
			ll ans = helper();
//			cout<<ans<<endl;
			if (ans == -1) {
				cout<<0<<" ";
			} else {
				cout<<ans<<" ";
				task[ans]++;
				mp[ai].push_back(ans);
			}
		}
		cout<<"\n"; 
	}
	return 0;
}
