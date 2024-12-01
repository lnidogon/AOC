#include<bits/stdc++.h>
#define breturn return
using namespace std;
map<pair<int, int>, int> m;
set<pair<int, int> > s;
int mo = 0;
struct elf {
	vector<int> pr = {0, 1, 2, 3};
	int px, py;
	int ppx, ppy, ppr; 
	void prop() {
		bool nw = (s.find({px - 1, py - 1}) != s.end());
		bool nn = (s.find({px - 1, py}) != s.end());
		bool ne = (s.find({px - 1, py + 1}) != s.end());
		bool ee = (s.find({px, py + 1}) != s.end());
		bool se = (s.find({px + 1, py + 1}) != s.end());
		bool ss = (s.find({px + 1, py}) != s.end());
		bool sw = (s.find({px + 1, py - 1}) != s.end());
		bool ww = (s.find({px, py - 1}) != s.end());
		//cout << nw << nn << ne << ee << se << ss << sw << ww << '\n';
		
		ppx = -100, ppy = -1;
		if(!nw and !nn and !ne and !ee and !se and !ss and !sw and !ww) breturn;
		for(int i = 0; i < 4; i++) {
			if(pr[i] == 0 and !nw and !nn and !ne) ppr = 0, m[{ppx = px - 1, ppy = py}]++;
			else if(pr[i] == 1 and !sw and !ss and !se) ppr = 1, m[{ppx = px + 1, ppy = py}]++;
			else if(pr[i] == 2 and !nw and !sw and !ww) ppr = 2, m[{ppx = px, ppy = py - 1}]++;
			else if(pr[i] == 3 and !ne and !se and !ee) ppr = 3, m[{ppx = px, ppy = py + 1}]++;			
			else continue;
		//	cout << ppx << " " << ppy << " " << ppr << " " << "hmm\n";
		//	cout << m[{ppx, ppy}] << '\n';
			i = 5;
		}
	}
	void mov() {		
		pr.push_back(pr[0]);
		pr.erase(pr.begin());
		//cout << m[{ppx,ppy}] << '\n';
		if(ppx == -100 or m[{ppx, ppy}] > 1) breturn; 
		mo++;
		px = ppx, py = ppy;

	}
};
string st;
int x;
vector<elf> elves;
int main() {	
	while(true) {	
		cin >> st;
		if(st == "+") break;
		for(int i = 0; i < st.size(); i++) if(st[i] == '#') {
			elf e;
			e.px = x, e.py = i;
			elves.push_back(e);
			s.insert({e.px, e.py});
		}
		x++;
	}
	for(int i = 0; i <1000; i++) {
		m.clear();
		for(int i = 0; i < elves.size(); i++) elves[i].prop();
		mo= 0;
		for(int i = 0; i < elves.size(); i++) elves[i].mov();
		if(!mo) breturn cout << i, 0;
		s.clear();
		for(int i = 0; i < elves.size(); i++) s.insert({elves[i].px, elves[i].py});//cout << elves[i].px << "_"  << elves[i].py <<'\n';
		cout << elves[28].px << '\n';
	}
	int x1 = 1e9, x2 = -1e9, y1 = 1e9 , y2 = -1e9;
	for(int i = 0; i <elves.size(); i++) {
		cout << i << ": " << elves[i].px << " " << elves[i].py << '\n';
		x1 = min(elves[i].px, x1);
		x2 = max(elves[i].px, x2);
		y1 = min(elves[i].py, y1);
		y2 = max(elves[i].py, y2);
		cout << x1 << " " << x2 << " " << y1 << " " << y2 << '\n';
	}
	cout << x1 << " " << x2 << " " << y1 <<" " << y2 << '\n';
	cout << (x2 + 1 - x1) * (y2 + 1 - y1) - elves.size();
}
