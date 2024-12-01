#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<string> &v) {
	fstream f;
	f.open("input2.txt", ios::in);
	string s;
	while(getline(f, s)) v.push_back(s);
	f.close();
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int mat[10 * 141][10 * 141];
int bfs(vector<string> &v, int x, int y, int k) {
	//cout << x << " " << y << '\n'; 
	memset(mat, -1, sizeof(mat));	
	queue<pair<int, pair<int, int> > > q;
	q.push({0, {x, y}});	
	mat[x][y] = 0;
	while(q.size()) {
		auto x = q.front();
	//	cout << x.second.first << " " << x.second.second << '\n';
		q.pop();
		for(int i = 0; i < 4; i++) {
			int xx = x.second.first + dx[i];
			int yy = x.second.second + dy[i];
			if(xx < 0 or yy < 0 or xx >= v.size() or yy >= v.size() or v[xx][yy] == '#') continue;
			if(mat[xx][yy] == -1) {
				mat[xx][yy] = mat[x.second.first][x.second.second] + 1;
				q.push({mat[xx][yy], {xx, yy}});
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v.size(); j++) {
			if(mat[i][j] <= k and mat[i][j]%2 == 0 and mat[i][j] != -1) ans++;
		}
	}
	return ans;
}

void solve(vector<string> &v) {
	cout << bfs(v, v.size()/2, v.size()/2, 64);
	
}
int main() {
	vector<string> v;	
	readline(v);
	solve(v);
}
