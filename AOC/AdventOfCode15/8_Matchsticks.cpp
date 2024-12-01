#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<string> &v) {
	fstream f;
	f.open("8_input.txt");
	string s;
	while(getline(f, s)) 
		v.push_back(s);	
}
void solve(vector<string> &v) {
	int ans = 0;
	for(auto t:v) {
		int redund = 2;
		for(int i = 0; i < t.size(); i++) {
			if(t[i] == '\\') {
				redund++;
				i++;
				if(i < t.size() and t[i] == 'x') {
					redund+=2;
					i += 2;
				}
			}		
		}
		
		ans += (redund);
	}
	cout << ans << '\n';
}
int main() {
	vector<string> v;
	readline(v);
	solve(v);
}
