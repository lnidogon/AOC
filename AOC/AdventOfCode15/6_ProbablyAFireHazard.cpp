#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<pair<int, pair<pair<int, int>, pair<int, int> > > > &v) {
	fstream f;
	f.open("6_input.txt");
	string s;
	while(getline(f, s)) {
		int x1, x2, y1, y2;
		int z;
		int idx = 0, idnx;
		if(s[6] == ' ') z = 1, idx = 7;
		else if(s[7] == ' ') z = 2, idx = 8;
		else z = 3, idx = 9;
		idnx = s.find(",", idx);
		x1 = stoi(s.substr(idx, idnx - idx));
		idx = idnx + 1;
		idnx = s.find(" ", idx);
		y1 = stoi(s.substr(idx, idnx - idx));
		idx = idnx + 9;
		idnx = s.find(",", idx);
		x2 = stoi(s.substr(idx, idnx - idx));
		idx = idnx + 1;
		idnx = s.size();
		y2 = stoi(s.substr(idx, idnx - idx));
		v.push_back({z, {{x1, y1}, {x2, y2}}});
	}
}

void solve(vector<pair<int, pair<pair<int, int>, pair<int, int> > > > &v) {
	bool mat[1001][1001];
	memset(mat, 0, sizeof(mat));
	for(auto t:v) {
		for(int i = t.second.first.first; i <= t.second.second.first; i++) {
			for(int j = t.second.first.second; j <= t.second.second.second; j++) {
				if(t.first == 1) mat[i][j] ^= 1;
				else if(t.first == 2) mat[i][j] += 1;
				else mat[i][j] *= 0;
			}
		}
	}
	int ret = 0;
	for(int i = 0; i <= 1000; i++) for(int j = 0; j <= 1000; j++) ret += mat[i][j];
	cout << ret << '\n';
} 
int main() {
	vector<pair<int, pair<pair<int, int>, pair<int, int> > > > v;
	readline(v);
	solve(v);	
}
