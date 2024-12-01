#include<bits/stdc++.h>
#define breturn return
using namespace std;
string s;
int sum, f, l;
int main() {
	while(true) {
		cin >> s;
		f = -1;
		if(s == "tvojamama") break;
		for(auto t:s) {
			if(t >= '0' and t <= '9') {
				if(f == -1) f = t - '0';
				l = t - '0';
			}
		}
		sum += f * 10 + l;
	}
	cout << sum;
}
