#include<bits/stdc++.h>
#define breturn return
using namespace std;
string s;
int main() {
	cin >> s;
	
	for(int i = 0; i < s.size(); i++) {
		set<int> st;
		st.clear();
		for(int j = 0; j < 14; j++) st.insert(s[i + j]);
		if(st.size() == 14) {
			cout << i + 14;
			breturn 0;
		}	
	}
}
