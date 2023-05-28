#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, a, b, index, value;

int main() {
	
	map<int,vector<int>> mp;
	cin>>n>>a>>b;
	for (int i = 0; i < a+b; i++) {
		cin>>index>>value;
		mp[index].push_back(value);
	}
	ll ans = 0;
	for (auto &x : mp) {
		if (x.second.size() == 2) {
			ans += x.second[0]*x.second[1];
		}
	}
	cout<<ans<<endl;
	return 0;
}

/*
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40
*/
