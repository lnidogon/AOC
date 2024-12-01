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
//	cout << k << " " << x << " " << y << '\n';
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

void solve(vector<string> &v) {
	dfs(v, 1, 0, 0);
	int ans = 0;
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[0].size(); j++) {
			ans++;
			if(bio[0][i][j]) cout << 'V';
			else if(bio[1][i][j]) cout << '>';
			else if(bio[2][i][j]) cout << '^';
			else if(bio[3][i][j]) cout << '<';
			else cout << '.', ans--;
		}
		cout << '\n';
	}
	cout << ans << '\n';
}
int main() {
	vector<string> v;
	readline(v);
	solve(v);
}
