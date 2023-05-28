#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 929;
const ll N = 2000;
ll w, s, k, cnt;
string str;
ll d[N], g[N], res[N];
void get_d() {
	ll len = str.size();
	ll flag = 0; // 0表示大写 1表示小写2表示数字 
	for (ll i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			if (flag == 1) {
				d[++cnt] = 28;
				d[++cnt] = 28;
			} else if (flag == 2) {
				d[++cnt] = 28;
			}
			flag = 0;
			d[++cnt] = str[i]-'A';
		} else if (str[i] >= 'a' && str[i] <= 'z') {
			if (flag != 1) {
				d[++cnt] = 27;
			}  
			flag = 1;
			d[++cnt] = str[i]-'a';
		} else {
			if (flag != 2) {
				d[++cnt] = 28;
			}
			flag = 2;
			d[++cnt] = str[i]-'0';
		}
	}
	if (cnt % 2 == 1) {
		d[++cnt] = 29;
	}
	for (ll i = 1, j = 1; i < cnt; i += 2, j++) {
		d[j] = 30*d[i] + d[i+1];
	}
	cnt /= 2;
	while((cnt+1+k)%w) {
		d[++cnt] = 900;
	}
	d[0] = cnt+1;
}
// 多项式求系数(x-3)(x-3^2) 
void get_g() {
	g[0] = 1;
	ll r = -3;
	for (ll i = 1; i <= k; r = r*3%mod, i++) {
		for (ll j = i-1; j >= 0; j--) {
			g[j+1] = (g[j+1] + g[j]*r)%mod;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>w>>s>>str;
	k = s == -1 ? 0 : 1<<(s+1);
	get_d(), get_g();
	for (ll i = 0; i <= cnt; i++) {
		res[i] = d[i];
	}
	// 取余 
	for (ll i = 0; i <= cnt; i++) {
		ll r = res[i];
		res[i] = 0;
		for (ll j = 1; j <= k; j++) {
			res[i+j] = (res[i+j] - r*g[j]) % mod;
		}
	}
	for (ll i = 0; i <= cnt; i++) {
		cout<<d[i]<<"\n";
	}
	for (ll i = cnt+1; i <= cnt+k; i++) {
		cout<<(-res[i]%mod + mod)%mod<<"\n";
	}
	return 0;
}
