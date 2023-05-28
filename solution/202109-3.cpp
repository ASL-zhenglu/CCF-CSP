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
	cin.tie(0);
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
