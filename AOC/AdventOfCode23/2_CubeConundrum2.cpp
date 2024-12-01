#include<bits/stdc++.h>
#define breturn return
using namespace std;
string s;
int x, sum, r, g, b, z, ar, ag, ab;
int main() {
	while(true) {
		if(!scanf("Game %d: ", &x)) break;
		getline(cin, s);
		s += ';';
		bool poss = true;
		r = g = b = 0;
		ar = ag = ab = 0;
		z = 0;
		while(z < s.size()) {
		int y = min(s.find(',', z), s.find(';', z));
		string ss = s.substr(z, y - z);
		int val, p;
		if(ss[1] != ' ') val = (ss[0] - '0') * 10 + (ss[1] - '0'), p = 3;	
		else val = ss[0] - '0', p = 2;
		string sss = ss.substr(p);
		if(sss == "blue") b += val;
		else if(sss == "green") g += val;
		else if(sss == "red") r += val;
		if(s[y] == ';') ar = max(ar, r), ag = max(ag, g), ab = max(ab, b), r = g = b = 0;
		z = y + 2;
		}
		sum += ar * ag * ab;
	}
	cout << sum;
}
