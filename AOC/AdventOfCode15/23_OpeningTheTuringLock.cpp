#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<pair<int, int> > &v) {
	fstream f;
	f.open("23_input.txt");
	string s;
	while(getline(f, s)) {
		int id = s.find(" ");
		string s1 = s.substr(0, id);
		id++;
		if(s1 == "hlf") v.push_back({0, 0});
		else if(s1 == "tpl") v.push_back({1, 0});
		else {
			int id2 = s.find(" ", id);
			string s2 = s.substr(id, id2 - id);
			id = id2+1;
			if(s1 == "inc") {
				if(s2 == "a") v.push_back({2, 0}); 
				else v.push_back({2, 1}); 
			}
			else if(s1 == "jmp") v.push_back({3, stoi(s2)});
			else {
				id2 = s.find(" ", id);
				string s3 = s.substr(id, id2 - id);
				if(s1 == "jie") v.push_back({4, stoi(s3)});
				else v.push_back({5, stoi(s3)});
			}
		}
	}
}
void solve(vector<pair<int, int> > &v) {
	int a = 0, b = 0;
	for(int i = 0; i < v.size(); i++) {
		auto t = v[i];
		if(t.first == 0) {
			a = a/2;
			continue;
		}
		if(t.first == 1) {
			a = a * 3;
			continue;
		}
		if(t.first == 2) {
			if(t.second == 0) a++;
			else b++;
			continue;
		}
		if(t.first == 3) {
			i += t.second - 1;
			continue;
		}
		if(t.first == 4) {
			if(a%2 == 0) i += t.second - 1;
			continue;
		}
		if(t.first == 5) {
			if(a == 1) i += t.second - 1;
			continue;
		}
	}
	cout << b << '\n';
}
int main() {
	vector<pair<int, int> > v;
	readline(v);
	solve(v);
}
