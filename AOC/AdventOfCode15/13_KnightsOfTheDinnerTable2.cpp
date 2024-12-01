#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<pair<int, pair<string, string> > > &v) {
	fstream f;
	f.open("13_input.txt");
	string s;
	while(getline(f, s)) {
		s[s.size() - 1] = ' ';
		int id = -1;
		int idnx = 0;
		string s1, s2, s3, s4;
		int x = 0;
		while(true) {
			idnx = s.find(" ", ++id);
			string subs = s.substr(id, idnx - id);
			id = idnx;
			if(x == 0) s1 = subs;
			if(x == 2) s2 = subs;
			if(x == 3) s3 = subs;
			if(x == 10) {
				s4 = subs;
				break;
			}
			x++;
		}
		int delt = stoi(s3);
		if(s2 == "lose") delt *= -1;
		v.push_back({delt, {s1, s4}}); 
	}
}
void solve(vector<pair<int, pair<string, string> > > &v) {
	set<string> s;
	s.insert("you");
	vector<string> vv;
	for(auto t:v) s.insert(t.second.first), s.insert(t.second.second);
	for(auto t:s) vv.push_back(t);
	for(auto t:vv) {
		v.push_back({0, {t, "you"}});
		v.push_back({0, {"you", t}});
	}
	int minx = 0;
	int n = vv.size();
	do {
		int sum = 0;
		for(int i = 0; i < n; i++) {
			string prv = vv[(i - 1 + n)%n];
			string nxt = vv[(i + 1)%n];
			string cur = vv[i];
			for(auto t:v) {
				if(t.second.first == cur and (t.second.second == prv or t.second.second == nxt)) sum += t.first; 
			}
		}
		minx = max(minx, sum);
	} while(next_permutation(vv.begin(), vv.end()));
	cout << minx << '\n';
}
int main() {
	vector<pair<int, pair<string, string> > > v;
	readline(v);
	solve(v);
}
