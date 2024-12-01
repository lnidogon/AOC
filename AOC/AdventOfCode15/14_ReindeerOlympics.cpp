#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<pair<pair<string, int>, pair<int, int> > > &v) {
	fstream f;
	f.open("14_input.txt");
	string s;
	while(getline(f, s)) {
		int id = -1;
		int idnx = 0;
		string s1, s2, s3, s4;
	
		for(int i = 0; i < 14; i++) {
			idnx = s.find(" ", ++id);
			string ss = s.substr(id, idnx - id);
			id = idnx;
			if(i == 0) s1 = ss;
			if(i == 3) s2 = ss;
			if(i == 6) s3 = ss;
			if(i == 13) s4 = ss;
		}
		v.push_back({{s1, stoi(s2)},{stoi(s3), stoi(s4)}});
	}
}

string run(vector<pair<pair<string, int>, pair<int, int> > > &v, int ukDis) {
	int mx = 0;
	string inLead = "";
	for(auto t:v) {
		int onc = t.first.second * t.second.first;
		int ond = t.second.first + t.second.second;
		int dis = (ukDis / ond) * onc;
		int ost = ukDis % ond;
		if(ost <= t.second.first) dis += ost * t.first.second;
		else dis += t.second.first * t.first.second;
		if(dis > mx) {
			mx = dis;
			inLead = t.first.first;
		}
	}
	cout << mx << '\n';
	return inLead;
}

void solve(vector<pair<pair<string, int>, pair<int, int> > > &v) {
	run(v, 2503);	
}
int main() {
	vector<pair<pair<string, int>, pair<int, int> > > v;
	readline(v);
	solve(v);	
}
