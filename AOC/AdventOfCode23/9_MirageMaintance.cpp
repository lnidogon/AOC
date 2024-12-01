#include<bits/stdc++.h>
#define breturn return
using namespace std;
vector<int> v;
fstream file;
void lineread(vector<int> &v) {
	int x = 0, y = 0;
	string s;
	getline(file, s);
	while(x < s.size()) {
		x = s.find(" ", x + 1);
		if(x == -1) x = s.size();
		int a = stoi(s.substr(y, x - y));
		v.push_back(a);
		y = x + 1;
	}
}
long long solve(vector<int> &v) {
	long long sum = 0, mx = v.size() - 1;
	for(int i = 0; i < mx; i++) {
		sum += v.back();
		for(int j = 0; j < v.size() - 1; j++) v[j] = v[j + 1] - v[j]; 
		v.pop_back();
	}
	return sum;
}
int main() {
	file.open("input.txt", ios::in);
	long long ans = 0;
	while(true) {
		v.clear();
		lineread(v);
		ans += solve(v);
		if(v.size() == 0) break;
	}
	cout << ans << '\n';
}
