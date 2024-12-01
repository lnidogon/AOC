#include<bits/stdc++.h>
#define breturn return
using namespace std;
string s;
string ans[6];
int v, x = -1, cs = 1;
int main() {
	for(int i = 0; i < 6; i++) ans[i] = "........................................";
	while(true) {
		cout << x << " " << cs << "x\n";
		cin >> s;
		if(s == "+") break;
		if(s == "noop") {
			x++; 	
			if(x%40 >= cs - 1 and x%40 <= cs + 1) ans[x/40][x%40] = '#';
			else ans[x/40][x%40] = '.';
		} else {
			x++;
			if(x%40 >= cs - 1 and x%40 <= cs + 1) ans[x/40][x%40] = '#';
			else ans[x/40][x%40] = '.';
			x++;
			if(x%40 >= cs - 1 and x%40 <= cs + 1) ans[x/40][x%40] = '#';
			else ans[x/40][x%40] = '.';
			cin >> v;
			cs += v;					
		}
	}
	for(int i = 0; i < 6; i++) cout << ans[i] << '\n';
}
