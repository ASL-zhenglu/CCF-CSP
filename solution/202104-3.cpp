#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 10010;
int N, n; 
ll Tmin, Td, Tmax, ct, ti, Ip;
string se, re, type;

struct Info {
	int state; // 0-δ���� 1-������ 2-ռ�� 3-���� 
	ll time; //����ʱ��
	string user; //ռ���û� 
};
// 1. IP��ַ�Ƿ񶼱��ù���Ԥ�����Ż� 
// 2. ���Ż�����ʱ�� 
// 3. �ͷ�Ip��map�Ż� 
bool flag = false; 
// <��������> <��������> <��������> <IP ��ַ> <����ʱ��>

//vector<Info> ip(maxn);
Info ip[maxn];

void setTime(int t1, int i) {
	if (t1 != 0) {
		if (t1 < ct+Tmin) {
			ip[i].time = ct+Tmin;
		} else if (t1 > ct + Tmax) {
			ip[i].time = ct+Tmax;
		} else {
			ip[i].time = t1;
		}
	} else {
		ip[i].time = ct + Td;
	}
}


int find(int tt, string se) { //��ip 
	for (int i = 1; i <= N; i++) {
		if (ip[i].user == se) {
			ip[i].state = 1;
			setTime(tt, i);
			return i;
		}
	}
//	bool mark = false;
	for (int i = 1; i <= N; i++) { //��δ����� 
		if (ip[i].state == 0) {
			ip[i].state = 1;
			ip[i].user = se;
			setTime(tt, i);
			return i;
		}
	} 
	for (int i = 1; i <= N; i++) { //�ҹ��ڵ� 
		if (ip[i].state == 3) {
			ip[i].state = 1;
			ip[i].user = se;
			setTime(tt, i);
			return i;
		}
	}
	return 0;
}


int main() {
	string H; //���� 
	
	cin>>N>>Td>>Tmax>>Tmin>>H;
	cin>>n;
	
	for (int i = 0; i < n; i++) {
		cin>>ct>>se>>re>>type>>Ip>>ti;
//		if(re != H && re!="*") {
//            if(type != "REQ") continue;
//        }
//        if(type != "DIS" && type!="REQ") continue;
//		if((re == "*" && type != "DIS") || (re == H && type == "DIS")) continue;
		
		for (int j = 1; j <= N; j++) { //����  
			if (ip[j].state == 1 && ct >= ip[j].time) { //������ 
				ip[j].state = 0;
				ip[j].user = "";
				ip[j].time = 0;
			} else if (ip[j].state == 2 && ct >= ip[j].time) { //�ѷ��� 
				ip[j].state = 3;
				ip[j].time = 0;
			}
		}
		if (type == "DIS" || type == "REQ") { //���� 
			if (type == "DIS") {
				if (re == "*") {
					int p = find(ti, se); 
					if (p != 0) { // p=0������ 
						cout<<H<<" "<<se<<" "<<"OFR"<<" "<<p<<" "<<ip[p].time<<endl;
					}
				}
			} else {
				if (re != "*") {
					if (re != H) {
						for (int j = 1; j <= N; j++) {
							if (ip[j].state == 1 && ip[j].user == se) {
								ip[j].state == 0;
								ip[j].user = "";
								ip[j].time = 0;
							}
						}
					} else {
						if (Ip >= 1 && Ip <= N && ip[Ip].user == se) {
							ip[Ip].state = 2;
							setTime(ti, Ip);
							cout<<H<<" "<<se<<" "<<"ACK"<<" "<<Ip<<" "<<ip[Ip].time<<endl;
						} else {
							cout<<H<<" "<<se<<" "<<"NAK"<<" "<<Ip<<" "<<0<<endl;
						}
					}
				}
				
			}
		}
		
	}
	return 0;
}
