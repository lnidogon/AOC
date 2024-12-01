#include<bits/stdc++.h>
#define breturn return
#define f first
#define s second
using namespace std;
void readline(vector<string> &v) {
	fstream f;
	f.open("input2.txt", ios::in);
	string s;
	while(getline(f, s)) v.push_back(s);
	f.close();
}
int mem[4][12][150][150];
pair<pair<int, int>, pair<int, int> > par[4][12][150][150];
bool bio[150][150];


void solve(vector<string> &v) {
	set<pair<int, pair<pair<int, int>, pair<int, int> > > > s; 
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};	
	s.insert({0, {{1, 0}, {0, 0}}});
	s.insert({0, {{2, 0}, {0, 0}}});
	const int INF = 1e9;
	for(int i  = 0; i < 4; i++) for(int j = 0; j < 12; j++) for(int k = 0; k < v.size(); k++) for(int l = 0; l < v[0].size(); l++) mem[i][j][k][l] = INF;
	mem[1][0][0][0] = 0;
	mem[2][0][0][0] = 0;
	while(s.size()) {
		auto x = s.begin()->second;
		s.erase(s.begin());
		if(x.s.f == v.size() - 1 and x.s.s == v[0].size() - 1 and x.f.s >= 4) {
			s.clear();
			cout << mem[x.f.f][x.f.s][x.s.f][x.s.s] << '\n';
			while(x.s.f != 0 or x.s.s != 0) {
				bio[x.s.f][x.s.s] = 1;
				x = par[x.f.f][x.f.s][x.s.f][x.s.s];
			}
			for(int i = 0; i < v.size(); i++, cout << '\n') for(int j = 0; j < v[0].size(); j++) cout << bio[i][j];
			continue;
		}
		for(int i = 0; i < 4; i++) {
			int xx = x.s.f + dx[i];
			int yy = x.s.s + dy[i];
			int ll = i;
			int zz = 1;
			if(ll == x.f.f) zz = x.f.s + 1;
			if(xx < 0 or xx >= v.size() or yy < 0 or yy >= v[0].size() or zz > 10 or (x.f.s < 4 and ll != x.f.f) or (ll - x.f.f + 4)%4 == 2) continue;
			if(mem[ll][zz][xx][yy] > mem[x.f.f][x.f.s][x.s.f][x.s.s] + v[xx][yy] - '0') {
				auto it = s.find({mem[ll][zz][xx][yy], {{ll, zz},{xx, yy}}});
				if(it != s.end()) s.erase(it);
				mem[ll][zz][xx][yy] = mem[x.f.f][x.f.s][x.s.f][x.s.s] + v[xx][yy] - '0';
				s.insert({mem[ll][zz][xx][yy], {{ll, zz},{xx, yy}}});				
				par[ll][zz][xx][yy] = x;
			} 
		}
	}	
}
int main() {
	vector<string> v;
	readline(v);
	solve(v);
}
