#include<bits/stdc++.h>
#define breturn return
using namespace std;
string s;
int sum, f, l;
int main() {
	while(true) {
		string ss;
		cin >> ss;
		if(ss == "tvojamama") break;
		s = "";
		for(int i = 0; i < ss.size(); i++) {
			if(ss[i] >= '0' and ss[i] <= '9') {
				s.push_back(ss[i]);
			}
			string sss = "";
			if(i <= ss.size() - 3) {
				sss = ss.substr(i, 3);
				if(sss == "one") s.push_back('1');
				if(sss == "two") s.push_back('2');
				if(sss == "six") s.push_back('6');
			} 
			if(i <= ss.size() - 4) {
				sss = ss.substr(i, 4);
				if(sss == "four") s.push_back('4');
				if(sss == "five") s.push_back('5');
				if(sss == "nine") s.push_back('9');
			} 
			if(i <= ss.size() - 5) {
				sss = ss.substr(i, 5);
				if(sss == "three") s.push_back('3');
				if(sss == "seven") s.push_back('7');
				if(sss == "eight") s.push_back('8');
			}
 		}
		 
		f = -1;
		for(auto t:s) {
			if(t >= '0' and t <= '9') {
				if(f == -1) f = t - '0';
				l = t - '0';
			}
		}
		cout << f*10+l << " " <<s << '\n';
		sum += f * 10 + l;
	}
	cout << sum;
}
