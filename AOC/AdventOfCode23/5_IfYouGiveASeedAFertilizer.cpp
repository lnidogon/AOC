#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;
ll n, a, b, c, x;
vector<ll> v, nv;
int main() {
	while(1) {
		cin >> x;
		if(!~x) break;
		v.push_back(x);
	}
	for(int i = 0; i < 7; i++) {
		nv = v;
		while(1) {
			cin >> a >> b >> c;
			if(!~a) break;
			for(int j = 0; j < v.size(); j++) if(v[j] >= b and v[j] < b + c) nv[j] = a + v[j] - b;			
		}
		v = nv;
	}
	sort(v.begin(), v.end());
	cout << v[0];
}
