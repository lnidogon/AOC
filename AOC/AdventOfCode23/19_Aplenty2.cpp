#include<bits/stdc++.h>
#define breturn return
using namespace std;
struct Part {
	int x, m, a, s, val;
	Part(int x, int m, int a, int s) : x(x), m(m), a(a), s(s) {val = x + m + a + s;}
};
struct Instruction {
	vector<pair<pair<char, char>, pair<int, string> > > inst;
	Instruction() : inst(*(new vector<pair<pair<char, char>, pair<int, string> > >)) {}
	Instruction(vector<string> &v) {
		for(int i = 0; i < v.size() - 1; i++) {
			auto t = v[i];				
			char c1 = t[0];
			char c2 = t[1];
			int x = t.find(':');
			int i1 = stoi(t.substr(2, x - 2));
			string s2 = t.substr(x + 1);
			inst.push_back({{c1, c2},{i1, s2}});
		}
		inst.push_back({{0, 0}, {0, v.back()}});
	}
};
int has(string s) {
	int ret = 0;
	while(s.size()) {
		ret *= 30;
		ret += (s.back()-'a'+1);
		s.pop_back();
	}
	return ret;
}
void readline(Instruction (&m)[30000], vector<Part> &v) {
	fstream f;
	f.open("input2.txt", ios::in);
	string s;
	while(true) {
		getline(f, s);
		if(s == "") break;
		cout << s << '\n';
		int x = s.find('{');
		vector<string> v2;
		string nam = s.substr(0, x);
		v2.clear();
		x++;
		while(true) {
			int y = min(s.find(',', x), s.find('}', x));
			v2.push_back(s.substr(x, y - x));
			if(s[y] == '}') break;
			x = y + 1;
		}
		int h = has(nam);
		m[h] = Instruction(v2);			
	}
	while(getline(f, s)) {
		int a, b, c, d;
		int x = 3;
		int y = s.find(',', x);
		a = stoi(s.substr(x, y - x));
		x = y + 3;
		y = s.find(',', x);
		b = stoi(s.substr(x, y - x));
		x= y + 3;
		y = s.find(',', x);
		c = stoi(s.substr(x, y - x));
		x = y + 3;
		y = s.find('}', x);
		d = stoi(s.substr(x, y - x));
		v.push_back(Part(a, b, c, d));	
	}
}
long long rek(Instruction (&m)[30000], int c, int lo[4], int hi[4]) {
	for(int i = 0; i < 4; i++) if(lo[i] > hi[i]) return 0LL;
	if(c == has("A")) return (hi[0] - lo[0] + 1LL) * (hi[1] - lo[1] + 1LL) * (hi[2] - lo[2] + 1LL) * (hi[3] - lo[3] + 1LL);
	if(c == has("R")) return 0LL;
	long long ret = 0;
	for(int i = 0; i < m[c].inst.size(); i++) {
		auto t = m[c].inst[i];
		int opt = -1;	
		if(t.first.first == 'x') opt = 0;
		else if(t.first.first == 'm') opt = 1;
		else if(t.first.first == 'a') opt = 2;
		else if(t.first.first == 's') opt = 3;
		else ret += rek(m, has(t.second.second), lo, hi);					
		if(opt != -1) {
			int loc[4], hic[4];
			if(t.first.second == '>') {		
				int b = max(lo[opt], t.second.first + 1);
				for(int i = 0; i < 4; i++) loc[i] = lo[i], hic[i] = hi[i];
				loc[opt] = b;
				ret += rek(m, has(t.second.second), loc, hic);
				hi[opt] = b - 1;
			}
			if(t.first.second == '<') {
				int b = min(hi[opt], t.second.first - 1);
				for(int i = 0; i < 4; i++) loc[i] = lo[i], hic[i] = hi[i];
				hic[opt] = b;
				ret += rek(m, has(t.second.second), loc, hic);
				lo[opt] = b + 1;
			}
		}
	}
	return ret;
}
void solve(Instruction (&m)[30000], vector<Part> &v) {
	int flo[] = {1, 1, 1, 1};
	int fhi[] = {4000, 4000, 4000, 4000};
	cout << rek(m, has("in"), flo, fhi);
}
int main() {
	Instruction m[30000];
	vector<Part> v;
	readline(m, v);
	solve(m, v); 		
}
