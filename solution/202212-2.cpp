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
        if (sbj[i] == 0) {  //û������������Ŀ
            res_e[i] = 1;
        }
        else { //����������Ŀ����Ҫ���㱻������Ŀ�Ľ���ʱ��
            res_e[i] = res_e[sbj[i] - 1] + days[sbj[i] - 1];
        }
        if (res_e[i] + days[i] - 1 > n) { //�ж��Ƿ��п�Ŀѵ������
            tag = false;
        }
    }
    for (int i = 0; i < m; i++) {  //������翪ʼʱ��
        cout << res_e[i] << " ";
    }
    if (tag) { //����tag�ж��Ƿ���Ҫ��������ʼʱ��
        for (int i = m - 1; i >= 0; i--) { //�����������ʼʱ��
            int temp = INT_MAX;  //temp��¼��Ŀ�ı߽磺������ �� ��������Ŀ�Ŀ�Ŀ������ʼʱ��
            if (i < m - 1) {
                for (int j = i + 1; j < m; j++) { //��������Ŀ�Ŀ���жϵ�ǰ��Ŀ�Ƿ�����
                    if (sbj[j] == i + 1) {  //������������ÿ�Ŀ�Ŀ�Ŀ
                        temp = min(temp, res_l[j]);  //�޸ı߽�
                    }
                }
            }
            if (temp == INT_MAX) { //û�б������Ŀ�Ŀ
                res_l[i] = n - days[i] + 1;
            }
            else { //�б������Ŀ�Ŀ
                res_l[i] = temp - days[i];
            }
        }
        cout << endl;
        for (int i = 0; i < m; i++) { //�������ʼʱ��
            cout << res_l[i] << " ";
        }
    }
    return 0;
 
}
