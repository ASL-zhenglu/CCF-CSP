#include <bits/stdc++.h>

using namespace std;

template <typename Tp>
void read(Tp &x) {
	x = 0; int fh = 1; char ch = 1;
	while(ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if(ch == '-') fh = -1, ch = getchar();
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= fh;
}

const int N = 500010;
const int M = 10005;
vector<int> diff(M);
vector<int> a(N);


void helper(int l, int r) {
    diff[l]++;
    diff[r+1]--;
}

int main()
{
    int n;
    read(n);
    for(int i = 1;i <= n;i++) read(a[i]);
    for(int i = 1;i <= n;i++) {
        if(a[i] > a[i-1]) {
            helper(a[i-1]+1,a[i]);
        }
    }
    int Max = INT_MIN;
    for(int i = 1;i < M;i++) {
        diff[i] += diff[i-1];
        Max = max(Max,diff[i]);
    }
    cout<<Max;
//     system("pause");
    return 0;
}

