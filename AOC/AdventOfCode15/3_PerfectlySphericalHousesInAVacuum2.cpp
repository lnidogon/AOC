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
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, z = 0;
	st.insert({0, 0});
	int *x, *y;
	for(auto t:s) {
		if(z%2 == 0) x = &x1, y = &y1;
		else x = &x2, y = &y2;
		cout << *x << " " << *y <<" " <<z << '\n';
		if(t == '>') (*y)++;
		if(t == '<') (*y)--;
		if(t == 'v') (*x)--;
		if(t == '^') (*x)++;
		st.insert({*x, *y});
		z++;
	}
	cout << st.size();
}
int main() {
	string s;
	readline(s);
	solve(s);
}
