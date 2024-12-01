#include<bits/stdc++.h>
#define breturn return
using namespace std;

void readline(vector<pair<int, pair<string, string> > > &v) {
	fstream f;
	f.open("9_input.txt");
	string s;
	while(getline(f, s)) {
		int id = -1;
		int idnx = 0;
		string s1, s2;
		int x;
		for(int i = 0; i < 5; i++) {
			idnx = s.find(" ", ++id);
			string ss = s.substr(id, idnx - id);
			if(i == 0) s1 = ss;
			if(i == 2) s2 = ss;
			if(i == 4) x = stoi(ss);
			id = idnx;
		}
		v.push_back({x, {s1, s2}});
	}
}

void solve(vector<pair<int, pair<string, string> > > &v) {
	set<string> s;
	vector<string> nm;
	map<pair<string, string>, int> m;
	for(auto t:v) s.insert(t.second.first), s.insert(t.second.second), m[{t.second.first, t.second.second}] = t.first, m[{t.second.second, t.second.first}] = t.first;
	for(auto t:s) nm.push_back(t);
	int minx = 0;
	do {
		int sum = 0;
		for(int i = 0; i < nm.size() - 1; i++) sum += m[{nm[i], nm[i + 1]}];
		minx = max(minx, sum);
	} while(next_permutation(nm.begin(), nm.end()));
	cout << minx <<'\n';
}

int main() {
	vector<pair<int, pair<string, string> > > v;	
	readline(v);
	solve(v);
}
