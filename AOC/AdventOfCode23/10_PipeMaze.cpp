#include<bits/stdc++.h>
#define breturn return
using namespace std;
vector<string> v;
//        G   D  L  D
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<pair<int, int> > path;
int mat[150][150];
map<char, pair<int, int> > m;
void readline(vector<string> &v) {
	string s;
	fstream f;
	f.open("input.txt", ios::in);
	while(getline(f, s)) v.push_back(s);
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
	cout << path.size()/2 << '\n';
}

int main() {
	readline(v);
	solve();
}

