#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF = 2e18;

struct File {
	ll size; //文件大小，不是文件为0
	bool isFile; //是否为普通文件
	ll ld, lr; //设置上限
	ll ldsize, lrsize; //后代之和
	unordered_map<string, File*> child;
	File(ll sz, bool file) : size(sz), isFile(file), ld(INF), lr(INF), ldsize(0), lrsize(0) {}
};

//分割字符串
vector<string> split(const string& s, string c = " ") {
    vector<string> ans;
    for (ll i = 0, j = 0; i < s.size(); i = j + 1) {
        j = s.find(c, i);
        if (j == -1) {
            j = s.size();
        }
        ans.push_back(s.substr(i, j - i));
    }
    return ans;
}

ll fileSize(File *root, const vector<string> &path) {
	for (ll i = 1; i < path.size() && root; i++) {
		root = root->child.count(path[i]) ? root->child[path[i]] : nullptr;
	}
	return root && root->isFile ? root->size : 0;
} 

bool canCreatFile(File *root, const vector<string> path, ll sz) {
	for (ll i = 1; i < path.size() && root; i++) {
		if (root->isFile || root->lrsize + sz > root->lr ||(i == path.size()-1 && root->ldsize + sz > root->ld)) { //配额不对的时候就有问题了 
			return false;
		}
		root = root->child.count(path[i]) ? root->child[path[i]] : nullptr; 
	}
	return !root || root->isFile;
}

bool createFile(File *root, const vector<string> &path, ll sz) {
	ll curSize = fileSize(root, path); //求出当前的文件大小，因为你要看能不能修改； 
	sz -= curSize; //变化的值,差值 
	if (!canCreatFile(root, path, sz)) {
		return false;
	} 
	//可以创建
	for (ll i = 1; i < path.size()-1; i++) {
		root->lrsize += sz;
		if (!root->child.count(path[i])) {
			root->child[path[i]] = new File(0, false);
		}
		root = root->child[path[i]];
	} 
	//最后一个文件了path.back()
	root->ldsize += sz; root->lrsize += sz;
	if (!root->child.count(path.back())) {
		root->child[path.back()] = new File(0, true);
	}
	root->child[path.back()]->size += sz;
	return true;
}
// 删除文件 
void removeFile(File *root, const vector<string> &path) {
	// 删除的路径不存在
	auto r = root;
	for (ll i = 1; i < path.size() && r; i++) {
		r = r->child.count(path[i]) ? r->child[path[i]] : nullptr;
	} 
	if (!r) {
		return ;
	}
	ll sz = r->isFile ? r->size : r->lrsize;
	for (ll i = 1; i < path.size()-1 && root; i++) {
		root->lrsize -= sz;
		root = root->child[path[i]]; 
	}
	root->lrsize -= sz;
	if (r->isFile) {
		root->ldsize -= sz;
	}
	root->child.erase(path[path.size() - 1]);
} 

bool QFile(File* root, const vector<string>& path, ll ld, ll lr) {
    for (ll i = 1; i < path.size() and root; i++) {
        root = root->child.count(path[i]) ? root->child[path[i]] : nullptr;
    }
    if (not root or root->isFile or root->lrsize > lr or root->ldsize > ld) {
        return false;
    }
    root->lr = lr;
    root->ld = ld;
    return true;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    ll ni, ld, lr, sz;
    cin >> ni;
    string c, path;
    File* root = new File(0, false);  //表示根目录的结点
    while (ni--) {
        cin >> c >> path;
        auto pathSplit = split(path, "/");
        if (c == "C") {
            cin >> sz;
            if (createFile(root, pathSplit, sz)) {
            	cout<<"Y"<<endl;
			} else {
				cout<<"N"<<endl;
			}
        } else if (c == "R") {
            removeFile(root, pathSplit);
            cout<<"Y"<<endl;
        } else {
            cin >> ld >> lr;
            ld = ld == 0 ? INF : ld;
            lr = lr == 0 ? INF : lr;
            if (QFile(root, pathSplit, ld, lr)) {
            	cout<<"Y"<<endl;
			} else {
				cout<<"N"<<endl;
			}
        }
    }
	return 0;
}
