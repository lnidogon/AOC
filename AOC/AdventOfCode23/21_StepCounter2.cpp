#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;
void readline(vector<string> &v) {
	fstream f;
	f.open("input2.txt", ios::in);
	string s;
	while(getline(f, s)) v.push_back(s);
}
const ll dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, N = 202300;
ll mat[141][141];
ll bfs(vector<string> &v, ll x, ll y, ll k, bool b) {
	memset(mat, -1, sizeof(mat));
	queue<pair<ll, pair<ll, ll> > > q;
	q.push({0, {x, y}});
	mat[x][y] = 0;
	while(q.size()) {
		auto x = q.front().second;
		q.pop();
		for(ll i = 0; i < 4; i++) 	{
			ll xx = x.first + dx[i], yy = x.second + dy[i];
			if(xx < 0 or yy < 0 or xx >= v.size() or yy >= v.size() or v[xx][yy] == '#' or ~mat[xx][yy]) continue;
			mat[xx][yy] = mat[x.first][x.second] + 1;
			q.push({mat[xx][yy], {xx, yy}});			
		}
	}
	long long ret = 0;
	for(ll i = 0; i < v.size(); i++) for(ll j = 0; j < v.size(); j++) ret += (mat[i][j] <= k and mat[i][j]%2 == b and ~mat[i][j]);
	return ret;
}
void solve(vector<string> &v) {
	ll s1  = bfs(v, v.size()/2, v.size()/2, 131, 1),
	   s2  = bfs(v, v.size()/2, v.size()/2, 131, 0),	
	   k1  = bfs(v,          0,          0,  64, 0),
	   k2  = bfs(v,          0, v.size()-1,  64, 0),
	   k3  = bfs(v, v.size()-1,          0,  64, 0),
	   k4  = bfs(v, v.size()-1, v.size()-1,  64, 0),
	   k21 = bfs(v,          0,          0, 195, 1),
	   k22 = bfs(v,          0, v.size()-1, 195, 1),
	   k23 = bfs(v, v.size()-1,          0, 195, 1),
	   k24 = bfs(v, v.size()-1, v.size()-1, 195, 1),
	   b1  = bfs(v,          0, v.size()/2, 130, 0),
	   b2  = bfs(v, v.size()-1, v.size()/2, 130, 0),
	   b3  = bfs(v, v.size()/2,          0, 130, 0),
	   b4  = bfs(v, v.size()/2, v.size()-1, 130, 0),
	   a1 = 1, a2 = 0;
	for(ll i = 1; i < N; i++) (i%2?a2:a1) += 4 * i; 
	cout <<  (a1 * s1 + a2 * s2) + (N) * (k1 + k2 + k3 + k4) + (N - 1) * (k21 + k22 + k23 + k24) + (b1 + b2 + b3 + b4);
}
int main() {
	vector<string> v;
	readline(v);
	solve(v);
}
