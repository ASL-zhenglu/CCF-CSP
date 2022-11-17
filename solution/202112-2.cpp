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

int n, N;
int r;
long long ans = 0;
vector<int> A;

int main()
{
    read(n),read(N);
    A.resize(n+2);
    r = floor(N*1.0 / (n+1));
    for(int i = 1;i < n+1;i++) {
        read(A[i]);
    }
    A[n+1] = N;
    for(int i = 0;i <= n;i++) {
        for(int j = A[i];j < A[i+1];) {
            int g = floor(j * 1.0 / r);
            int l = r - j%r;
            l = min(l, A[i+1]-j);
            int num1 = l * i;
            int num2 = l * g;
            ans += abs(num1 - num2);
            j += l;
        }
    }
    cout<<ans;
//     system("pause");
    return 0;
}
