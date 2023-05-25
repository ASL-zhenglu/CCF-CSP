https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/solution/shan-chu-zi-wen-jian-jia-by-leetcode-sol-0x8d/

debug
1. error: type 'vector<int>' does not provide a call operator
样例：
 min[o] = std::min(min[o * 2], min[o * 2 + 1]);
原因：
就是min跟他c++中的min重名了，所以要加std::来区分
2. 运行错误可能是边界没处理（有分数）, 指针越界等等
3. map有时候要先判断是否存在，不然可能会直接创建

class Graph {
public:
	struct Pair {   // <=> pair<int, int> 
        int first, second;
    };
    
    vector<vector<Pair>> g;
    Graph(int n, vector<vector<int>>& edges) {
		g.resize(n);
		for (auto &e : edges) {
			g[e[0]].push_back(Pair{e[1], e[2]});
		}
    }
    
    void addEdge(vector<int> edge) {
		
    }
    
    int shortestPath(int node1, int node2) {
    	for (int i = 0; i < g.size(); i++) {
    		for (int j = 0; j < g[i].size(); j++) {
    			cout<<g[i][j].first<<" "<<g[i][j].second;
			}
		}
		return 0;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

初始化为大于10e9 的常数
# include<bits/stdc++.h>

using namespace std;

int main() {
 	int a[5];
 	memset(a,0x3f,sizeof(a));  // 0x3f3f3f3f
    // memset(a,-1,sizeof(a)); 
    // memset(a,0,sizeof(a)); 
 	for (auto &x : a) {
 		cout<<x<<endl;
	}
} 

二分查找
int idx = lower_bound(a, a+n, x) - a
// 找第一个大于等于x的下标，在a数组中，其中a为静态数组， 第一个大于用upper_bound
而对于vector使用就是
int main() {
  	vector<int> a = {1, 2, 3, 4, 5};
	auto idx = lower_bound(a.begin(), a.end(), 4)-a;
	cout<<*idx<<endl; 
} 

逆序：
# include<bits/stdc++.h>

using namespace std;


int main() {
  	int a[5] = {1,5,3,4,6};
  	sort(a, a+5, [&](int a, int b) {
  		return a > b;
	});
	for (auto &x : a) {
		cout<<x<<" ";
	} 
} 


结构体
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int cur, max, min;
};

struct Pair {
	int up, down;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, l, r;
        string s;
        cin >> n >> m >> s;
        // 预处理
        vector<Node> preSum(n + 1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '+') {
                preSum[i + 1].cur = preSum[i].cur + 1;
            } else {
                preSum[i + 1].cur = preSum[i].cur - 1;
            }
            preSum[i + 1].max = max(preSum[i].max, preSum[i + 1].cur);
            preSum[i + 1].min = min(preSum[i].min, preSum[i + 1].cur);
        }
        vector<Pair> suf(n + 1);
        int cur = 0, mx = 0, mn = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '+') {
                cur--;
            } else {
                cur++;
            }
            mx = max(mx, cur);
            mn = min(mn, cur);
            suf[i] = { mx - cur, mn - cur };
        }
        while (m--) {
            cin >> l >> r;
            Node p = preSum[l - 1];
            Pair s = suf[r];
            cout << max(p.max, p.cur + s.up) - min(p.min, p.cur + s.down) + 1 << endl;
        }
    }
    return 0;
}

堆
priority_queue<int, vector<int>, greater<int> >qi2;//最小堆
priority_queue<int, vector<int>, less<int> >qi2;//最大堆
#include <bits/stdc++.h>
 
using namespace std;

const int lnf = INT_MAX/2;

struct Pair {
    int to, cost;
	
};
bool operator>(Pair a, Pair b) { // 小根堆这里是>,大根堆是<
    return a.cost < b.cost;
}
int main() {
    int n, m, start;
    scanf("%d%d%d", &n, &m, &start);
    start--;
    // Build Graph
    vector<vector<Pair>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({ v, w });
    }

    vector<int> dis(n, lnf);
    dis[start] = 0;

    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    q.push({ start, 0 });
    while (!q.empty()) {
        Pair p = q.top(); q.pop();
        int x = p.to, cost = p.cost;
        if (dis[x] < cost) continue;
        for (Pair &y : g[x]) {
            int di = dis[x] + y.cost;
            if (di < dis[y.to]) {
                dis[y.to] = di;
                q.push({ y.to, di });
            }
        }
    }

    for (auto &d : dis) {
        printf("%d ", d);
    }

    return 0;
}


auto
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<string> ans(n);
        int idx[n];
        iota(idx, idx+n, 0);
        sort(idx, idx + n, [&](const auto &a, const auto &b) {
            return heights[a] > heights[b];
        });
        for (int i = 0; i < n; i++) {
            ans[i] = names[idx[i]];
        }
        return ans;
    }
};

排序去重：
sort(xs.begin(), xs.end());
xs.erase(unique(xs.begin(), xs.end()), xs.end());
sort(ys.begin(), ys.end());
ys.erase(unique(ys.begin(), ys.end()), ys.end());

long long 
#define ll long long
typedef long long ll

图论
方向：
#include<bits/stdc++.h>
#define ll long long

using namespace std;

static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
	ll x = 0; 
	x += dirs[1][0];
	cout<<x<<endl;
	return 0;
}


LCP 75.传送卷轴
class Solution {
	const int INF = 0x3f3f3f3f;
	static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int challengeOfTheKeeper(vector<string>& maze) {
    	int m = maze.size(), n = maze[0].size();
		int sx, sy, tx, ty, disFromT[m][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (maze[i][j] == 'S') {
					sx = i;sy = j;
				} else if (maze[i][j] == 'T') {
					tx = i;ty = j; 
				}
				disFromT[i][j] = INF;
			}
		} 
		disFromT[tx][ty] = 0;
		queue<pair<int, int>> q;
		q.push({tx,ty});
		int dist = 1;
		while(!q.empty()) {
			int l = q.size();
			for (int i = 0; i < l; i++) {
				auto [x, y] = q.front();
				q.pop();
				for (auto &d : dirs) {
					int nx = x+d[0], ny = y+d[1];
					if (0 <= nx && nx < m && 0 <= ny && ny < n && disFromT[nx][ny] == INF && maze[nx][ny] != '#') {
						disFromT[nx][ny] = dist;
						q.push({nx, ny});
					}
				}
			}
			dist++;
		}
		if (disFromT[sx][sy] == INF) {
			return -1;
		}
		int vis[m][n];
		memset(vis, -1, sizeof(vis));
		function<bool(int)> check = [&](int maxDis) {
			function<bool(int, int)> dfs = [&](int x, int y) {
				if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] == maxDis || maze[x][y] == '#') {
					return false; 
				} 
				if (maze[x][y] == 'T') {
					return true;
				}
				vis[x][y] = maxDis;
				if (maze[x][y] == '.') {
					if (maze[m-x-1][y] != '#' && disFromT[m-x-1][y] > maxDis) {
						return false;
					}
					if (maze[x][n-y-1] != '#' && disFromT[x][n-y-1] > maxDis) {
						return false;
					}
				}
				for (auto &d : dirs) {
					if (dfs(x+d[0], y+d[1])) {
						return true;
					}
				}
				return false;
			};
			return dfs(sx, sy);
		};
		
		int left = 0, right = m*n+1;
		while(left < right) {
			int mid = left+(right-left)/2;
			if (check(mid)) right = mid;
			else left = mid+1;
		}
		if (left >= m*n) {
			return -1;
		}
		return left;
    }	
};
Floyd
class Graph {
    vector<vector<int>> d;
public:
    Graph(int n, vector<vector<int>> &edges) {
        // 邻接矩阵（初始化为无穷大，表示 i 到 j 没有边）
        d = vector<vector<int>>(n, vector<int>(n, INT_MAX / 3));
        for (int i = 0; i < n; ++i)
            d[i][i] = 0;
        for (auto &e: edges)
            d[e[0]][e[1]] = e[2]; // 添加一条边（输入保证没有重边和自环）
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    void addEdge(vector<int> e) {
        int x = e[0], y = e[1], w = e[2], n = d.size();
        if (w >= d[x][y]) // 无需更新
            return;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][x] + w + d[y][j]);
    }

    int shortestPath(int start, int end) {
        int ans = d[start][end];
        return ans < INT_MAX / 3 ? ans : -1;
    }
};

随便学的
typedef unsigned long long ll;
题目条理比较清晰，对于这种第五题，我们在考试时尽可能拿更多的分（第5题拿满分我不敢奢望hhhh），在此只提出一些应该注意的小细节
数据类型采用unsigned long long数据范围比long long更大，如果只采用long long 最后只有70分
多次采用取模运算，在操作2乘法计算完后，进行取模操作，否则只有20分
在操作4后，求得指定区间内的坐标和后，进行取模运算
在计算平方和时：1.计算完单一坐标的平方后取模，2.计算完所有的坐标的平方和后取模
快读：
template <typename Tp>
void read(Tp &x) {
	x = 0; int fh = 1; char ch = 1;
	while(ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if(ch == '-') fh = -1, ch = getchar();
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= fh;
}

ios::sync_with_stdio(false);
cin.tie(nullptr);
读入问题：
读入1 1 A
#include<bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    char ch;
    scanf("%d%d %c", &x, &y, &ch); //%d%d %c 中间加一个空格
    cout << x << " " << y << " " << ch << endl;
    return 0;
}


正向查找find()

s.find(str)
string中find()返回值是字母在母串中的第一次出现的下标位置。如果没有找到，那么会返回-1。
s.find(str, pos)
find(str,pos)是用来寻找从pos开始**(包括pos处字符)**匹配str的位置。


// 两个数组的交集
set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
// 两个数组的并集
set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100010;

struct segtree {
	int l, r, todo;
	ll sum;
}t[4*maxn];


void maintain(int o) {
	t[o].sum = t[o*2].sum + t[o*2+1].sum;
}

void build(vector<int> &a, int o, int l, int r) {
	t[o].l = l; t[o].r = r;
	if (l == r) {
		t[o].sum = a[l-1];
		return;
	}
	int m = (l + r) >> 1;
	build(a, o*2, l, m);
	build(a, o*2+1, m+1, r);
	maintain(o); // 维护
}

void do2(int o, int val) { //传递 c++中有关键字do
	t[o].sum += (t[o].r-t[o].l+1)*val;
	t[o].todo += val;
}

void spread(int o) {
	int val = t[o].todo;
	if (val != 0) {
		do2(o*2, val);
		do2(o*2+1, val);
		t[o].todo = 0;
	}
} 

// 将 [x, y] + val
void add(int o, int l, int r, int val) {
	if (l <= t[o].l && t[o].r <= r) {
		do2(o, val);
		return;
	}
    spread(o);
	int m = (t[o].l + t[o].r) >> 1;
	if (l <= m) {
		add(o*2, l, r, val);
	}
	if (r > m) {
		add(o*2+1, l, r, val);
	}
	maintain(o);
}

// 返回区间 [l,r] 内的元素和
ll querySum(int o, int l, int r)  {
	ll sum = 0;
	if (l <= t[o].l && t[o].r <= r) {
		return t[o].sum;
	}
    spread(o);
	int m = (t[o].l + t[o].r) >> 1;
	if (l <= m) {
		sum += querySum(o*2, l, r);
	}
	if (r > m) {
		sum += querySum(o*2+1, l, r);
	}
	return sum;
}


int main() {
	int n, m, f, x, y, k;
	scanf("%d%d", &n, &m);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	build(a, 1, 1, n);
	for (int i = 0; i < m; i++) {
		scanf("%d", &f);
		if (f == 2) {
			scanf("%d%d", &x, &y);
			cout<<querySum(1, x, y)<<endl;
		} else {
			scanf("%d%d%d", &x, &y, &k);
			add(1, x, y, k);
		}
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 610;
int n, L, r, t;

class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            sum.resize(m+1,vector<int>(n+1));
                for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                sum[i+1][j+1] = matrix[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
            }
        }
            
    }     
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }
};

int main() {
	scanf("%d%d%d%d", &n, &L, &r, &t);
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	// 二维前缀和 
	NumMatrix numMatrix(a);
//	int regionSum = numMatrix.sumRegion(row1, col1, row2, col2);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int row1, col1, row2, col2, cnt;
			row1 = i-r<0? 0: i-r;
			col1 = j-r<0? 0: j-r;
			row2 = i+r>n-1? n-1 : i+r;
			col2 = j+r>n-1? n-1 : j+r; 
			cnt = (row2-row1+1)*(col2-col1+1);
			int sum = numMatrix.sumRegion(row1, col1, row2, col2);
			if (sum <= t*cnt) {
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
set
#include <bits/stdc++.h>
using namespace std;

int main() {
	set<int> st;
	st.insert(10);
	st.insert(20);
	st.insert(30);
	cout<<*st.begin()<<endl;  //取第一个值，取最后一个用*st.rend();
    return 0;
}
// it = st.begin()是第一个元素，从第二个元素开始遍历，就让it++即可
施肥：
#include<bits/stdc++.h>

using namespace std;

template <typename Tp>
void read(Tp &x) {
	x = 0;
	int fh = 1;
	char ch = 1;
	while(ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if(ch == '-') fh = -1, ch = getchar();
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= fh;
}
typedef long long ll;
ll n, m, l, r;
struct Pair { //自定义要重载，使用使用set嵌套pair不要自定义
    ll l, r;

    bool operator<(const Pair& other) const {
        if (l != other.l)
            return l < other.l;
        return r < other.r;
    }
};
set<Pair> a;

bool check(ll L, ll R) {
	vector<int> diff(R+2);
	for (auto &p : a) {
		ll l1 = p.l, r1 = p.r;
		if (L <= l1 && r1 <= R) {
			diff[l1]++;
			diff[r1+1]--;
		}
	}
	for (int i = L; i <= R; i++) {
		diff[i] += diff[i-1];
		if (diff[i] == 0) {
			return false;
		}
	}
	return true;
}


int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	read(n);
	read(m);
	for(ll i = 0; i < m; i++) {
		read(l);read(r);
		a.insert({l, r});
	}
	ll ans = 0;
	for (ll l = 1; l < n; l++) {
		for (ll r = l+1; r <= n; r++) {
			if (check(l, r)) {
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
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

pi : acos(-1)

脉冲：vector<int> g[1001] 是一个包含 1001 个元素的数组，每个元素的类型是vector<int>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1010;

int N, S, P, T;
double dt;
double delay[maxn][maxn]; //每个结点在该时间步得到的脉冲(循环队列节约空间)
double v[maxn], u[maxn], a[maxn], b[maxn], c[maxn], d[maxn];
int r[maxn];  //发射结点的常数
int f[maxn];  //每个结点的发射次数
int t[maxn];
struct Edge {
	int to, D;
	double w;
};
vector<Edge> ng[maxn]; //神经元 
vector<Edge> rg[maxn]; //脉冲源 

static unsigned long _next = 1;

/* RAND_MAX assumed to be 32767 */
int myrand(void) {
    _next = _next * 1103515245 + 12345;
    return((unsigned)(_next/65536) % 32768);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	scanf("%d%d%d%d", &N, &S, &P, &T);
	cin>>N>>S>>P>>T; 
//	scanf("%lf", &dt);
	cin>>dt;
	for (int i = 0; i < N;) {
		int rn;
//		scanf("%d", &rn);
		cin>>rn;
		double vv, uu, aa, bb, cc, dd;
//		scanf("%lf%lf%lf%lf%lf%lf", &vv, &uu, &aa, &bb, &cc, &dd);
		cin>>vv>>uu>>aa>>bb>>cc>>dd;
		for (int j = 0; j < rn; j++, i++) {
			v[i] = vv, u[i] = uu, a[i] = aa, b[i] = bb, c[i] = cc, d[i] = dd;
		}
	}
	for (int i = 0; i < P; i++ ) {
		//	scanf("%d", &r[i]);
		cin>>r[i];
	}

	
	int maxd = 0; //循环节 
	for (int i = 0; i < S; i++) {
		int ss, tt, DD;
		double ww;
//		scanf("%d%d%lf%d", &ss, &tt, &ww, &DD);
		cin>>ss>>tt>>ww>>DD;
		maxd = max(maxd, DD+1);
		Edge y;
		y.D = DD; y.to = tt; y.w = ww;
		if (ss < N) {
			ng[ss].push_back(y); 
		} else {
			rg[ss-N].push_back(y);
		}
	}
	for (int i = 0; i < N; i++) {
		f[i] = 0;
		for (int j = 0; j < maxd; j++) {
			delay[i][j] = 0;
		} 
	}
	int cur = 0;
	for (int t = 1; t <= T; t++) {  // 遍历时间 
		for (int i = 0; i < N; i++) {
			double vv = v[i], uu = u[i];
			v[i] = vv + dt*(0.04*vv*vv + 5*vv + 140-uu) + delay[i][cur];
			u[i] = uu + dt * a[i] * (b[i] * vv - uu);
			if (v[i] >= 30) { //发射下一个脉冲 
				v[i] = c[i];
				u[i] += d[i];
				for (int y = 0; y < ng[i].size(); y++) {
					Edge x = ng[i][y];
					delay[x.to][(cur+x.D)%maxd] += x.w;
				}
				f[i]++;
			}
			delay[i][cur] = 0;  //队首清零准备放入队尾
		} 
		
		for (int i = 0; i< P; i++) {
            int z = myrand();
            if(r[i] > z) {  //发射 
                for (int y = 0; y < rg[i].size(); y++) {
                    Edge x = rg[i][y];
                    delay[x.to][(cur + x.D) % maxd] += x.w;
                }
            }
        }
        cur = (cur + 1) % maxd;
	}
	double v_min = 1e10;
    double v_max = -1e10;
    int f_min = 1e10;
    int f_max = -1e10;
    for(int i = 0;i<N;i++)
    {
        v_min = min(v_min,v[i]);
        v_max = max(v_max,v[i]);
        f_min = min(f_min,f[i]);
        f_max = max(f_max,f[i]);
    }
    printf("%.3lf %.3lf\n%d %d\n",v_min,v_max,f_min,f_max);
	return 0;
}

分割字符串

vector<string> split(const string& s, string c = " ") {
    vector<string> ans;
    for (gg i = 0, j = 0; i < s.size(); i = j + 1) {
        j = s.find(c, i);
        if (j == -1) {
            j = s.size();
        }
        ans.push_back(s.substr(i, j - i));
    }
    return ans;
}
字符串转字符
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    const char* charArray = str.c_str();
    std::cout << charArray << std::endl;
    return 0;
}
数字/字母
isalpha()
isisdigit('1') 
map
erase
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int t, n, k;
	cin>>t;
	while (t--) {
		cin>>n;
		vector<ll> a(n);
		for (int i = 0; i < n; i++) {
			cin>>a[i];
		}
		n = unique(a.begin(), a.end())-a.begin(); //连续去重
//		n = a.size();
		int ans = 0;
    	for (int i = 0; i < n; i++) {
	        if (((i == 0 || a[i] > a[i - 1]) && (i == n - 1 || a[i] > a[i + 1]))
	            || ((i == 0 || a[i] < a[i - 1]) && (i == n - 1 || a[i] < a[i + 1]))) {
	            ans++;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
● unqiue必须是前面的n项，因为后面没有删除只是覆盖了，除非你用erase

建树
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF = 2e18;

struct File {
	ll size; //文件大小，不是文件为0
	bool isFile; //是否为普通文件
	ll ld, lr; //设置上限
	ll ldsize, lrsize; //后代之和
	unordered_map<string, File*> child;
	File(ll sz, bool file) : size(sz), isFile(file), ld(INF), lr(INF), ldsize(0), lrsize(0) {}
};

//分割字符串
vector<string> split(const string& s, string c = " ") {
    vector<string> ans;
    for (ll i = 0, j = 0; i < s.size(); i = j + 1) {
        j = s.find(c, i);
        if (j == -1) {
            j = s.size();
        }
        ans.push_back(s.substr(i, j - i));
    }
    return ans;
}

ll fileSize(File *root, const vector<string> &path) {
	for (ll i = 1; i < path.size() && root; i++) {
		root = root->child.count(path[i]) ? root->child[path[i]] : nullptr;
	}
	return root && root->isFile ? root->size : 0;
} 

bool canCreatFile(File *root, const vector<string> path, ll sz) {
	for (ll i = 1; i < path.size() && root; i++) {
		if (root->isFile || root->lrsize + sz > root->lr ||(i == path.size()-1 && root->ldsize + sz > root->ld)) { //配额不对的时候就有问题了 
			return false;
		}
		root = root->child.count(path[i]) ? root->child[path[i]] : nullptr; 
	}
	return !root || root->isFile;
}

bool createFile(File *root, const vector<string> &path, ll sz) {
	ll curSize = fileSize(root, path); //求出当前的文件大小，因为你要看能不能修改； 
	sz -= curSize; //变化的值,差值 
	if (!canCreatFile(root, path, sz)) {
		return false;
	} 
	//可以创建
	for (ll i = 1; i < path.size()-1; i++) {
		root->lrsize += sz;
		if (!root->child.count(path[i])) {
			root->child[path[i]] = new File(0, false);
		}
		root = root->child[path[i]];
	} 
	//最后一个文件了path.back()
	root->ldsize += sz; root->lrsize += sz;
	if (!root->child.count(path.back())) {
		root->child[path.back()] = new File(0, true);
	}
	root->child[path.back()]->size += sz;
	return true;
}
// 删除文件 
void removeFile(File *root, const vector<string> &path) {
	// 删除的路径不存在
	auto r = root;
	for (ll i = 1; i < path.size() && r; i++) {
		r = r->child.count(path[i]) ? r->child[path[i]] : nullptr;
	} 
	if (!r) {
		return ;
	}
	ll sz = r->isFile ? r->size : r->lrsize;
	for (ll i = 1; i < path.size()-1 && root; i++) {
		root->lrsize -= sz;
		root = root->child[path[i]]; 
	}
	root->lrsize -= sz;
	if (r->isFile) {
		root->ldsize -= sz;
	}
	root->child.erase(path[path.size() - 1]);
} 

bool QFile(File* root, const vector<string>& path, ll ld, ll lr) {
    for (ll i = 1; i < path.size() and root; i++) {
        root = root->child.count(path[i]) ? root->child[path[i]] : nullptr;
    }
    if (not root or root->isFile or root->lrsize > lr or root->ldsize > ld) {
        return false;
    }
    root->lr = lr;
    root->ld = ld;
    return true;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    ll ni, ld, lr, sz;
    cin >> ni;
    string c, path;
    File* root = new File(0, false);  //表示根目录的结点
    while (ni--) {
        cin >> c >> path;
        auto pathSplit = split(path, "/");
        if (c == "C") {
            cin >> sz;
            if (createFile(root, pathSplit, sz)) {
            	cout<<"Y"<<endl;
			} else {
				cout<<"N"<<endl;
			}
        } else if (c == "R") {
            removeFile(root, pathSplit);
            cout<<"Y"<<endl;
        } else {
            cin >> ld >> lr;
            ld = ld == 0 ? INF : ld;
            lr = lr == 0 ? INF : lr;
            if (QFile(root, pathSplit, ld, lr)) {
            	cout<<"Y"<<endl;
			} else {
				cout<<"N"<<endl;
			}
        }
    }
	return 0;
}


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

合并两个有序数组O(n)
// 合并两个有序数组O(n)
void merge(vector<int>& dest, vector<int>& v)
{
	vector<int> v3(dest.size() + v.size());
	if (dest.empty()) dest = v;
	else {
		int p1 = 0, p2 = 0, i = 0;
		while (p1 != dest.size() && p2 != v.size()) {
			if (dest[p1] < v[p2]) v3[i++] = dest[p1++];
			else v3[i++] = v[p2++];
		}
		if (p1 == dest.size()) {
			while(p2 != v.size())
				v3[i++] = v[p2++];
		}
		else{
			while (p1 != dest.size())
				v3[i++] = dest[p1++];
		}
	}
	dest = v3;
}
递归
求后代
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAX = 3e5+5;
ll n;
vector<ll> p[MAX];
ll a[MAX];
vector<ll> suf[MAX]; // 后代 

vector<ll> find(ll x) { //递归
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
