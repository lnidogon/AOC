#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(string &s) {
	fstream f;
	f.open("input.txt");
	f >> s;
}

void solve(string &s) {
	int rez = 0;
	for(int i = 0; i < s.size(); i++) {
		rez += (s[i] == ')'?-1:1);
		if(rez < 0) {
			cout << i + 1;
			return;
		}
	}
	
}

int main() {
	string s;
	readline(s);
	solve(s);
}
