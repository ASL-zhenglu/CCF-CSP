#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const ll MAX = 3000;
ll n, m, q;
struct Person { //��ɫ 
	string name; // mapӳ��
	set<string> ops; //�����嵥 ��*���� 
	set<string> types;  // ��Դ���࣬*���� 
	set<string> names; // ��Դ���� , ������
};


Person a[MAX];
unordered_map<string, ll> mp; //��person 
unordered_map<string, vector<int>> ug; //�û����Ӧ����ɫ���  ���û� 
//unordered_map<string, vector<int>> user;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>q;
	for (ll i = 0; i < n; i++) {
		string name;
		ll nv, no, nn;
		cin>>name>>nv;
		mp[name] = i;
		a[i].name = name;
		for (ll j = 0; j < nv; j++) {
			string op;
			cin>>op;
			a[i].ops.insert(op);
		}
		cin>>no;
		for (ll j = 0; j < no; j++) {
			string type;
			cin>>type;
			a[i].types.insert(type);
		}
		cin>>nn;
		for (ll j = 0; j < nn; j++) {
			string name1;
			cin>>name1;
			a[i].names.insert(name1);
		}
	}
//	cout<<m<<"\n";
	for (ll i = 0; i < m; i++) {
		string name;
		cin>>name;
		ll j = mp[name];
//		cout<<j<<"\n";
		
		ll ns;
		cin>>ns;
		for (ll k = 0; k < ns; k++) {
			string a, b;
			cin>>a>>b;
			if (a == "u" || a == "g") {
				ug[b].push_back(j);
			}
		}
	}
//	cout<<ug.size()<<"\n";
//	for (auto &x : ug) {
//		for (auto &y : ug[x.first]) {
//			cout<<y<<"\n";
//		}
//	}
	for (ll i = 0; i < q; i++) {
		// ����
		
		string name, op, type, name1;
		ll ng;
		vector<string> f;
		cin>>name>>ng;
		f.push_back(name);
		for (ll j = 0; j < ng; j++) {
			string family;
			cin>>family;
			f.push_back(family);
		} 
		cin>>op>>type>>name1;
		// ��� 
		bool flag = false;
		for (auto &j : f) { 
			for (auto &x : ug[j]) { 
				if (a[x].ops.count(op) || a[x].ops.count("*")) {
					if (a[x].types.count(type) || a[x].types.count("*")) {
						if (a[x].names.count(name1) || a[x].names.size() == 0) {
							flag = true;
							break;
						}
					}
				}
			}
			if (flag) {
				break;
			}
		}
		if (flag) {
			cout<<1<<"\n"; 
		} else {
			cout<<0<<"\n";
		}
	}
	return 0;
}
