#include<bits/stdc++.h>

using namespace std;
int n;
double i, x, ans;

int main() {
    
    cin>>n>>i;
    for (int j = 0; j <= n; j++) {
        cin >> x;
        ans += x * pow(i + 1, -j); 
    }
    printf("%.3f", ans);
    return 0;
}

