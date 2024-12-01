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
    bool con1 = false;
    bool con2 = false;
    for(int i = 0; i < t.size()-1; i++) {
      for(int j = i+2; j < t.size()-1; j++) {
        if(t[i]==t[j] and t[i+1]==t[j+1]) con1=true;
      }
      if(i<t.size()-2) {
        if(t[i]==t[i+2]) con2=true;
      }
    }
   ans += con1*con2;
  }
  cout << ans << '\n';
}
int main() 
{
    vector<string> v;
    readline(v);
    solve(v);
}
