#include<bits/stdc++.h>
#define breturn return
using namespace std;

struct Quer {
	char dir;
	int len;
	string col;
	Quer(char dir, int len, string col) : dir(dir), len(len), col(col) {}
};

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int chd[100];
bool been[1000][1000];
bool mat[1000][1000];

void dfs(int x, int y) {
	vector<pair<int, int> > v;
	v.push_back({x, y});
	while(v.size()) {
		auto x = v.back().first;
		auto y = v.back().second;
		been[x][y] = 1;
		v.pop_back();
		for(int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(mat[xx][yy] == 0 and been[xx][yy] == 0) v.push_back({xx, yy});
		}
	}
}

void readline(vector<Quer> &v) {
	string s;
	fstream f;
	f.open("input2.txt", ios::in);
	while(getline(f, s)) {
		char a = s[0];
		int x = s.find(" ", 2);
		int b = stoi(s.substr(2, x - 2));
		string c = s.substr(x + 3);
		c.pop_back();
		v.push_back(Quer(a, b, c));
	}
}
void solve(vector<Quer> &v) {
	ofstream of;
	of.open("output.txt");
	chd['U'] = 0;
	chd['D'] = 2;
	chd['L'] = 3;
	chd['R'] = 1;
	memset(mat, 0, sizeof(mat));
	int cx = 500, cy = 500;
	for(auto t:v) {
		cout << cx << " " << cy << " " << t.col << '\n';
		int sm = chd[t.dir];
		for(int i = 0; i < t.len; i++) {
			cx += dx[sm];
			cy += dy[sm];
			mat[cx][cy] = 1;
			cout << cx << " " << cy <<'\n';
		}
	}	
	dfs(501, 501);
	int ans = 0;
	for(int i = 0; i < 1000; i++) {
		for(int j = 0; j < 1000; j++) {			
			ans += (been[i][j] or mat[i][j]);
			of << (been[i][j]?"#":" ");
		}
		of << '\n';
	}
	cout << ans;
	of.close();
}

int main() {
	vector<Quer> v;
	readline(v);
	solve(v);
}
