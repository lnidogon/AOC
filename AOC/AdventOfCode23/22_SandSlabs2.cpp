#include<bits/stdc++.h>
#define breturn return
using namespace std;
int mat[350][350][350];
bool been[1500], poss[1500];
int ret[1500];
set<int> dep[1500], beg;
vector<int> grap[1500];
int vist[1500];


void readline(vector<int> (&v)[6]) {
	fstream f;
	f.open("input2.txt", ios::in);
	string s;
	while(getline(f, s)) {
		int x = 0, y = 0;
		s += '~';
		for(int j = 0; j < 6; j++) {
			y = min(s.find(',', x), s.find('~', x));
			v[j].push_back(stoi(s.substr(x, y - x)));
			x = y + 1; 
		}
	}
}
void filcub(int x1, int y1, int z1, int x2, int y2, int z2, int col) {
	for(int i = x1; i <= x2; i++) for(int j = y1; j <= y2; j++) for(int k = z1; k <= z2; k++) mat[i][j][k] = col;
}

int rek(vector<int> (&v)[6], int id) {
	if(been[id]) return ret[id];
	int x1 = v[0][id];
	int y1 = v[1][id];
	int z1 = v[2][id];
	int x2 = v[3][id];
	int y2 = v[4][id];
	int z2 = v[5][id];
	been[id] = 1;
	ret[id] = z2 - z1 + 1;
	for(int i = x1; i <= x2; i++) 
		for(int j = y1; j <= y2; j++) 
			for(int k = z1 - 1; k >= 0; k--) 
	if(~mat[i][j][k]) {
		int p = rek(v, mat[i][j][k]) + z2 - z1 + 1;
		if(p < ret[id]) continue;
		if(p > ret[id]) {
			dep[id].clear();
			ret[id] = p;
		}	
		dep[id].insert(mat[i][j][k]);						
	}	
	return ret[id];
}


int rek2(int x, bool b = true) {
	vist[x]++;
	//cout << x << " _ " << b << " " << vist[x] << " " << dep[x].size() << '\n';
	if(vist[x] == dep[x].size() or b) {
		int ret = !b;
		for(auto t:grap[x]) {
			ret += rek2(t, false);
		}
		return ret;
	} 
	return 0;
 	
}

void solve(vector<int> (&v)[6]) {
	memset(mat, -1, sizeof(mat));
	for(int i = 0; i < v[0].size(); i++) 
		filcub(v[0][i], v[1][i], v[2][i], v[3][i], v[4][i], v[5][i], i);
	for(int k = 349; k >= 0; k--) for(int i = 0; i < 350; i++) for(int j = 0; j < 350; j++) 
		if(~mat[i][j][k] and !been[mat[i][j][k]]) 
			rek(v, mat[i][j][k]);
	for(int i = 0; i < v[0].size(); i++) {
		if(dep[i].size() == 1) beg.insert(*dep[i].begin());
		for(auto t:dep[i]) grap[t].push_back(i);
	}
	
	int ans = 0;
	for(auto t:beg) {
		ans += rek2(t);
		memset(vist, 0, sizeof(vist));
	}
	cout << ans << '\n';

}

int main() {
	vector<int> v[6];
	readline(v);
	solve(v);
}
