#include<bits/stdc++.h>
#define breturn return
using namespace std;
int gx;
int mem[150][150];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int grap[50][50];
int glongest;
bool been[150];
void readline(vector<string> &v) {
	fstream f;
	f.open("input2.txt", ios::in);
	string s;
	while(getline(f, s)) v.push_back(s);
}
void testallpaths(int x, int dis, int dep = 0) {
	if(dep > 20) return;
	been[x] = true;
	glongest = max(glongest, dis);
	for(int i = 0; i <= gx; i++)   
		if(grap[x][i] and !been[i]) 
			testallpaths(i, dis + grap[x][i], dep ++);
	been[x] = false;
}
void congrap(vector<string> &v, int x, int y, int px, int py, int pg = 0, int dis = 1) {
	if(~mem[x][y]) {
		grap[pg][mem[x][y]] = dis;
		grap[mem[x][y]][pg] = dis;
		return;
	} else {
		int nd = 0;
		for(int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 0 and xx < v.size() and yy >= 0 and yy < v.size()) 
				nd += (v[xx][yy] != '.' and v[xx][yy] != '#');			
		}
		if(nd > 2 or (x == v.size()-1 and y == v.size()-2)) {
			mem[x][y] = ++gx;
			grap[pg][gx] = dis;				
			grap[gx][pg] = dis;
			pg = mem[x][y];
			dis = 0;
		}
	}
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx >= 0 and xx < v.size() and yy >= 0 and yy < v.size() and (xx != px or yy != py) and v[xx][yy] != '#') 
			congrap(v, xx, yy, x, y, pg, dis + 1);		
	}
}
void solve(vector<string> &v) {
	glongest = 0;
	gx = 0;
	memset(mem, -1, sizeof(mem));
	mem[0][1] = 0;
	congrap(v, 1, 1, 0, 1);
	int been[150];
	memset(been, 0, sizeof(been));
	testallpaths(0, 0);
	cout << glongest;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	vector<string> v;
	readline(v);
	solve(v);	
}
