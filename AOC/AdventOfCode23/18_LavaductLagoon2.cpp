#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;

struct Quer {
	char dir;
	ll len;
	string col;
	Quer(char dir, ll len, string col) : col(col) {
		this->dir = dir;
		this->len = len;
		return;
		ll ret = 0;
		for(ll i = 0; i < 5; i++) {
			auto t = col[i];
			ret *= 16;
			if(t <= '9') ret += t - '0';
			else ret += t - 'a' + 10; 
		}
		if(col[5] == '0') {
			this->dir = 'R';
		} else if(col[5] == '1') {
			this->dir = 'D';
		} else if(col[5] == '2') {
			this->dir = 'L';
		} else if(col[5] == '3') {
			this->dir = 'U';
		} 
		this->len = ret;
		cout << this->len << " " << this->dir <<'\n';
	}
};

const ll dx[] = {-1, 0, 1, 0};
const ll dy[] = {0, 1, 0, -1};
ll chd[100];
void readline(vector<Quer> &v) {
	string s;
	fstream f;
	f.open("input.txt", ios::in);
	while(getline(f, s)) {
		char a = s[0];
		ll x = s.find(" ", 2);
		ll b = stoi(s.substr(2, x - 2));
		string c = s.substr(x + 3);
		c.pop_back();
		v.push_back(Quer(a, b, c));
	}
}
void solve(vector<Quer> &v) {
	chd['U'] = 0;
	chd['D'] = 2;
	chd['L'] = 3;
	chd['R'] = 1;
	vector<pair<ll, ll> > coords;
	ll cx = 0, cy = 0;
	coords.push_back({0, 0});
	for(auto t:v) {
		ll sm = chd[t.dir];
		cx += dx[sm] * t.len;
		cy += dy[sm] * t.len; 	
		coords.push_back({cx, cy});
	}	
	ll ans = 0;
	for(ll i = 0; i < coords.size() - 1; i++) {
		auto t1 = coords[i];
		auto t2 = coords[i + 1];
		if(t1.second == t2.second) {
			cout << v[i - 1].dir << " " << v[i + 1].dir << '\n';
			if(v[i - 1].dir != v[i + 1].dir) ans += abs(t1.first - t2.first) + 1, cout << "c\n";
			else if(v[i - 1].dir == 'L') ans += max(t1.first, t2.first) + 1, cout <<"b\n";
			else ans -= max(t1.first, t2.first) + 1, cout << "a\n";
			cout << ans <<'\n';
			continue;
		}
		int del = t1.second - t2.second;
		if(del < 0) del++;
		else del--;
		cout <<del << " " << t1.first + (t1.second > t2.second) << " del\n";
		ans += (del) * (t1.first + (t1.second > t2.second));
		cout << t1.second << " " << t2.second << " " << t1.first << '\n';
		cout << ans << '\n';
	}
	cout << ans;
}

int main() {
	vector<Quer> v;
	readline(v);
	solve(v);
}
