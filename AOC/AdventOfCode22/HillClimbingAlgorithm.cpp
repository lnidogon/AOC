#include<bits/stdc++.h>
#define breturn return
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, mem[300][300];
string s;
vector<string> mat;
queue<pair<int, int> > q;
int main() {
	while(true) {
		cin >> s;
		if(s == "+") break;
		mat.push_back(s);
	}
	n = mat.size(); 
	m = mat[0].size();
	int ex, ey;
	memset(mem, -1, sizeof(mem));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
		if(mat[i][j] == 'S' or mat[i][j] == 'a'){
		mem[i][j] = 0, q.push({i, j});
		mat[i][j] = 'a';
		} else if(mat[i][j] == 'E') {
			mat[i][j] = 'z';
			ex = i, ey = j;
		}
		
	}
	while(q.size()) {
		auto x = q.front();
		cout << x.first << " " << x.second << '\n';
		q.pop();
		for(int i = 0; i < 4; i++) {
			int xx = x.first + dx[i], yy = x.second + dy[i];
			if(xx >= 0 and xx < n and yy >= 0 and yy < m and mem[xx][yy] == -1 and mat[xx][yy] - mat[x.first][x.second] <= 1) {
				mem[xx][yy] = mem[x.first][x.second] + 1;
				q.push({xx, yy});
			} 
		}
	}
	cout << mem[ex][ey];
	
}
