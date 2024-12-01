#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(string &s) {
	fstream f;
	f.open("10_input.txt");
	getline(f, s);
}
void solve(string &s) {
	vector<int> v;
	for(auto t:s) v.push_back(t - '0');
	v.push_back(-1);
	int nop = 50;
	while(nop--) {
		vector<int> vv;
		int cn = v[0];
		int cs = 1;
		for(int i = 1; i < v.size(); i++) {
			if(v[i] != v[i - 1]) {
				vv.push_back(cs);
				vv.push_back(cn);
				cs = 1;
				cn = v[i];
			} else cs++;
		}
		v = vv;
		v.push_back(-1);
		vv.clear();
	}
	cout << v.size() -1  << '\n';
}

int main() {
	string s;
	readline(s);
	solve(s);
}
