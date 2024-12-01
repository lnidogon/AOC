#include<bits/stdc++.h>
#define breturn return
using namespace std;
int ans, sum;
vector<int> v;
int main() {
	string s;
	while(true) {
		getline(cin, s);
		if(s == ".") break;
		if(s.size() == 0) v.push_back(sum), sum = 0;
		else {
			int k = 0;
			for(int i = 0; i < s.size(); i++) {
				k *= 10;
				k += (s[i] - '0');
			}
			sum += k;
		}	
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	cout << v[0] + v[1] + v[2];
}
