#include <bits/stdc++.h>
#define breturn return
using namespace std;

void readline(vector<string> &v) {
  fstream f;
  f.open("5_input.txt");
  string s;
  while(getline(f, s)) {
    v.push_back(s);
  }
}
void solve(vector<string> &v) {
  int ans = 0;
  for(auto t:v) {
    int nov = 0;
    bool twr = false;
    bool spec = false;
    for(int i = 0; i < t.size(); i++) {
      char c1 = t[i];
      char c2 = '\0';
      if(i < t.size()-1) c2 = t[i+1];
      if(c1=='a' or c1 == 'o' or c1 == 'u'
      or c1 == 'e' or c1 == 'i') {
        nov++;
      }
      if(c1 == c2) twr = true;
      if(c1 == 'a' and c2 == 'b'
      or c1 == 'p' and c2 == 'q'
      or c1 == 'x' and c2 == 'y'
      or c1 == 'c' and c2 == 'd') {
        spec = true;
      }
    }
    if(nov >= 3 and twr and !spec) ans++;
  }
  cout << ans << '\n';
}
int main() 
{
    vector<string> v;
    readline(v);
    solve(v);
}
