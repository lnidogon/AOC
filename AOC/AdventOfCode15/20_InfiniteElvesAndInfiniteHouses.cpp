#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(int &n) {
	fstream f;
	f.open("20_input.txt");
	string s;
	getline(f, s);
	n = stoi(s);
}
int v[2000000];
void solve(int &n) {
	for(int i = 1; i <= 2000000; i++) 
		for(int j = i; j <= 2000000; j += i) 
			v[j] += i * 10;
	for(int x = 0;;x++) {
		if(v[x] >= n) {
			cout << x << '\n';
			return;
		}
	}
}
int main() {
	int n;	
	readline(n);
	solve(n);
}
