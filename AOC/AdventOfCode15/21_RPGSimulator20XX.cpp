#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(int &a, int &b, int &c) {
	fstream f;
	f.open("21_input.txt");
	string s;
	getline(f, s);
	int id = s.find(" ");
	id = s.find(" ", id + 1);
	a = stoi(s.substr(id + 1));
	
	getline(f, s);
	id = s.find(" ");
	b = stoi(s.substr(id + 1));
	getline(f, s);
	id = s.find(" ");
	c = stoi(s.substr(id + 1));
}
void solve(int &a, int &b, int &c) {
	pair<int, pair<int, int> > wp[5];
	pair<int, pair<int, int> > ar[6];
	pair<int, pair<int, int> > rn[8];
	wp[0] = {8,  {4, 0}};
	wp[1] = {10, {5, 0}};
	wp[2] = {25, {6, 0}};
	wp[3] = {40, {7, 0}};
	wp[4] = {74, {8, 0}};

	ar[0] = {13,  {0, 1}};
	ar[1] = {31,  {0, 2}};
	ar[2] = {53,  {0, 3}};
	ar[3] = {75,  {0, 4}};
	ar[4] = {102, {0, 5}};
	ar[5] = {0,   {0, 0}};

	rn[0] = {25,  {1, 0}};
	rn[1] = {50,  {2, 0}};
	rn[2] = {100, {3, 0}};
	rn[3] = {20,  {0, 1}};
	rn[4] = {40,  {0, 2}};
	rn[5] = {80,  {0, 3}};
	rn[6] = {0,   {0, 0}};
	rn[7] = {0,   {0, 0}};
	int ans = 10000;
	for(int i = 0; i < 5; i++) 
	for(int j = 0; j < 6; j++) 
	for(int k1 = 0; k1 < 8; k1++) 
	for(int k2 = k1 + 1; k2 < 8; k2++) {
		int cost= wp[i].first 
				+ ar[j].first
				+ rn[k1].first
				+ rn[k2].first;
		int damage= wp[i].second.first 
				+ ar[j].second.first
				+ rn[k1].second.first
				+ rn[k2].second.first;
		int armor = wp[i].second.second 
				+ ar[j].second.second
				+ rn[k1].second.second
				+ rn[k2].second.second;
		int aa = a, bb = b, cc = c;
		//aa = 12, bb = 7, cc = 2;
		int health = 100;
		//health = 8, damage = 5, armor = 5;
		bool win = false;
		while(true) {
			int dif = max(damage - cc, 1);
			aa -= dif;
			if(aa <= 0) {
				win = true;
				break;
			}
			//cout << aa << " " << dif << " boss health\n";
			dif = max(bb - armor, 1);
			health -= dif;
			if(health <= 0) break;
			//cout << health << " " << dif << " health\n";
		}
		if(win) ans = min(ans, cost);
		
	}
	cout << ans << '\n';
}

int main() {
	int a, b, c;
	readline(a, b, c);
	solve(a, b, c);
}
