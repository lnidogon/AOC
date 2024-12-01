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

pair<ld, pair<ld, ld> > da_formula(ld x0, ld y0, ld z0, ld x1, ld y1, ld z1, ld vx1, ld vy1, ld vz1, ld x2, ld y2, ld z2, ld vx2, ld vy2, ld vz2) {
	//cout << x0 << " " << y0 << " " << z0 << '\n';
	//cout << x1 << " " << y1 << " " << z1 << '\n';
	//cout << x2 << " " << y2 << " " << z2 << '\n';
	ld vy0 = ((y2 - y0) * (y1 - y0) * (vx2 - vx1) + (y2 - y0) * (x1 - x0) * vy1 - (y1 - y0) * (x2 - x0) * vy2)/((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0));
	ld vx0 = vx1 + (x1 - x0)/(y1 - y0) * (vy0 - vy1);
	ld vz0 = vz1 + (z1 - z0)/(y1 - y0) * (vy0 - vy1);
	//cout << vx0 << " " << vy0 << " " << vz0 << '\n';
	return {vx0,{vy0,vz0}};
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

ld tle(vector<pair<pair<ld, pair<ld, ld> >, pair<ld, pair<ld, ld> > > > &v, ld k) {
		vector<pair<pair<ld, pair<ld, ld> >, pair<ld, pair<ld, ld> > > > v2;
	int a = 0, b, c;
		v2 = v;
		for(int i = 0; i < v2.size(); i++) v2[i].x += v2[i].vx * k,  v2[i].y += v2[i].vy * k,  v2[i].z += v2[i].vz * k;
		for(int i = a; i < v2.size(); i++) if(v2[a].x != v2[i].x and v2[a].y != v2[i].y and v2[a].z != v2[i].z) {
			b = i;
			break;
		}
		for(int i = b; i < v2.size(); i++) if(v2[b].x != v2[i].x and v2[b].y != v2[i].y and v2[b].z != v2[i].z) {
			if(v2[b].x != v2[a].x and v2[b].y != v2[a].y and v2[b].z != v2[a].z) {
				c = i;
				break;
			}
		}
		pair<ld, pair<ld, ld> > v0 = da_formula(v2[a].x, v2[a].y, v2[a].z, v2[b].x, v2[b].y, v2[b].z, v2[b].vx, v2[b].vy, v2[b].vz, v2[c].x, v2[c].y, v2[c].z, v2[c].vx, v2[c].vy, v2[c].vz);
		for(int i = 0; i < v2.size(); i++) {
			ld t1 = crosstime(v2[a].x, v2[a].y, v0.first, v0.second.first, v2[i].x, v2[i].y, v2[i].vx, v2[i].vy);
			cout << t1 << ": ";
			cout << v2[a].x + t1 * v0.first << " ";
			cout << v2[a].y + t1 * v0.second.first << " ";
			cout << v2[a].z + t1 * v0.second.second << " - ";
			cout << v2[i].x + t1 * v2[i].vx << " ";
			cout << v2[i].y + t1 * v2[i].vy << " ";
			cout << v2[i].z + t1 * v2[i].vz << " \n";
		}
		cout << v0.first << " " << v0.second.first << " " << v0.second.second << " " << k << '\n';
		cout << v2[a].x - k * v0.first << " " << v2[a].y - k * v0.second.first << " " << v2[a].z - k * v0.second.second << '\n';
		cout << v2[a].x - k * v0.first + v2[a].y - k * v0.second.first + v2[a].z - k * v0.second.second << '\n';
		
		for(int i = v2.size()-2; i  < v2.size()-1; i++) {
			ld t1 = crosstime(v2[a].x, v2[a].y, v0.first, v0.second.first, v2[i].x, v2[i].y, v2[i].vx, v2[i].vy);
			/*cout << t1 << ": ";
			cout << v2[a].x + t1 * v0.first << " ";
			cout << v2[a].y + t1 * v0.second.first << " ";
			cout << v2[a].z + t1 * v0.second.second << " - ";
			cout << v2[i].x + t1 * v2[i].vx << " ";
			cout << v2[i].y + t1 * v2[i].vy << " ";
			cout << v2[i].z + t1 * v2[i].vz << " \n";
			*/
			ld ret = v2[a].x + t1 * v0.first - (v2[i].x + t1 * v2[i].vx);
			return ret;
		}
}


void solve(vector<pair<pair<ld, pair<ld, ld> >, pair<ld, pair<ld, ld> > > > &v) {
	
	tle(v, 327144385338);
	
	return;
	long long hi = 327144386000, lo = 327144385000;
	for(long long k = lo; k <= hi; k+=1) {
		if(tle(v, k) < 0 and tle(v, k + 1) >= 0) {
			cout << k << " " << k + 1 << '\n';
			cout << tle(v, k) << " " << tle(v, k + 1) << '\n';
		}
	}
	
}

int main() {
	cout << fixed;
	vector<pair<pair<ld, pair<ld, ld> >, pair<ld, pair<ld, ld> > > > v;
	readline(v);
	solve(v);
}
