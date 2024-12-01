#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<pair<int, vector<int> > > &v) {
	map<string, int> m;
	m["children"] = 0;
	m["cats"] = 1;
	m["samoyeds"] = 2;
	m["pomeranians"] = 3;
	m["akitas"] = 4;
	m["vizslas"] = 5;
	m["goldfish"] = 6;
	m["trees"] = 7;
	m["cars"] = 8;
	m["perfumes"] = 9; 
	fstream f;
	f.open("16_input.txt");
	string s;
	while(getline(f, s)) {
		string z;
		for(auto t:s) if(t != ':' and t != ',') z.push_back(t);
		s = z;
		s += " ";
		int id = -1;
		int idnx = 0;
		int a, b, c, d;
		string s1, s2, s3;
		for(int i = 0; i < 8; i++) {
			idnx = s.find(" ", ++id);
			string p = s.substr(id, idnx - id);
			id = idnx;
			if(i == 1) a = stoi(p);
			if(i == 2) s1 = p;
			if(i == 3) b = stoi(p);
			if(i == 4) s2 = p;
			if(i == 5) c = stoi(p);
			if(i == 6) s3 = p;
			if(i == 7) d = stoi(p);
		}
		vector<int> temp(10, -1);
		temp[m[s1]] = b;
		temp[m[s2]] = c;
		temp[m[s3]] = d;
		v.push_back({a, temp});
	}	
}	

void solve(vector<pair<int, vector<int> > > &v) {
	int arr[] = {3, 7, 2, 3, 0, 0, 5, 3, 2, 1};
	for(auto t:v) {
		bool poss = true;
		for(int i = 0; i < 10; i++) 
			if(t.second[i] >= 0 and t.second[i] != arr[i]) {
				poss = false;
				break;
			}
		
		if(poss) {
			cout << t.first << '\n';
			break;
		}
	}
}

int main() {
	vector<pair<int, vector<int> > > v;
	readline(v);
	solve(v);
}
