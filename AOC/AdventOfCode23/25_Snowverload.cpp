#include<bits/stdc++.h>
#define breturn return
using namespace std;

int has(string s) {
	const int b = 30;
	return (s[0]-'a') * b * b + (s[1]-'a') * b + s[2]-'a';
}

void readline(int (&grap)[1500][1500], int &gx) {
	int *mem = new int[27000];
	gx = 0;
	fstream f;
	f.open("input2.txt", ios::in);
	string s;
	memset(grap, 0, sizeof(grap));
	while(getline(f, s)) {
		cout << s << '\n';
		int a = has(s.substr(0, 3));
		if(mem[a] == 0) mem[a] = ++gx;
		a = mem[a];
		int x = 5;
		while(x < s.size()) {
			int y = has(s.substr(x, 3));
			if(mem[y] == 0) mem[y] = ++gx;
			y = mem[y];
			grap[a][y]++;
			grap[y][a]++;
			x += 4;
		}
	}
	delete []mem;
}


bool dijkstra(int (&grap)[1500][1500], int des, int gx) {
	int mem[1500], par[1500];
	for(int i = 1; i <= gx; i++) mem[i] = 0;
	mem[1] = 1e9;
	set<pair<int, int> > s;
	s.insert({1e9, 1});
	while(s.size()) {
		auto x = *s.begin();
		s.erase(s.begin());
		for(int i = 0; i <= gx; i++) {
			if(mem[i] < min(grap[x.second][i], x.first)) {
				auto it = s.find({mem[i], i});
				if(it != s.end()) s.erase(it);
				par[i] = x.second;
				
				mem[i] = min(grap[x.second][i], x.first);
				s.insert({mem[i], i});
			}
		}
	}
	int f = mem[des];
	if(!f) return false;
	while(des != 1) {
		int desc = par[des];
		grap[desc][des] -= f;
		grap[des][desc] += f;
		des = desc;
	}
	return true;
}

int dfs(int (&grap)[1500][1500], bool (&been)[1500], int &gx, int x) {
	int ret = 1;
	been[x] = true;
	for(int i = 1; i <= gx; i++) if(grap[x][i] and !been[i]) ret += dfs(grap, been, gx, i);
	return ret;
}


int grap[1500][1500], ograp[1500][1500];

void solve(int (&grap)[1500][1500], int &gx) { 
	int par[1500];
	int mem[1500];
	for(int i = 1; i <= gx; i++) for(int j = 1; j <= gx; j++) ograp[i][j] = grap[i][j];
	while(dijkstra(grap, gx, gx));
	bool been[1500];
	memset(been, 0, sizeof(been));
	int a = dfs(grap, been, gx, 1);
	cout << a << " " << gx - a<< " " << a * (gx - a) <<'\n';
}


int mem[27000];

int main() {
	int gx;
	readline(grap, gx);
	solve(grap, gx);	
}
