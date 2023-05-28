#include<bits/stdc++.h>
using namespace std;
int main() {
    int m;
    int n;
    cin >> n;
    cin >> m;
    vector<int>sbj (m, 0);
    vector<int>days(m, 0);
    vector<int>res_e (m, 0);
    vector<int>res_l (m, 0);
    bool tag = true;
    for (int i = 0; i < m; i++) {
        cin >> sbj[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> days[i];
    }
    for (int i = 0; i < m; i++) {
        if (sbj[i] == 0) {  //没有依赖其它科目
            res_e[i] = 1;
        }
        else { //依赖其它科目，需要计算被依赖科目的结束时间
            res_e[i] = res_e[sbj[i] - 1] + days[sbj[i] - 1];
        }
        if (res_e[i] + days[i] - 1 > n) { //判断是否有科目训练不完
            tag = false;
        }
    }
    for (int i = 0; i < m; i++) {  //输出最早开始时间
        cout << res_e[i] << " ";
    }
    if (tag) { //根据tag判断是否需要计算最晚开始时间
        for (int i = m - 1; i >= 0; i--) { //倒叙计算最晚开始时间
            int temp = INT_MAX;  //temp记录科目的边界：总天数 或 依赖给科目的科目的最晚开始时间
            if (i < m - 1) {
                for (int j = i + 1; j < m; j++) { //遍历后面的科目，判断当前科目是否被依赖
                    if (sbj[j] == i + 1) {  //如果存在依赖该科目的科目
                        temp = min(temp, res_l[j]);  //修改边界
                    }
                }
            }
            if (temp == INT_MAX) { //没有被依赖的科目
                res_l[i] = n - days[i] + 1;
            }
            else { //有被依赖的科目
                res_l[i] = temp - days[i];
            }
        }
        cout << endl;
        for (int i = 0; i < m; i++) { //输出最晚开始时间
            cout << res_l[i] << " ";
        }
    }
    return 0;
 
}
