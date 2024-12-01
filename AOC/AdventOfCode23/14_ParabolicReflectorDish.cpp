#include<bits/stdc++.h>
using namespace std;

void readline(vector<string> &v) {
  fstream f;
  f.open("input.txt", ios::in);
  string s;
  while(getline(f, s)) v.push_back(s);
}

void cycle(vector<string> &v) {
   for(int j = 0; j < v[0].size(); j++) {
    int mins = -1;
    for(int i = 0; i < v.size(); i++) {
      if(v[i][j] == '#') mins = i;
      if(v[i][j] == 'O') {
       v[i][j] = '.';
        v[mins+1][j] = 'O';
        mins = min(mins+1, i);
      }
    }
  }
}
void solve(vector<string> &v) {
 int ans = 0;
 cycle(v);
 for(int i = 0; i < v.size(); i++) {
    for(int j = 0; j < v[0].size(); j++) {
      cout << v[i][j] << " ";
      if(v[i][j] == 'O') ans += (v.size()-i);
     }
    cout << '\n';
  }
  cout<<ans;
}

int main() {
  vector<string> v;
  readline(v);
  solve(v);
  
}
