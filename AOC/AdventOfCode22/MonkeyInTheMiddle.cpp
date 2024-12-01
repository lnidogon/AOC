#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;
const ll n = 8;
const ll mod = 9699690;
vector<pair<ll, ll> > ret;
struct Monkey {
	vector<ll> it;
	string s1, s2, s3;
	ll dx, rec1, rec2;
	ll ans = 0;
	ll opt(ll x0) {
		ans++;
		ll x, y;
		if(s1.size() == 1) x = s1[0]-'0';
		else if(s1.size() == 2) x = (s1[0] - '0') + s1[1] - '0';
		else x = x0;
		if(s2.size() == 1) y = s2[0]-'0';
		else if(s2.size() == 2) y = (s2[0] -'0') * 10 + s2[1]-'0';
		else y = x0;
		if(s3 == "+") breturn x + y;
		else breturn x * y;
	}
	void to_ho() {
		for(auto t:it) {
			ll z = opt(t)%mod;
			if(z%dx == 0) ret.push_back({rec1, z});
			else ret.push_back({rec2, z});
		}
		it.clear();
	} 	
} monky[n];
int main() {
	cout << 237828LL * 216047LL;
	for(ll i = 0; i < n; i++) {
		ll x;
		do {
			cin >> x;
			if(!x) break;
			monky[i].it.push_back(x);
		} while(true);
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		monky[i].s1 = s1;
		monky[i].s2 = s3;
		monky[i].s3 = s2;		
		ll x1, x2, x3;
		cin >> x1 >> x2 >> x3;
		monky[i].dx = x1;
		monky[i].rec1 = x2;
		monky[i].rec2 = x3;
	}
	for(ll i = 0; i < 10000; i++) {
		for(ll j = 0; j < n; j++) {
			monky[j].to_ho();
			for(auto t:ret) monky[t.first].it.push_back(t.second);
			ret.clear();
		}
	}
	for(ll i = 0; i < n; i++) cout << monky[i].ans << '\n';
}
