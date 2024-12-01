#include<bits/stdc++.h>
#define breturn return
using namespace std;
int mem[3][35][100][35 * 100], p, fu[3][35*100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char mat[35][100][35 * 100];
queue<pair<pair<int, int>, pair<int, int> > > q;
string s;
int main() {
	p = 0;
	for(int i = 0; i < 35; i++) for(int j = 0; j < 100; j++) for(int k = 0; k < 3500; k++) mat[i][j][k] = '.';
	while(true) {
		cin >> s;
		if(s[2] != '#') {
			for(int i = 1; i < s.size() - 1; i++) mat[p][i - 1][0] = s[i];		
			p++;
		} else if(p) break;
	}
	int n = p, m = s.size() - 2;
	int o = n * m;
	memset(mem, -1, sizeof(mem)); 
	memset(fu, -1, sizeof(fu));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(mat[i][j][0] == '>') for(int k = 1; k < n * m; k++) mat[i][(j + k)%m][k] = '#';
			else if(mat[i][j][0] == '<') for(int k = 1; k < n * m; k++) mat[i][(j - k + n * m)%m][k] = '#';
			else if(mat[i][j][0] == 'v') for(int k = 1; k < n * m; k++) mat[(i + k)%n][j][k] = '#';
			else if(mat[i][j][0] == '^') for(int k = 1; k < n * m; k++) mat[(i - k + n * m)%n][j][k] = '#';
		}
	}
	//for(int k = 0; k < o; k++, cout << "\n\n") for(int i = 0; i < n; i++, cout << '\n') for(int j = 0; j < m; j++) cout << mat[i][j][k];
	cout << n << " " << m <<  " " << o << '\n';
	q.push({{-1, 0}, {0, 0}});
	while(q.size()) {
		auto x = q.front().first.first, y = q.front().second.first, z = q.front().second.second, w = q.front().first.second;
		q.pop();
		if(x == n - 1 and y == m - 1 and w == 0) {
			fu[1][(z + 1)%o] = mem[w][x][y][z] + 1;
			q.push({{-1, 1}, {0, (z + 1)%o}});
		} else if(x == n - 1 and y == m - 1 and w == 2) {
			breturn cout << mem[2][x][y][z], 0;
		} else if(x == 0 and y == 0 and w == 1) {
			fu[2][(z + 1)%o] = mem[w][x][y][z] + 1;
			q.push({{-1, 2},{0, (z + 1)%o}});
		}
		if(x == -1 and w == 0) {
			int xx = x + 1, yy = y, zz = (z + 1)%o;
			if(mat[xx][yy][zz] == '.' and mem[0][xx][yy][zz] == -1) mem[0][xx][yy][zz] = zz, q.push({{xx, 0}, {yy, zz}});
			if(zz != o) q.push({{x, 0}, {yy, zz}});
		} else if(x == -1 and w == 1) { 
			int xx = n - 1, yy = m - 1, zz = (z + 1)%o;
			if(fu[1][zz] == -1) fu[1][zz] = fu[1][z] + 1, q.push({{-1, 1}, {0, zz}});
			if(mat[xx][yy][zz] == '.' and mem[1][xx][yy][zz] == -1) mem[1][xx][yy][zz] = fu[1][z] + 1, q.push({{xx, w}, {yy, zz}});
		} else if(x == -1 and w == 2) { 
			int xx = 0, yy = 0, zz = (z + 1)%o;
			if(fu[2][zz] == -1) fu[2][zz] = fu[2][z] + 1, q.push({{-1, 2}, {0, zz}});
			if(mat[xx][yy][zz] == '.' and mem[2][xx][yy][zz] == -1) mem[2][xx][yy][zz] = fu[2][z] + 1, q.push({{xx, w}, {yy, zz}});
		} else {
			for(int i = 0; i < 4; i++) {
				int xx = x + dx[i], yy = y + dy[i], zz = (z + 1)%o;
				if(xx >= 0 and xx < n and yy >= 0 and yy < m and mat[xx][yy][zz] == '.' and mem[w][xx][yy][zz] == -1) mem[w][xx][yy][zz] = mem[w][x][y][z] + 1, q.push({{xx, w}, {yy, zz}});	
			}
			if(mat[x][y][(z + 1)%o] == '.' and mem[w][x][y][(z + 1)%o] == -1) mem[w][x][y][(z + 1)%o] = mem[w][x][y][z] + 1, q.push({{x, w}, {y, (z + 1)%o}});
		}
	}
	
}
