#include<bits/stdc++.h>
#define breturn return
using namespace std;
string s;
vector<string> mat;
int dp[2001][2001], col, cols[2001][2001], dpa[2001 * 2001], sol, l;
int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {-1, 0, 1, 1, -1, 0, 1, -1};
set<int> stt;
int rek(int x, int y, int c) {
	cols[x][y] = col;
	if(mat[x][y+1] >='0' and mat[x][y+1] <='9') dp[x][y] = rek(x, y + 1, c * 10 + mat[x][y] - '0');
	else dp[x][y] = c * 10 + mat[x][y] - '0';
	return dp[x][y];
}
int main() {
	while(true) {
		cin >> s;
		if(s == "tvojamama") break;
		mat.push_back(s);
		l = s.size();
	}
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < mat.size(); i++) 
		for(int j = 0; j < l; j++) 
			if(dp[i][j] == -1 and mat[i][j] >= '0' and mat[i][j] <= '9') col++, dpa[col] = rek(i, j, 0); 
	for(int i = 0; i < mat.size(); i++) 
		for(int j = 0; j < l; j++) 
			if(mat[i][j] != '.' and (mat[i][j] > '9' or mat[i][j] < '0'))
				for(int k = 0; k < 8; k++) stt.insert(cols[i + dx[k]][j+dy[k]]); 
	for(auto t:stt) sol += dpa[t];
	cout << sol;
	
		
}
