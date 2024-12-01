#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;
string s;
ll sum, cs;
int main() {
	while(true) {
		cin >> s;
		if(s == "+") break;
		cs = 0;
		for(ll i = 0; i < s.size(); i++) {
			cs *= 5;
			if(s[i] == '2') cs += 2;
			if(s[i] == '1') cs += 1;
			if(s[i] == '0') cs += 0;
			if(s[i] == '-') cs += -1;
			if(s[i] == '=') cs += -2;			
		}
		sum += cs;

	}		
	ll mx[100], mn[100], cp;
	mx[0] = 2, mn[0] = -2; 
	for(ll i = cp = 1; i  <= 20; i++) cp *= 5, mx[i] = mx[i - 1] * 5 + 2, mn[i] = mn[i - 1] * 5 - 2;
		cout << sum << '\n';
		cout << cp << '\n';
		for(int i = 19; i >= 0; i--) {
			if(sum - 2 * cp >= mn[i] and sum - 2 * cp <= mx[i]) sum -= 2 * cp, cout << 2;
			else if(sum - 1 * cp >= mn[i] and sum - 1 * cp <= mx[i]) sum -= 1 * cp, cout << 1;
			else if(sum + 1 * cp >= mn[i] and sum + 1 * cp <= mx[i]) sum += 1 * cp, cout << '-';
			else if(sum + 2 * cp >= mn[i] and sum + 2 * cp <= mx[i]) sum += 2 * cp, cout << '=';
			else cout << 0;
			cp /= 5;
	}
	cout << sum;
}
