#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;

void readline(ll &a, ll &b) {
	fstream f;
	f.open("25_input.txt");
	string s;
	getline(f, s);
	a = stoi(s.substr(80, 4));
	b = stoi(s.substr(93, 4));
}
void solve(ll &a, ll &b) {
	ll c = (a + b);
	ll p = (c - 1) * (c - 2) / 2 + b;
	ll x = 20151125;
	for(int i = 0; i < p - 1; i++) x = (x * 252533)%33554393;
	cout <<x<<'\n';	
}

int main() {
	ll a, b;
	readline(a, b);
	solve(a, b);
}
