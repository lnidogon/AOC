#include<bits/stdc++.h>
#define breturn return
using namespace std;
int x, y;
void readline(string &s) {
	fstream f;
	f.open("3_input.txt");
	f >> s;
}
void solve(string &s) {
	set<pair<int, int> > st;
	int x = 0, y = 0;
	st.insert({x, y});
	for(auto t:s) {
		if(t == '>') y++;
		if(t == '<') y--;
		if(t == 'v') x--;
		if(t == '^') x++;
		st.insert({x, y});
	}
	cout << st.size();
}
int main() {
	string s;
	readline(s);
	solve(s);
}
