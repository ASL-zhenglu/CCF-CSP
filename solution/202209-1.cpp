#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> A(n);
    vector<int> B(n);
    for(int i = 0;i < n;i++) {
        cin>>A[i];
    }
    vector<int> C(n+1);
    C[0] = 1;
    int sum = 0;
    for(int i = 0;i < n;i++) {
        C[i+1] = C[i] * A[i];
        B[i] = (m % C[i+1] - sum) / C[i];
        sum += B[i] * C[i];
    }
    for(int &b : B) {
        cout<<b<<" ";
    }
//     system("pause");
    return 0;
}
