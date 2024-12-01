#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<pair<int, pair<int, int > > > &v) {
	fstream f;
	f.open("2_input.txt");
	string s;
	while(getline(f, s)) {
		int id1 = s.find('x');
		int id2 = s.find('x', id1 + 1);
		int id3 = s.size();
		int no1 = stoi(s.substr(0, id1));
		int no2 = stoi(s.substr(id1 + 1, id2));
		int no3 = stoi(s.substr(id2 + 1, id3));
		v.push_back({no1, {no2, no3}});
	}
}
void solve(vector<pair<int, pair<int, int > > > &v) {
	int sum = 0;
	for(auto t:v) {
		int x = t.first;
		int y = t.second.first;
		int z = t.second.second;
		sum += 2 * min(x + y, min(x + z, y + z)) + x * y * z;
	}
	cout << sum;
}
int main() {
	vector<pair<int, pair<int, int > > > v;
	readline(v);
	solve(v);
}
