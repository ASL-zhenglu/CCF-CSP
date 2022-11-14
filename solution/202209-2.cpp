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
//学到一个处理输出的方法，快乐
const int maxn = 30 + 5;
int n , m, sum;
int dp[500000];
int a[maxn];

void Init() {
    read(n),read(m);
    for(int i = 0;i < n;i++) {
        read(a[i]);
        sum += a[i];
    }
}

int main()
{
    Init();
    dp[0] = true;
    for(int i = 0;i < n;i++) {
        for(int j = sum;j >= a[i];j--) {
            dp[j] |= dp[j - a[i]];
        }
    }
    for(int i = m;i <= sum;i++) {
        if(dp[i]) {
            cout<<i<<endl;
            break;
        }
    }
    // system("pause");
    return 0;
}
