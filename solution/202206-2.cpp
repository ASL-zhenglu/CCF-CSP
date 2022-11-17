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

int n, L, S;
set<pair<int, int>> st;
vector<vector<int>> Svec;
int main()
{
    read(n),read(L),read(S);
    Svec.resize(S+1,vector<int>(S+1));
    int x, y;
    for(int i = 0;i < n;i++) {
        read(x),read(y);
        st.insert({x,y});
    }
    for(int i = 0;i <= S;i++) {
        for(int j = 0;j <= S;j++) {
            read(Svec[S-i][j]);
        }
    }
    function<bool(int, int)> helper = [&](int x, int y) {
        for(int i = 0;i <= S;i++) {
            for(int j = 0;j <= S;j++) {
                if((Svec[i][j] && !st.count({x+i, y+j})) || (!Svec[i][j] && st.count({x+i,y+j}))) {
                    return false;
                }
            }
        }
        return true;
    };
    int ans = 0;
    for(auto &s : st) {
        if(s.first+S > L || s.second+S > L) continue;
        ans += helper(s.first, s.second);
    }
    cout<<ans;
//     system("pause");
    return 0;
}
