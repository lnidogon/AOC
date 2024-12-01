#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;
map<string, ll> m;
vector<ll> grap[10000]; 
ll val[10000], x, ipt;
vector<ll> v;
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	m["/"] = 0;
	x = 0;
	string bruh;
	cin >> bruh >> bruh >> bruh >> bruh >> bruh;
	v.push_back(0);
	while(true) {
		string s;
		cin >> s;
		if(s == "+") break;
		string z;
		if(s == "$") {
			string z2;
			cin >> z >> z2;
			if(z2 == "..") v.pop_back();
			else {
				if(v.back() >= 10) z2 += (v.back()/10%10)+'0';
				z2 += (v.back()%10)+'0';
				v.push_back(m[z2]), cin >> z >> z2;								
			}
		} else {
			string z2;
			cin >> z;
			if(s == "dir") {
				if(v.back() >= 10) z += (v.back()/10%10)+'0';
				z += (v.back()%10)+'0';
				if(m.find(z) == m.end()) m[z] = ++x;
				grap[v.back()].push_back(m[z]);		
				cout << z << " -> " << x << '\n';
			} else {
				long long d = 0;
				for(ll i = 0; i < s.size(); i++) d *= 10, d += s[i] - '0';
				val[v.back()] += d;
			}
		}
	}
	long long sum = 0;
	ll mmv = 1e18;
	for(ll j = x; j>= 0; j--) {
		for(auto t:grap[j]) val[j] += val[t];
		cout << j << "_" << val[j] << ": \n";
		for(auto t:grap[j]) cout << t << "_" << val[t] << "\n";
		cout << '\n';
	}
	for(ll j = 0; j <= x; j++) {
		cout << val[j] << " " << val[0] - val[j] << '\n';
		if(70000000 - val[0] + val[j] >= 30000000) mmv = min(mmv, val[j]);
	}
	cout << mmv;
} 
