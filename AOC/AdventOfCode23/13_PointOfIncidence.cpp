#include<bits/stdc++.h>
#define breturn return
using namespace std;
vector<vector<string>> v;
void readline(vector<vector<string> > &v) {
	string s;
	fstream f;
	f.open("input2.txt", ios::in);
	int x = 0;
	vector<string> v2;
	v.push_back(v2);
	while(true) {
		if(getline(f, s) == false) 
			break;		
		else {
			if(s ==  "") v.push_back(v2);
			else v.back().push_back(s);							
		}
	}
	for(auto z:v) {
		for(int i = 0; i < z.size(); i++) {
			cout << z[i] << '\n';
		}
		cout << "okay\n";
	}
	f.close();
}

bool rowSym(vector<string> &v, int x) {
	int y = x + 1;
	while(x >= 0 and y < v.size()) {
		for(int j = 0; j < v[0].size(); j++) {
			if(v[x][j] != v[y][j]) return false;
		}
		x--;
		y++;		
	}
	return true;
}
bool colSym(vector<string> &v, int x) {
	int y = x + 1;
	while(x >= 0 and y < v[0].size()) {
		for(int j = 0; j < v.size(); j++) {
			if(v[j][x] != v[j][y]) return false;
		}
		x--;
		y++;		
	}
	return true;
}



void solve(vector<vector<string> > &v) {
	int ans = 0;
	for(int k = 0; k < v.size(); k++) {
		for(int i = 0; i < v[k].size() - 1; i++) 
			if(rowSym(v[k], i)) ans += (100) * (i + 1);		
		for(int i = 0; i < v[k][0].size() - 1; i++) 
			if(colSym(v[k], i)) ans += i + 1;		
	}
	cout << ans;
}

int main() {
	readline(v);
	solve(v);
}
