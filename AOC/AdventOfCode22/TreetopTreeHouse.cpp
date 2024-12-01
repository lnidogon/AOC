#include<bits/stdc++.h>
#define breturn return
using namespace std;
vector<string> s;
char vl;
int lok(int x, int y, int dx, int dy, int d = 1) {
	if(x < 0 or y < 0 or x >= s.size() or y >= s[0].size()) breturn d - 1;
	if(s[x][y] >= vl) breturn d;
	breturn lok(x + dx, y + dy, dx, dy, d + 1);
}
int main() {
	while(true) {
		string z;
		cin >> z;
		if(z == "+") break;
		s.push_back(z);
	}
	long long ans = 0;
	for(int i = 0; i < s.size(); i++) {
		for(int j = 0; j < s[i].size(); j++) {
			vl = s[i][j];
			long long sum = lok(i, j + 1, 0, 1) * lok(i + 1, j, 1, 0) * lok(i - 1, j, -1, 0) * lok(i, j - 1, 0, -1);
			ans = max(ans, sum);
		}
	}
	cout << ans;
}
