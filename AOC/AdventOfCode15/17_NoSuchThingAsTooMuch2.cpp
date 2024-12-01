#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<int> &v) {
	fstream f;
	f.open("17_input.txt");
	string s;
	while(getline(f, s)) {
		v.push_back(stoi(s));
	}
}
void solve(vector<int> &v) {
	int n = v.size();
	int x = 150;
	int ans[n + 1];
	memset(ans, 0, sizeof(ans));
	for(int i = 0; i < (1 << n); i++) {
		int sum = 0;
		for(int j = 0; j < n; j++) {
			if((i >> j)%2) sum += v[j];
			if(v[j] > x) break;
		}
		if(x == sum) 
			ans[__builtin_popcount(i)]++;
	}
	for(int i = 0; i <= n; i++) if(ans[i]) {
		cout << ans[i];
		return;
	}
}
int main() {
	vector<int> v;	
	readline(v);
	solve(v);
}
