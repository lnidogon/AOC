#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;
vector<pair<ll, ll> > v, ov;
ll a;
int main() {
	
	fstream f;
	f.open("bruh.txt");
	ll x = 0;
	while(true) {
		f >>a; 
		if(a == -69) break;
		v.push_back({a, x++});			
	}
	ll n = v.size();
	for(ll i = 0; i < n; i++) ov.push_back({v[i].first * 811589153LL, v[i].second});
	for(ll i = 0; i < v.size(); i++) v[i].first = (v[i].first * 811589153LL)%(n - 1);
	for(ll p = 0; p < 10; p++) for(ll i = 0; i < v.size(); i++) {
		ll cp = -1;
		for(ll j = 0; j < v.size(); j++)if(v[j].second == i) {
			cp = j;
			break;
		}
		ll vl = v[cp].first;
		for(ll j = 0; j < abs(vl); j++) {
			ll nx;
			if(vl < 0) {
				nx = (cp - 1 + n)%n;
			} else if(vl > 0) {
				nx = (cp + 1)%n;				
			}
			swap(v[nx], v[cp]);
			cp = nx;
		}
	}
	//for(ll i = 0; i < v.size(); i++) cout << ov[v[i].second].first << " ";
	for(ll i = 0; i < v.size(); i++) if(v[i].first == 0) {
		ll n1 = ov[v[(i + 1000)%v.size()].second].first;
		ll n2 = ov[v[(i + 2000)%v.size()].second].first;
		ll n3 = ov[v[(i + 3000)%v.size()].second].first;
		cout << n1 << " + " << n2 << " + " << n3 << " = " << n1 + n2 + n3;
	}
}
