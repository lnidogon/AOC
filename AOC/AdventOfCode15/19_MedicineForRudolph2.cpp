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
	string z = s;
	s = "";
	for(auto t:z) s.push_back(t);
}




void solve(vector<pair<string, string> > &v, string &s) {
	int n = 0;
	int a = 0;
	int b = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= 'A' and s[i] <= 'Z') n++;
		a += (s[i] == 'R' or s[i] == 'A' and s[i + 1] == 'r');
		b += (s[i] == 'Y');
	}
	cout << n - a - 2 * b - 1 <<'\n';
}
int main() {
	vector<pair<string, string> > v;
	string s;
	readline(v, s);
	solve(v, s);
}
