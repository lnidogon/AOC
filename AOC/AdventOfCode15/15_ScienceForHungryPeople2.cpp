#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<pair<int, pair<pair<int, int>, pair<int, int> > > > &v) {
	fstream f;
	f.open("15_input.txt");
	string s;
	while(getline(f, s)) {
		string z;
		for(auto t:s) if(t != ',') z.push_back(t);
		s = z;
		s += " ";
		int id = -1;
		int idnx = 0;
		int a, b, c, d, e;
		for(int i = 0; i < 11; i++) {
			idnx = s.find(" ", ++id);
			string p = s.substr(id, idnx - id);
			id = idnx;
			if(i == 2) a = stoi(p);
			if(i == 4) b = stoi(p);
			if(i == 6) c = stoi(p);
			if(i == 8) d = stoi(p);
			if(i == 10) e = stoi(p);
		}
		v.push_back({a, {{b, c},{d, e}}});
	}	
}	
void solve(vector<pair<int, pair<pair<int, int>, pair<int, int> > > > &v) {
	int ans = 0;
	int vec[] = {0, 0, 0, 0};
	int sum[] = {0, 0, 0, 0, 0};
	for(vec[0] = 0; vec[0] <= 100; vec[0]++) {
		for(vec[1] = 0; vec[1] + vec[0] <= 100; vec[1]++) {
			for(vec[2]= 0; vec[2] + vec[1] + vec[0] <= 100; vec[2]++) {
				vec[3] = 100 - vec[2] - vec[1] - vec[0];
				int val = 0;
				sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = 0;
				for(int j = 0; j < 4; j++) {
					sum[0] += vec[j] * v[j].second.first.first;
					sum[1] += vec[j] * v[j].second.first.second;
					sum[2] += vec[j] * v[j].second.second.first;
					sum[3] += vec[j] * v[j].first;
					sum[4] += vec[j] * v[j].second.second.second;
				}
				val = max(sum[0], 0) * max(sum[1], 0) * max(sum[2], 0) * max(sum[3], 0);
				
				//cout << sum[0] << " " << sum[1] << " " << sum[2] << " " << sum[3] << ": " << val << '\n';
				
				if(val > ans and sum[4] == 500) ans = val;
			}
		}
	}
	cout << ans;
}

int main() {
	vector<pair<int, pair<pair<int, int>, pair<int, int> > > > v;	
	readline(v);
	solve(v);
}
