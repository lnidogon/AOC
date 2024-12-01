#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;
string s1, s2, s3;
char c;
map<string, ll> m;
ll val[100000], gx, typ[100000], par[100000];
pair<ll, ll> grap[100000];
bool been[100000], onx[100000];

ll rek(ll x) {
	if(been[x]) breturn val[x];
	been[x] = true;
	if(typ[x] == 1) breturn val[x] = rek(grap[x].first) + rek(grap[x].second);
	if(typ[x] == 2) breturn val[x] = rek(grap[x].first) - rek(grap[x].second);
	if(typ[x] == 3) breturn val[x] = rek(grap[x].first) * rek(grap[x].second);
	if(typ[x] == 4) breturn val[x] = rek(grap[x].first) / rek(grap[x].second);
}

void ker(ll x, ll y) {
	ll l = grap[x].first, r = grap[x].second;
	if(typ[x] == 0) {
		cout << val[x] << " valx\n";
		val[x] = y;	
		cout << y << '\n';
		breturn;
	} else if(typ[x] == 1) {
		if(onx[l]) ker(l, y - val[r]);
		else ker(r, y - val[l]);
	} else if(typ[x] == 2) {
		if(onx[l]) ker(l, y + val[r]);
		else ker(r, val[l] - y);
	} else if(typ[x] == 3) {
		if(onx[l]) ker(l, y/val[r]);
		else ker(r, y/val[l]);
	} else {
		if(onx[l]) ker(l, val[r] * y);
		else ker(r, val[l]/y);
	}
	been[x] = false;
	rek(x);
	cout << y << ": \n";
	if(typ[x] == 1) cout << val[l] + val[r];
	else if(typ[x] == 2) cout << val[l] - val[r];
	else if(typ[x] == 3) cout << val[l] * val[r];
	else if(typ[x] == 4) cout << val[l] / val[r];
	cout << '\n';
}


int main() {
	fstream f;
	f.open("bruh.txt");
	while(1) {
		f >> s1 >> s2;
		if(s1 == "-") break;
		if(m.find(s1) == m.end()) m[s1] = ++gx;
		if(s2.size() <= 2 or s2 == "1789") {			
			if(s2.size() == 1) val[m[s1]] = s2[0]-'0';
			else if(s2.size() == 2) val[m[s1]] = (s2[0]-'0')*10 + s2[1]-'0';
			else val[m[s1]] = 1789;
			been[m[s1]] = 1;
		} else {
			f >> c >> s3;
			if(c == '+') typ[m[s1]] = 1;
			else if(c == '-') typ[m[s1]] = 2;
			else if(c == '*') typ[m[s1]] = 3;
			else if(c == '/') typ[m[s1]] = 4;
			if(m.find(s2) == m.end()) m[s2] = ++gx;
			par[m[s2]] = m[s1];
			if(m.find(s3) == m.end()) m[s3] = ++gx;
			par[m[s3]] = m[s1];
			grap[m[s1]] = {m[s2], m[s3]};
		}			
	}
	int x = m["humn"];
	while(x != m["root"]) {
		onx[x] = 1;
		x = par[x];
	}
	rek(m["root"]);
	typ[m["root"]] = 2;
	ker(m["root"], 0);
	//cout << "meow\n";
	cout << rek(m["root"]);
}
