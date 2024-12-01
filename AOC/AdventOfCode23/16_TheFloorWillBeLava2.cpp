#include<bits/stdc++.h>
#define breturn return
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool bio[4][150][150];
void readline(vector<string> &v) {
	string s;
	fstream f;
	f.open("input2.txt", ios::in);
	while(getline(f, s)) v.push_back(s);
}
void dfs(vector<string> &v, int k, int x, int y) {
	if(x < 0 or y < 0 or x >= v.size() or y >= v[0].size()) return;
	if(bio[k][x][y]) return;
	bio[k][x][y] = 1;
	if(v[x][y] == '.' or (v[x][y] == '-' and k%2 == 1) or (v[x][y] == '|' and k%2 == 0)) dfs(v, k, x + dx[k], y + dy[k]);
	else if(v[x][y] == '-') {
		dfs(v, 1, x, y + 1);
		dfs(v, 3, x, y - 1);
	} else if(v[x][y] == '|') {
		dfs(v, 0, x + 1, y);
		dfs(v, 2, x - 1, y);
	}
	else {
		int kk;
		if(k%2 == 1) kk = (k + 1)%4;
		else kk = (k + 3)%4;
		if(v[x][y] == '\\') kk = (kk + 2)%4;
		dfs(v, kk, x + dx[kk], y + dy[kk]);
	}
}

int cnt(vector<string> &v) {
	int ret = 0;
	for(int i = 0; i < v.size(); i++) 
		for(int j = 0; j < v[0].size(); j++) 
			if(bio[0][i][j] + bio[1][i][j] + bio[2][i][j] + bio[3][i][j]) ret++;
	memset(bio, 0, sizeof(bio));
	return ret;
}
void solve(vector<string> &v) {
	int ans = 0;
	for(int i = 0; i < v.size(); i++) {
		dfs(v, 1, i, 0);
		ans = max(ans, cnt(v));
		dfs(v, 3, i, v[0].size() - 1);
		ans = max(ans, cnt(v));
	}
	for(int i = 0; i < v[0].size(); i++) {
		dfs(v, 0, 0, i);
		ans = max(ans, cnt(v));
		dfs(v, 2, v[0].size() - 1, i);
		ans = max(ans, cnt(v));
	}
	cout << ans << '\n';
}
int main() {
	vector<string> v;
	readline(v);
	solve(v);
}
