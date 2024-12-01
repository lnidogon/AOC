#include<bits/stdc++.h>
#define breturn return
using namespace std;
vector<string> v;
const int SPACE = 1e6 - 1;
void readline(vector<string> &v) {
	fstream f;
	f.open("input.txt", ios::in);
	string s;
	while(getline(f, s)) v.push_back(s);
}
void solve() {
	vector<pair<int, int> > vp;
	int emptr[200], emptc[200];
	for(int i = 0; i < v.size(); i++) {
		bool empt = true;
		for(int j = 0; j < v[0].size(); j++) {
			if(v[i][j] == '#') empt = false, vp.push_back({i, j});
		}
		emptr[i] = empt;
	}
	for(int j = 0; j < v[0].size(); j++) {
		bool empt = true;
		for(int i = 0; i < v.size(); i++) {
			if(v[i][j] == '#') empt = false;
		}
		emptc[j] = empt;
	}
	for(int i = 1; i < v.size(); i++) emptr[i] = emptr[i - 1] + emptr[i];
	for(int i = 1; i < v[0].size(); i++) emptc[i] = emptc[i - 1] + emptc[i];	
	long long sum = 0;
	for(int i = 0; i < vp.size(); i++) {
		for(int j = i + 1; j < vp.size(); j++) {
			long long cnt = abs(vp[i].first - vp[j].first) + abs(vp[i].second - vp[j].second);
			cnt += abs(emptr[vp[i].first] - emptr[vp[j].first]) * SPACE + abs(emptc[vp[i].second] - emptc[vp[j].second]) * SPACE;
			sum += cnt;
		}
	}
	cout << sum << '\n';
}
int main() {
	readline(v);
	solve();
	
}
