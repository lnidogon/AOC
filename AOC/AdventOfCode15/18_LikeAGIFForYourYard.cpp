#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<string> &v) {
	fstream f;
	f.open("18_input.txt");
	string s;
	while(getline(f, s)) 
		v.push_back(s);	
}

int nolit(vector<string> &v, int x, int y) {
	int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
	int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int ret = 0;
	for(int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx < 0 or yy < 0 or xx >= v.size() or yy >= v[0].size()) continue;
		if(v[xx][yy] == '#') ret++;
	}
	return ret;
}

void solve(vector<string> &v) {
	bool mat[101][101];
	int x = 100;
	while(x--) {
		memset(mat, 0, sizeof(mat));
		for(int i = 0; i < v.size(); i++) {
			for(int j = 0; j < v[0].size(); j++) {
				int cnt = nolit(v, i, j);
				if(v[i][j] == '#' and (cnt == 2 or cnt == 3) or v[i][j] == '.' and cnt == 3) mat[i][j] = 1; 
			}
		}
		for(int i = 0; i < v.size(); i++) for(int j = 0; j < v[0].size(); j++) v[i][j] = (mat[i][j]?'#':'.');		
	}
	int ans = 0;
	for(int i = 0; i < v.size(); i++) for(int j = 0; j < v[0].size(); j++) ans += (v[i][j] == '#');
	cout <<ans << '\n';
}
int main() {
	vector<string> v;
	readline(v);
	solve(v);
}
