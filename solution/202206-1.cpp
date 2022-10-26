
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) {
        cin>>nums[i];
    }
    double sum = 0;
    for(int &num : nums) {
        sum += num;
    }
    double f = sum * 1.0 / n;
    double d = 0;
    for(int &num : nums) {
        d += (num*1.0 - f) * (num*1.0 - f);
    }
    d = sqrt(d / n);
    for(int &num : nums) {
        double x = (num*1.0 - f) / d;
        printf("%0.16f\n", x);
    }
    system("pause");
    return 0;
}
