#include<bits/stdc++.h>
#define breturn return
using namespace std;

bool sig[1001][1001];
bool con[1001][1001];
char dc;
set<pair<string, int> > st;
int gx = 0;
int has(string s) {
	if(s == "broadcaster") return 0;
	if(s == "rx") return 69;
	if(s.size() == 1) return (s[0]-'a' + 1) * 30;
	return (s[0]-'a' + 1) * 30 + s[1]-'a' + 1;
}

struct Module {
	int id;
	bool type;
	bool state;
	vector<int> ins;
	vector<int> ous;
	Module() : id(-1), type(0) {}
	Module(int id, bool type) : id(id), type(type) {
		state = 0;
	}
	void emit(int from, bool pulse, queue<pair<pair<int, int>, bool> > &q, int &sul, int &suh) {
		sig[from][id] = pulse;
		if(id) {
			if(type == 0 and !pulse) state = !state;		
			else if(type == 0) return;
			else {
				state = false;
				for(int j = 0; j < ins.size(); j++) 
					state += !sig[ins[j]][id];			
				if(!state and id == has("th")) cout << "bruhara bruhara\n";
			}
		}
		for(int i = 0; i < ous.size(); i++) 
			q.push({{ous[i], id}, state});		
		sul += (ous.size() * !state);
		suh += (ous.size() *  state);
	}
};


void readline(Module (&m)[1000]) {
	fstream f;
	f.open("input2.txt", ios::in);
	string s;
	while(getline(f, s)) {
		s += ',';
		int id = -1;
		int typ = 0;
		int x = 0;
		if(s[0] == '%') 
			x++;
		else if(s[0] == '&') 
			x++, typ = 1;		
		int y = s.find(" ");
		id = has(s.substr(x, y - x));
		m[id] = Module(id, typ);
		st.insert({s.substr(x, y - x), id});
		x = y + 4;
		while(x < s.size()) {
			int y = s.find(',', x);
			int nid = has(s.substr(x, y - x));
			x = y + 2;
			con[id][nid] = 1;
		}
	}
	for(int i = 0; i < 1000; i++) for(int j = 0; j < 1000; j++) if(con[i][j]) m[j].ins.push_back(i), m[i].ous.push_back(j);
}

int dfs(Module (&m)[1000], int id, int en, int pot = 1, int val = 0) {
	if(m[id].ous.size() == 1) {
		if(m[id].ous[0] == en) return val + pot;
		return dfs(m, m[id].ous[0], en, pot * 2, val);
	} else {
		if(m[id].ous[0] == en) return dfs(m, m[id].ous[1], en, pot * 2, val + pot);
		return dfs(m, m[id].ous[0], en, pot * 2, val + pot);
	}
}

void solve(Module (&m)[1000]) {
	int en = -1;
	long long x = 1;
	for(int i = 0; i < 4; i++) {
		auto poc = m[0].ous[i];
		for(auto t:m[poc].ous)
			if(m[t].ous.size() > 2) en = t, cout << m[t].id << '\n';
		long long y = dfs(m, poc, en);
		cout << y << " ";
		x = x * y / __gcd(x, y);
		cout << x << '\n';
	}
}

int main() {
	Module m[1000];
	readline(m);
	for(int i = 0; i < 1000; i++) for(int j = 0; j < 1000; j++) if(con[i][j]) cout << i << " _ " << j <<'\n';
	solve(m);
}
