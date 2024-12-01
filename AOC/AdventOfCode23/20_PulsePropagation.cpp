#include<bits/stdc++.h>
#define breturn return
using namespace std;

bool sig[1001][1001];
bool con[1001][1001];
char dc;
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
	//	cout << id << "_\n";
	//	for(auto t:ous) {
	//		cout << t << '\n';
	//	}
	///	for(auto t:ins) 
	//		cout << t << "in\n";
		if(id) {
			
			if(type == 0 and !pulse) state = !state;		
			else if(type == 0) return;
			else {
				state = false;
				for(int j = 0; j < ins.size(); j++) 
					state += !sig[ins[j]][id];			
			}
	//		cout << state << " STATE\n";		
		}
		for(int i = 0; i < ous.size(); i++) 
			q.push({{ous[i], id}, state});		
		sul += (ous.size() * !state);
		suh += (ous.size() *  state);
	}
};

int has(string s) {
	if(s == "broadcaster") return 0;
	if(s.size() == 1) return (s[0]-'a' + 1) * 30;
	return (s[0]-'a' + 1) * 30 + s[1]-'a' + 1;
}

void readline(Module (&m)[1000]) {
	fstream f;
	f.open("input2.txt", ios::in);
	string s;
	while(getline(f, s)) {
		s += ',';
		int id = -1;
		int typ = 0;
		int x = 0;
		if(s[0] == '%') {
			x++;
		} else if(s[0] == '&') {
			x++;
			typ = 1;
		}	
		int y = s.find(" ");
		id = has(s.substr(x, y - x));
		x = y + 4;
		m[id] = Module(id, typ);
		cout << id << ".\n";
		while(x < s.size()) {
			int y = s.find(',', x);
			int nid = has(s.substr(x, y - x));
			x = y + 2;
			con[id][nid] = 1;
		}
	}
	for(int i = 0; i < 1000; i++) for(int j = 0; j < 1000; j++) if(con[i][j]) m[j].ins.push_back(i), m[i].ous.push_back(j);
}
void solve(Module (&m)[1000]) {
	memset(sig, 0, sizeof(sig));
	queue<pair<pair<int, int>, bool> > v;
	int sul = 0, suh = 0;
	for(int i = 0; i < 1000; i++) {
		v.push({{0, 0}, 0});
		while(v.size()) {
			auto t = v.front();
			v.pop();
			m[t.first.first].emit(t.first.second, t.second, v, sul, suh);
	/*		auto q2 = v;
			while(q2.size()) {
				cout << q2.front().first.first <<" ~ ";
				q2.pop();
			}
			cout << '\n';
			cin >> dc;
	*/	}
	}
	cout << sul <<" ans " << suh << '\n';
	cout << (1000LL + sul) * suh;
}

int main() {
	Module m[1000];
	readline(m);
	for(int i = 0; i < 1000; i++) for(int j = 0; j < 1000; j++) if(con[i][j]) cout << i << " _ " << j <<'\n';
	solve(m);
}
