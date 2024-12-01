#include<bits/stdc++.h>
#define breturn return
#define pp pair<pair<int, pair<int, int> >, pair<int, pair<int, int> > > 
using namespace std;


map<pp, int> dp;
void readline(int &a, int &b) {
	fstream f;
	f.open("22_input.txt");
	string s;
	getline(f, s);
	a = stoi(s.substr(11));
	getline(f, s);
	b = stoi(s.substr(7));
}


int rek(int b, int t1, int t2, int t3, int h1, int h2, int mana, int b_damage) {
	if(h1 <= 0) return 0;
	if(h2 <= 0 or b == 0 and mana < 53) return 1e9;
	//cout << " b: " << b << " t1: " << t1 <<" t2: " << t2 << " t3: " << t3 <<" h1: " << h1 << " h2: " << h2 << " mana: " << mana << '\n'; 
	pp p = {{t1, {t2, t3}}, {h1, {h2, mana}}};
	if(dp.find(p) != dp.end()) return dp[p];
	int val = 1e9;
	if(t3 > 0) mana += 101, t3--;
	if(b == 1) return rek(0, t1 - !!t1, t2 - !!t2, t3 - !!t3, h1 - (t2 > 0) * 3, h2 -  b_damage + (t1 > 0) * 7, mana + (t3 > 0) * 101, b_damage);
	else {	
		if(mana >= 53) val = min(val, rek(1, t1 - !!t1, t2 - !!t2, t3, h1 - (t2 > 0) * 3 - 4, h2, mana - 53, b_damage) + 53);
		if(mana >= 73) val = min(val, rek(1, t1 - !!t1, t2 - !!t2, t3, h1 - (t2 > 0) * 3, h2 + 2, mana - 73, b_damage) + 73);
		if(mana >= 113) if(t1 <= 1) val = min(val, rek(1, 6, t2 - !!t2, t3, h1 - (t2 > 0) * 3, h2, mana - 113, b_damage) + 113);
		if(mana >= 173) if(t2 <= 1) val = min(val, rek(1, t1 - !!t1, 6, t3, h1 - (t2 > 0) * 3, h2, mana - 173, b_damage) + 173);
		if(mana >= 229) if(t3 <= 0) val = min(val, rek(1, t1 - !!t1, t2 - !!t2, 5, h1 - (t2 > 0) * 3, h2, mana - 229, b_damage) + 229);
	}
	dp[p] = val;
	return dp[p];
}


void solve(int &a, int &b) {
	cout << rek(0, 0, 0, 0, a, 50, 500, b) << '\n';
}
int main() {
	int a, b;
	readline(a, b);
	solve(a, b);
}
