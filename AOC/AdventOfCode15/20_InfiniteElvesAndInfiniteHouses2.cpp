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
	for(int i = 1; i <= 2000000; i++) {
		int k = 0;
		for(int j = i; j <= 2000000 and k < 50; j += i) 
			v[j] += i * 11, k++;
	}
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
