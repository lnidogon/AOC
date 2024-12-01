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
		for(auto t:s) {
			if(t == '-') neg = true;
			else if(t >= '0' and t <= '9') {
				cn *= 10;
				if(neg) cn -= (t - '0');
				else cn += (t - '0');
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
