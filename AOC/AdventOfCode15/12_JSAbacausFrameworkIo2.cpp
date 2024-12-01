#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<string> &v) {
	fstream f;
	f.open("12_input.txt");
	string s;
	while(getline(f, s)) v.push_back(s);
}
void solve(vector<string> &v) {
	int sum = 0;
	for(auto s:v) {
		s += ".";
		bool neg = false;
		int cn = 0;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '{') {
				bool isbad = false;
				int isinbody = 0;
				for(int j = i + 1; j < s.size(); j++) {
					if(!isinbody and j < s.size() - 2 and s[j] == 'r' and s[j + 1] == 'e' and s[j + 2] == 'd') isbad = true;
					if(s[j] == '{' or s[j] == '[') isinbody++;
					if(s[j] == '}' or s[j] == ']') isinbody--;
					if(isinbody < 0) {
						if(isbad) i = j + 1;
						break;
					}		
				}
				
			}
			if(s[i] == '-') neg = true;
			else if(s[i] >= '0' and s[i] <= '9') {
				cn *= 10;
				if(neg) cn -= (s[i] - '0');
				else cn += (s[i] - '0');
			} else {
				sum += cn;
				neg = false;
				cn = 0;
			}
		}
	}
	cout << sum;
}
int main() {
	vector<string> v;	
	readline(v);
	solve(v);
}
