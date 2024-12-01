#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;
ll n, a, b, c, x, y;
vector<pair<ll, ll> > v, pt, nv;
vector<pair<pair<ll, ll>, ll> > is;
int main() {
	while(1) {
		cin >> x;
		if(!~x) break;
		cin >> y;
		v.push_back({x, x + y - 1});
	}
	for(int j = 0; j < 7; j++) {
		pt.clear();
		is.clear();
		for(int i = 0; i < v.size(); i++) pt.push_back({v[i].first, 1}), pt.push_back({v[i].second, -1});
		while(1) {
			cin >> a >> b >> c;
			if(!~a) break;
			pt.push_back({b, 0});
			pt.push_back({b + c - 1, 0});
			is.push_back({{a, b}, c});
		}
		v.clear();
		sort(pt.begin(), pt.end());
		int pushn = 0;
		for(int i = 0; i < pt.size() - 1; i++) {
			if(pt[i].second == 1) pushn++;
			if(pt[i].second == -1) pushn--;
			if(pushn) v.push_back({pt[i].first + !pt[i].second, pt[i + 1].first});			
		}
		nv = v;
		for(auto t:is) {
			a = t.first.first, b = t.first.second, c = t.second;
			for(int i = 0; i < v.size(); i++) if(v[i].first >= b and v[i].second < b + c) nv[i].first -= (b - a), nv[i].second -= (b - a);			
		}
		v = nv;
	}
	sort(v.begin(), v.end());
	cout << v[0].first;
}

//58722468
//33942461
//136096660
