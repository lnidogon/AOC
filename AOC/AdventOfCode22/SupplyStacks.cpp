#include<bits/stdc++.h>
#define breturn return 
using namespace std;
int n = 9;
vector<char> v[10];
int main() {
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(auto t:s) v[i].push_back(t);
	}
	while(true) {
		int a = -1, b, c;
		scanf("\nmove %d from %d to %d", &a, &b, &c);
		if(a == -1) break;
		b--, c--;
		vector<int> m;
		m.clear();
		for(int i = 0; i < a; i++) m.push_back(v[b].back()), v[b].pop_back();
		while(m.size()) v[c].push_back(m.back()), m.pop_back();	
	}
	for(int i = 0; i < n; i++) cout << v[i].back();

}
