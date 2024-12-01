#include <bits/stdc++.h>
using namespace std;
struct lab {
  string name;
  int value;
  lab(string name, int value):
  name(name), value(value) {};
};
void readline(vector<string> &v) {
  fstream f;
  f.open("input.txt", ios::in);
  string s;
  getline(f, s);
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
  
  vector<lab> mat[256];
  for(auto s:v) {
    int h;
    if(s.back()=='-') {
      string name = s.substr(0, s.size()-1);
//   cout<< name << " sub\n";
      h = hass(name);
     // cout << h << '\n';
      bool sw = 0;
      for(int i = 0; i < mat[h].size(); i++) {
        if(mat[h][i].name == name) sw = 1;
        if(i < mat[h].size() - 1 and sw) mat[h][i] = mat[h][i+1];
      }
      if(sw) mat[h].pop_back();
    }
    else {
      string name = s.substr(0, s.size()-2);
      
      h = hass(name);
      lab nlab(name, s.back()-'0');
    //  cout << name << " set " << nlab.value << '\n';
      //cout << h << '\n';
      bool put = 0;
      for(int i = 0; i < mat[h].size(); i++) {
        if(mat[h][i].name == nlab.name) mat[h][i] = nlab, put = 1;
      }
      if(!put) mat[h].push_back(nlab);
    }
    //for(auto t:mat[h]) cout << t.name << " " << t.value << '\n';
  }
  for(int i = 0; i < 256; i++) {
    for(int j = 0; j < mat[i].size(); j++) {
      //cout << j + 1<< ":" << mat[i][j].value << " ";
      ans += (i+1)*(j+1)*mat[i][j].value;
    }
  }
  cout << ans;
}

int main() {
  vector<string> v;
  readline(v);
    solve(v);
    return 0;
}
