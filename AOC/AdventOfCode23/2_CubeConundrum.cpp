#include<bits/stdc++.h>
#define breturn return
using namespace std;
string s;
int x, sum, r, g, b, z;
int main() {
	while(true) {
		if(!scanf("Game %d: ", &x)) break;
		getline(cin, s);
		s += ';';
		bool poss = true;
		r = 12, g = 13, b = 14;
		z = 0;
		while(z < s.size()) {
		int y = min(s.find(',', z), s.find(';', z));
		string ss = s.substr(z, y - z);
		int val, p;
		if(ss[1] != ' ') val = (ss[0] - '0') * 10 + (ss[1] - '0'), p = 3;	
		else val = ss[0] - '0', p = 2;
		string sss = ss.substr(p);
		if(sss == "blue") b -= val;
		else if(sss == "green") g -= val;
		else if(sss == "red") r -= val;
		poss *= (b >= 0 and g >= 0 and r >= 0); 
		if(s[y] == ';') r = 12, g = 13, b = 14;
		z = y + 2;
		}
		sum += x * poss;		
	}
	cout << sum;
}
