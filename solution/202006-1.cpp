#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

struct Tuple {
	ll x, y, flag;
};

int main() {
	ll x, y;
	char ch;
	cin>>n>>m;
	vector<Tuple> a(n);
	set<int> one, two;
	for (int i = 0; i < n; i++) {
//		scanf("%d%d %c", &x, &y, &ch);
		cin>>x>>y>>ch;
//		cout<<x<<" "<<y<<" "<<ch<<endl;
		if (ch == 'A') {
			a[i] = {x, y, 0};
		} else {
			a[i] = {x, y, 1};
		}
	}


	int x1, y1, z1;
	for (int i = 0; i < m; i++) {
		cin>>z1>>x1>>y1;
		for (int j = 0; j < n; j++) {
			ll val = x1*a[j].x + y1*a[j].y + z1;
			if (val > 0) {
				one.insert(a[j].flag);
			} else {
				two.insert(a[j].flag);
			}
		}
		if (one.size() == 1 && two.size() == 1) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
		one.clear(); two.clear();

	}
	return 0;
}

/*
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
0 -2 3
-3 0 2
-3 1 1
*/
