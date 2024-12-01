#include<bits/stdc++.h>
#define breturn return
#define ld long double
#define x first.first
#define y first.second.first
#define z first.second.second
#define vx second.first
#define vy second.second.first
#define vz second.second.second

using namespace std;
const ld MINC = 200000000000000;
const ld MAXC = 400000000000000;

ld crosstime(ld x1, ld y1, ld vx1, ld vy1, ld x2, ld y2, ld vx2, ld vy2) {
	return (ld)(vx2 * (y1 - y2)- vy2 * (x1-x2))/(vx1 * vy2 - vx2 * vy1);
}

bool inarea(ld x1, ld y1, ld z1, ld vx1, ld vy1, ld vz1, ld tim) {
	ld xx = x1 + vx1 * tim;
	ld yy = y1 + vy1 * tim;
	ld zz = z1 + vz1 * tim;
	return (tim >= 0 and xx >= MINC and xx <= MAXC and yy >= MINC and yy <= MAXC); 
} 

void readline(vector<pair<pair<ld, pair<ld, ld> >, pair<ld, pair<ld, ld> > > > &v) {
	fstream f;
	f.open("input2.txt", ios::in);
	string s;
	ld a1, a2, a3, a4, a5, a6;
	while(getline(f, s)) {
		int a = 0, b;		
		b = s.find(',');
		a1 = stoll(s.substr(a, b - a));
		a = b + 2;
		b = s.find(',', a);
		a2 = stoll(s.substr(a, b - a));
		a = b + 2;
		b = s.find('@', a);
		a3 = stoll(s.substr(a, b - a - 1));
		a = b + 2;
		b = s.find(',', a);
		a4 = stoll(s.substr(a, b - a));
		a = b + 2;		
		b = s.find(',', a);
		a5 = stoll(s.substr(a, b - a));
		a = b + 2;		
		b = s.size();
		a6 = stoll(s.substr(a, b - a));
		a = b + 2;
		v.push_back({{a1, {a2, a3}},{a4, {a5, a6}}});	
	}
}

void solve(vector<pair<pair<ld, pair<ld, ld> >, pair<ld, pair<ld, ld> > > > &v) {
	int ans = 0;
	for(int i = 0; i < v.size(); i++) {
		for(int j = i + 1; j < v.size(); j++) {
			auto e1 = v[i];
			auto e2 = v[j];
			ld t1 = crosstime(e1.x, e1.y, e1.vx, e1.vy, e2.x, e2.y, e2.vx, e2.vy);
			ld t2 = crosstime(e2.x, e2.y, e2.vx, e2.vy, e1.x, e1.y, e1.vx, e1.vy);
			//ld t2 = crosstime(e1.x, e1.z, e1.vx, e1.vz, e2.x, e2.z, e2.vx, e2.vz);
			//ld t3 = crosstime(e1.y, e1.z, e1.vy, e1.vz, e2.y, e2.z, e2.vy, e2.vz);
			ans += (inarea(e1.x, e1.y, e1.z, e1.vx, e1.vy, e1.vz, t1) and inarea(e2.x, e2.y, e2.z, e2.vx, e2.vy, e2.vz, t2));
		}
	}
	cout << ans << '\n';
}

int main() {
	cout << fixed;
	vector<pair<pair<ld, pair<ld, ld> >, pair<ld, pair<ld, ld> > > > v;
	readline(v);
	solve(v);
}
