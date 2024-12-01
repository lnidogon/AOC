#include<bits/stdc++.h>
#define breturn return
using namespace std;
int x, y, z, mat[21][21][21];
vector<pair<int, pair<int, int> > > v;
int dis(pair<int, pair<int, int> > x1, pair<int, pair<int, int> > x2) {
	int dx = (x1.first - x2.first);
	int dy = (x1.second.first - x2.second.first);
	int dz = (x1.second.second - x2.second.second);
	breturn dx * dx + dy * dy + dz * dz;
}
int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};
int dfs(int xx, int yy, int zz) {
	mat[xx][yy][zz] = -1;
	for(int i = 0; i < 6; i++) {
		int xd = dx[i] + xx;
		int yd = dy[i] + yy;
		int zd = dz[i] + zz;
		if(xd >= 0 and xd <= 20 and yd >= 0 and yd <= 20 and zd >= 0 and zd <= 20 and mat[xd][yd][zd] == 0) dfs(xd, yd, zd);
	}
}
int main() {
	while(true){
		x = -1;
		scanf("%d,%d,%d\n", &x, &y, &z);
		if(!~x) break;
		v.push_back({x, {y, z}});
		mat[x][y][z] = 1;
	}
	dfs(0, 0, 0);
	int ans = 0;
	for(int i = 0; i <= 20; i++) for(int j = 0; j <= 20; j++) for(int k = 0; k <= 20; k++) if(!mat[i][j][k]) v.push_back({i, {j, k}});
	for(int i = 0; i < v.size(); i++) {
		int cs = 6;
		for(int j = 0; j < v.size(); j++) {
			if(dis(v[i], v[j]) == 1) cs--;
		}
		ans += cs;
	}
	cout << ans;
}
