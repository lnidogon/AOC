#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(string &s) {
	fstream f;
	f.open("11_input.txt");
	getline(f, s);
}

void upd(int id, string &s) {
	if(s[id] == 'z') s[id] = 'a', upd(id - 1, s);
	else s[id]++;
}

void solve(string &s) {
	while(true) {
		upd(s.size() - 1, s);
		int poss = 0;
		for(int i = 0; i < s.size() - 2; i++) if(s[i + 1] == s[i] + 1 and s[i + 2] == s[i] + 2) poss++;
		if(!poss) continue;
		poss = 0;
		for(int i = 0; i < s.size() - 1; i++) poss += (s[i] == s[i + 1] and s[i] != s[i - 1]);
		if(poss < 2) continue;
		cout << s << '\n';
		return;
	}
}


int main() {
	string s;
	readline(s);
	solve(s);
}
