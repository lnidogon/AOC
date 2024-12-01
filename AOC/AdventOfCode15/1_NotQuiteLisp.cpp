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
	for(auto t:s) 
		rez += (t == ')'?-1:1);
	cout << rez;
}

int main() {
	string s;
	readline(s);
	solve(s);
}
