#include<bits/stdc++.h>
#define breturn return
using namespace std;
int dp[150][150];
bool been[150][150];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void readline(vector<string> &v) {
	fstream f;
	f.open("input2.txt", ios::in);
	string s;
	while(getline(f, s)) v.push_back(s);
}

int rek(vector<string> &v, int x, int y, int px, int py) {
	if(been[x][y]) return dp[x][y];
	been[x][y] = 1;
	dp[x][y] = 0;
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx >= 0 and xx < v.size() and yy >= 0 and yy < v.size() and (xx != px or yy != py)) {
			char c = v[xx][yy];
			if(c == '.' or (c == '^' and i == 0) or (c == 'v' and i == 2) or (c == '>' and i == 1) or (c == '<' and i == 3))
				dp[x][y] = max(dp[x][y], 1 + rek(v, xx, yy, x, y));
		}
	}
	return dp[x][y];
}

void solve(vector<string> &v) {
	cout << rek(v, 0, 1, -1, -1);
}

int main() {
	vector<string> v;
	readline(v);
	solve(v);	
}
