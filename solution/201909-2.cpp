#include<bits/stdc++.h>

using namespace std;

int N, m, x;
int T, D, E;


int main() {
	cin>>N;
	vector<bool> a(N);
	for (int i = 0; i < N; i++) {
		cin>>m;
		int pre = 0;
		bool flag = false;
		for (int j = 0; j < m; j++) {
			cin>>x;
			if (x > 0) {
				
				if (!flag && x < pre) {
					flag = true;
				}
				pre = x;
			} else {
				pre += x; 
			}
		}
		T += pre;
//		cout<<flag<<endl;
		if (flag) {
			D++;
			a[i] = true;
		}
	}
	
	for (int i = 0; i < N-2; i++) {
		if (a[i] && a[i+1] && a[i+2]) {
			E++;
		}
//		cout<<a[i]<<endl;
	}
//	cout<<a[N-1]<<a[N-2]<<endl;
	if (a[0] && a[1] && a[N-1]) {
		E++; 
	} 
//	cout<<E<<endl;
	if (a[0] && a[N-1] && a[N-2]) {
		E++;
	}
	cout<<T<<" "<<D<<" "<<E<<endl;
	return 0;
}

/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0
*/
/*
5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0
*/
