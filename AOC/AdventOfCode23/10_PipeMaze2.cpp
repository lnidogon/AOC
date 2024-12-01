#include<bits/stdc++.h>
#define breturn return
using namespace std;
vector<string> v;
//           0  1  2  3 
//           G  D  L  D
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int ox[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int oy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<pair<int, int> > path;
int mat[150][150];
map<char, pair<int, int> > m;
void readline(vector<string> &v) {
	string s;
	fstream f;
	f.open("input.txt", ios::in);
	while(getline(f, s)) v.push_back(s);
}
void dfs(int x, int y, int col) {
	if(x < 0 or x >= v.size() or y < 0 or y >= v[0].size()) return;
	mat[x][y] = col;
	for(int i = 0; i < 4; i++) if(!mat[x + dx[i]][y + dy[i]]) dfs(x + dx[i], y + dy[i], col);
}
void solve() {
	m['|'] = {0, 1};
	m['7'] = {1, 2};
	m['J'] = {0, 2};
	m['-'] = {2, 3};
	m['L'] = {0, 3};
	m['F'] = {1, 3};
	int x, y, px, py, ppx, ppy;
	for(int i = 0; i < v.size(); i++) for(int j = 0; j < v[0].size(); j++) if(v[i][j]  == 'S') px = i, py = j;
	path.push_back({px, py});
	x = px, y = py;
	do {
		if(x == px and y == py) x = x + dx[0], y = y + dy[0];
		else {
			auto dir = m[v[x][y]];
			if(x + dx[dir.first] == path[path.size() - 2].first and y + dy[dir.first] == path[path.size()-2].second) x += dx[dir.second], y += dy[dir.second];
			else x += dx[dir.first], y += dy[dir.first];
		}
		path.push_back({x, y});
	} while(x != px || y != py);
	for(auto t:path) mat[t.first][t.second] = 1;
	for(int i = 1; i < path.size() - 1; i++) {
		int prevx = path[i - 1].first, postx = path[i + 1].first, curx = path[i].first;
		int prevy = path[i - 1].second, posty = path[i + 1].second, cury = path[i].second;
		int g = -1, col = 2;
		for(int j = 0; j < 8; j++) if(curx + ox[j] == prevx and cury + oy[j] == prevy) g = j;
		for(int j = 0; j < 8; j++, g = (g + 1)%8) {
			int xx = curx + ox[g], yy = cury + oy[g];
			if(!mat[xx][yy]) dfs(xx, yy, col);
			if(xx == postx and yy == posty) col = 3;
		}
	}
	int nout = 0, noin = 0;
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[0].size(); j++) {
			if(mat[i][j] == 2) nout++;
			else if(mat[i][j] == 3) noin++;
		}
	}
	if(mat[0][0] == 3) cout << nout << '\n';
	else cout << noin;
} 
int main() {
	readline(v);
	solve();
}

