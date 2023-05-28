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
	// ¶þÎ¬Ç°×ººÍ 
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
