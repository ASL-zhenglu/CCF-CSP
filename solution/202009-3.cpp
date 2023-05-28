// 1.检测环路50
// 2.模拟逻辑50 
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAX = 3e3;
vector<ll> g[MAX];
ll degree[MAX];
ll Q, M, N, S, k, z, x1;
struct Pair {
	string name;
	vector<ll> input;
};
Pair device[MAX];
bool output[MAX];
vector<ll> cnt;
// 拓扑排序

// 输出 
bool check() {
	queue<ll> q;
	
	for (ll i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			q.push(i);
			
		}
	}
	while(!q.empty()) {
		auto cur = q.front();
		q.pop();
		cnt.push_back(cur);
		for (auto &x : g[cur]) {
			degree[x]--;
			if (degree[x] == 0) {
				q.push(x);
			}
		}
	}
	return cnt.size() == N;
}


void getAnswer(vector<ll> &a) {
	for (ll &i : cnt) { //这个也是顺序 
		if (device[i].name == "NOT") {
			ll id = device[i].input[0];
			output[i] = !(id > 0 ? output[id] : a[-id]);
		} else if (device[i].name == "AND") {
			output[i] = true;
			for (ll &id : device[i].input) {
				output[i] &= (id > 0 ? output[id] : a[-id]);
			} 
		} else if (device[i].name == "OR") {
			output[i] = false;
			for (ll &id : device[i].input) {
				output[i] |= (id > 0 ? output[id] : a[-id]);
			} 
		} else if(device[i].name == "XOR") {
			output[i] = false;
			for (ll &id : device[i].input) {
				output[i] ^= (id > 0 ? output[id] : a[-id]);
			} 
		} else if(device[i].name == "NAND") {
			output[i] = true;
			for (ll &id : device[i].input) {
				output[i] &= (id > 0 ? output[id] : a[-id]);
			} 
			output[i] = !output[i];
		} else if (device[i].name == "NOR") {
			output[i] = false;
			for (ll &id : device[i].input) {
				output[i] |= (id > 0 ? output[id] : a[-id]);
			} 
			output[i] = !output[i];
		}
	}
}

int main() {
	
	string x;
	cin>>Q;
	while(Q--) {
		cin>>M>>N;
		for (ll i = 1; i <= N; i++) {
			g[i].clear();
			device[i].input.clear(); // ?
			degree[i] = 0;
		}
		cnt.clear();
//		output.clear();
		for (ll i = 1; i <= N; i++) {
			cin>>device[i].name>>k;
			for (ll j = 1; j <= k; j++) {
				cin>>x;
				string str = x.substr(1);
				ll id = stoi(str);
				device[i].input.push_back(x[0] == 'O' ? id : -id); //id为正，-id说明是Input 
				if (x[0] == 'O') {
					g[id].push_back(i);
					degree[i]++;
				} 
			}
		}
		bool flag = check();
		if (!flag) {
			cout<<"LOOP"<<endl;
		}
		cin>>S;
		vector<vector<ll>> in(S, vector<ll>(M+1));
		for (ll i = 0; i < S; i++) {
			for (ll j = 1; j <= M; j++) {
				cin>>in[i][j];
			}
		}
		for (ll i = 0; i < S; i++) {
			cin>>z;
			getAnswer(in[i]);
			for (ll j = 0; j < z; j++) {
				cin>>x1;
				if (flag) { //这里也会输出 
					cout<<output[x1]<<" ";
				}
			}
			if (flag) {
				cout<<endl;
			}
			
			
		}
	} 
	return 0;
}
