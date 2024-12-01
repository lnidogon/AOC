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


bool rek(Instruction (&m)[30000], Part &p, int c) {
	if(c == has("A")) return true;
	if(c == has("R")) return false;
	for(int i = 0; i < m[c].inst.size(); i++) {
		auto t = m[c].inst[i];
		int v;
		if(t.first.first == 'x') 
			v = p.x;
		else if(t.first.first == 'm')
			v = p.m;
		else if(t.first.first == 'a')
			v = p.a;
		else if(t.first.first == 's')
			v = p.s;
		else 
			return rek(m, p, has(t.second.second));		
		if(t.first.second == '>' and v > t.second.first) return rek(m, p, has(t.second.second));
		else if(t.first.second == '<' and v < t.second.first) return rek(m, p, has(t.second.second));
	}
}

void solve(Instruction (&m)[30000], vector<Part> &v) {
	int ans = 0;
	for(auto t:v) 
		if(rek(m, t, has("in"))) {
			ans += t.val;
			cout << t.x << " " <<t.m << " " << t.a << " " << t.s << '\n'; 
		}
	cout << ans << '\n';
}

int main() {
	Instruction m[30000];
	vector<Part> v;
	readline(m, v);
	solve(m, v); 		
}
