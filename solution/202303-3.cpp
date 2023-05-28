#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2505, M = 505;
int n, m, id, cnt, key, value;

struct User {
	int id; // 编号 
	unordered_map<int, int> atter; //属性 
} user[N];


// 原子操作
vector<int> match1(string s) {
	vector<int> res;
	if (s.find(":") != -1) {
		int idx = s.find(":");
		string pre = s.substr(0, idx);
		string suf = s.substr(idx+1);
		int k = stoi(pre), v = stoi(suf);
		
		for (int i = 0; i < n; i++) {
			if (user[i].atter.count(k)) {
				if (user[i].atter[k] == v) {
					res.push_back(user[i].id);
				}
			}
		}
	} else if (s.find("~") != -1) {
		int idx = s.find("~");
		string pre = s.substr(0, idx);
		string suf = s.substr(idx+1);
		int k = stoi(pre), v = stoi(suf);
		
		for (int i = 0; i < n; i++) {
			if (user[i].atter.count(k)) {
				if (user[i].atter[k] != v) {
					res.push_back(user[i].id);
				}
			}
		}
	}
	sort(res.begin(), res.end());
	return res;
} 

// 复杂操作
vector<int> match2(string s) {
	vector<int> res;
	char f = s[0];
	if (f >= '0' && f <= '9') {
		return match1(s);
	} else {
//		string s1 = s.substr(1);
		int left = 0, right = 0;
		int start = 1, end;
		// 左右括号相同时得到表达式
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == '(') {
				left++;
			} else if (s[i] == ')') {
				right++;
			}
			if (left == right) {
				end = i;
				break;
			}
		} 
		string ls = s.substr(start+1, end-start-1);
		string rs = s.substr(end+2);
		vector<int> a, b;
		a = match2(ls);
		b = match2(rs);
		// 与操作
		if (f == '&') {
			set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
		} else if (f == '|') { // 或操作 
			set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
		}
		return res;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &id, &cnt);
		user[i].id = id;
		while (cnt--) {
			scanf("%d%d", &key, &value);
			user[i].atter[key] = value;
		}
	}
	string str;
	scanf("%d", &m);
	while(m--) {
//		scanf("%s", str);
		cin>>str;
		vector<int> ans;
		ans = match2(str);
//		sort(ans.begin(), ans.end());
		if (ans.size() == 0) {
			cout<<endl;
		} else {
			for (auto &x : ans) {
				cout<<x<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
} 
