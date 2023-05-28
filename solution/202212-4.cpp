#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAX = 3e5+5;
ll n;
vector<ll> p[MAX];
ll a[MAX];
vector<ll> suf[MAX]; // ºó´ú 

vector<ll> find(ll x) {
	vector<ll> res;
	res.push_back(x);
	if (p[x].size() == 0) {
		return res;
	}
	vector<ll> &t = p[x];
	vector<vector<ll>> s;
	for (ll i = 0; i < t.size(); i++) {
		s.push_back(find(t[i]));
	} 
	for (ll i = 0; i < s.size(); i++) {
		for (ll j = 0; j < s[i].size(); j++) {
			res.push_back(s[i][j]);
		}
	}
	suf[x] = res;
	return res;
}

ll cal(vector<ll> &v) {
	ll ans = 0;
	vector<ll> s;
	for (auto &x : v) {
		s.push_back(a[x]);
	}
	if (s.size() == 1) {
		return 0;
	}
	sort(s.begin(), s.end());
	
	for (int i = 0; i < s.size(); i++) {
		ll tmp = 1e18;
       	if(i+1>=0&&i+1<s.size())
       	tmp=min((s[i+1]-s[i])*(s[i+1]-s[i]),tmp);
       	if(i-1>=0&&i-1<s.size())
       	tmp=min((s[i-1]-s[i])*(s[i-1]-s[i]),tmp);
       	ans+=tmp;
	} 
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for (ll i = 2; i <= n; i++) {
		ll x;
		cin>>x;
		p[x].push_back(i);
	}
	for (ll i = 1; i <= n; i++) {
		cin>>a[i];
	}
	find(1);
	for (int i = 1; i <= n; i++) {
		cout<<cal(suf[i])<<"\n";
	}
	return 0;
}
