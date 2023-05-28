#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Pair {
	int zero, one;
};

int m, y, r, cnt1, ans, pre0, pre1, mx;

int main() {
	
	map<int, Pair> mp;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &y, &r);
		auto &p = mp[y];
		if (r == 0) {
			p.zero++;
		} else {
			cnt1++;
			p.one++;
		}
	}
	for (auto &x : mp) {
		int k = x.first;
		Pair v = x.second;
//		cout<<k<<" "<<v.zero<<" "<<v.one<<endl;
		int cnt = pre0+cnt1-pre1;
		if (cnt >= mx) {
			ans = k;
			mx = cnt;
		}
		pre0 += v.zero; 
		pre1 += v.one;
	}
	cout<<ans<<endl;
	return 0;
}
