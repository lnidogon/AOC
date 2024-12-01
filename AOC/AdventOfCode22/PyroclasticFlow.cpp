#include<bits/stdc++.h>
#define breturn return
using namespace std;
string s;
vector<pair<int, int> > fx;
int mat[10000000][9], val[10000000];
bool stp = true; 
int x = 0, y = -1, mx = 0, asx, asy, asz;
int fq[5][100000];
bool mov(bool c) {
	int m = (c?1:-1);
	for(auto t:fx) if(mat[t.first - 1][t.second] or t.first - 1 < 0) breturn false;
	for(int i = 0; i < fx.size(); i++) fx[i].first--;		 
	for(auto t:fx) if(t.second + m < 0 or t.second + m >= 7 or mat[t.first][t.second + m]) breturn true;
	for(int i = 0; i < fx.size(); i++) fx[i].second += m;
	breturn true;
}

int main() {
	cout << (1000000000000LL-1759)%1745<<'\n';
	cout << 1555LL + 2750LL + (1000000000000LL-1759LL)/(1745LL) * 2738LL << " ";
	fstream f;
	f.open("bruh.txt");
	string s;	
	f >> s;
	//breturn 0;
	for(int i = 0; i < 1759 + 996/*1759 + 1745*/; i++) {		
		if(stp) {
			y++;
			y %= 5;
			fq[y][x]++;
			if(fq[y][x] > asx) asx = fq[y][x], asy = x, asz = y;
			fx.clear();
			if(y == 0) {
				fx.push_back({mx + 4, 2});
				fx.push_back({mx + 4, 3});
				fx.push_back({mx + 4, 4});
				fx.push_back({mx + 4, 5});
			} else if(y == 1) {
				fx.push_back({mx + 4, 3});
				fx.push_back({mx + 5, 2});
				fx.push_back({mx + 5, 3});
				fx.push_back({mx + 5, 4});
				fx.push_back({mx + 6, 3});
			} else if(y == 2) {
				fx.push_back({mx + 4, 2});
				fx.push_back({mx + 4, 3});
				fx.push_back({mx + 4, 4});
				fx.push_back({mx + 5, 4});
				fx.push_back({mx + 6, 4});
			} else if(y == 3) {
				fx.push_back({mx + 4, 2});
				fx.push_back({mx + 5, 2});
				fx.push_back({mx + 6, 2});
				fx.push_back({mx + 7, 2});
			} else if(y == 4) {
				fx.push_back({mx + 4, 2});
				fx.push_back({mx + 5, 2});
				fx.push_back({mx + 4, 3});
				fx.push_back({mx + 5, 3});
			}
			stp = false;
		}
		if(!mov(s[x] == '>')) {
			stp = true;
			for(auto t:fx) mx = max(mx, t.first + 1), mat[t.first][t.second] = 1; 
			continue;
		}
		x++;
		x %= s.size(); 
		i--;
	}
	cout << asx << " " << asy << " " << asz << '\n';
	for(int i= mx- 50; i <= mx; i++) {
		cout << i << ":";
		for(int j = 0; j < 7; j++) {
			cout << (mat[i][j]?'#':'.');
		}
		cout << '\n';
	}
	
	cout << mx << '\n';
}
