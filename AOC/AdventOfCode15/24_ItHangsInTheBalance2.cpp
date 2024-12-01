#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;
void readline(vector<ll> &v) {
	fstream f;
	f.open("24_input.txt");
	string s;
	while(getline(f, s)) v.push_back(stoi(s));
	
}
bool been[30][600][600];
ll dp[30][600][600];
ll rek(vector<ll> &v, vector<ll> &vv, ll &val, ll x, ll y, ll z) {
	if(x == v.size() and y == val and z == val) {
		vector<int> vvv;
		vvv.clear();
		for(auto t:v) {
			bool skp = false;
			for(auto tt:vv)
				if(t == tt) skp = true;
			if(skp) continue;
			vvv.push_back(t);
		}
		bool poss = false;
		for(int i = 0; i < (1 << vvv.size()); i++) {
			int a = 0, b = 0;
			for(int j = 0; j < vvv.size(); j++) ((i >> j)%2?a:b) += vvv[j];
			if(a == b) {
				poss = true;
				break;
			}
		} 
		return poss;
	}
	else if(x == v.size()) return 1e14;
	if(been[x][y][z]) return dp[x][y][z];
	been[x][y][z] = 1;
	dp[x][y][z] = 1e14;
	dp[x][y][z] = min(dp[x][y][z], rek(v, vv, val, x + 1, y, z));
	vv.push_back(v[x]);
	if(y + v[x] <= val) dp[x][y][z] = min(dp[x][y][z], rek(v, vv, val, x + 1, y + v[x], z) * v[x]);
	if(z + v[x] <= val) dp[x][y][z] = min(dp[x][y][z], rek(v, vv, val, x + 1, y, z + v[x]));
	vv.pop_back();
	return dp[x][y][z];
}
void solve(vector<ll> &v) {
	ll sum = 0;
	for(auto t:v) sum += t;
	vector<ll> vv;
	sum /= 4;
	cout << rek(v, vv, sum, 0, 0, 0) << '\n';
} 
int main() {
	vector<ll> v;
	readline(v);
	solve(v);	
}
