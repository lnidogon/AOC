#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<pair<string, string> > &v, string &s) {
	fstream f;
	f.open("19_input.txt");
	while(getline(f, s)) {
		if(s == "") break;
		string s1, s2;
		if(s[1] == ' ') {
			s1 = s.substr(0, 1);
			s2 = s.substr(5);
		} else {
			s1 = s.substr(0, 2);
			s2 = s.substr(6);
		}
		v.push_back({s1, s2});
	}
	getline(f, s);
	
}

void solve(vector<pair<string, string> > &v, string &s) {
	set<string> st;
	string ss = "";
	for(int i = 0; i < s.size(); i++) {
		string s1 = "";
		string s2 = "";
		s1.push_back(s[i]);
		if(i < s.size() - 1) s2.push_back(s[i]), s2.push_back(s[i + 1]);
		for(auto t:v) {
			if(t.first == s1) st.insert(ss + t.second + s.substr(i + 1));
		 if(t.first == s2) st.insert(ss + t.second + s.substr(i + 2));
		}
		ss.push_back(s[i]);
	}
	cout << st.size() << '\n';
	
}
int main() {
	vector<pair<string, string> > v;
	string s;
	readline(v, s);
	solve(v, s);
}
