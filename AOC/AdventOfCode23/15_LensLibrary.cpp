#include <bits/stdc++.h>
using namespace std;
void readline(vector<string> &v) {
  fstream f;
  f.open("input.txt", ios::in);
  string s;
  getline(cin, s);
  s += ',';
  int x = 0;
  while(x < s.size()) {
    int y = s.find(',', x);
    v.push_back(s.substr(x, y - x));
    x = y + 1;
  }
}
int hass(string &s) {
  const int B = 17;
  const int MOD = 256;
  int ret = 0;
  for(auto t:s) ret = ((ret+t)*B)%MOD;
  return ret;
}
void solve(vector<string> &v) {
  int ans = 0;
  for(auto t:v) ans += hass(t);
  cout << ans<<'\n';
}

int main() 
{
    vector<string> v;
    readline(v);
    for(auto t:v) cout << t << " " << hass(t) << '\n';
    solve(v);
    return 0;
}
