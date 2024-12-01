#include<bits/stdc++.h>
using namespace std;

void readline(vector<string> &v) {
  fstream f;
  f.open("input.txt", ios::in);
  string s;
  while(getline(f, s)) {
    v.push_back(s), cout << s<<'\n';
  }
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
   //return;
 for(int i=0;i < v.size(); i++) {
    int mins = -1;
    for(int j = 0; j < v[0].size(); j++) {
      if(v[i][j] == '#') mins = j;
      if(v[i][j] == 'O') {
       v[i][j] = '.';
        v[i][mins + 1] = 'O';
        mins = min(mins+1, j);
      }
    }
  } 
 //return;
 for(int j = 0; j < v[0].size(); j++) {
    int mins = v.size();
    for(int i = v.size()-1; i >= 0; i--) {
      if(v[i][j] == '#') mins = i;
      if(v[i][j] == 'O') {
       v[i][j] = '.';
        v[mins-1][j] = 'O';
        mins = max(mins-1, i);
      }
    }
  } 
  //return;
 for(int i = 0; i < v.size(); i++) {
    int mins = v[0].size();
    for(int j = v[0].size()-1; j >= 0; j--) {
      if(v[i][j] == '#') mins = j;
      if(v[i][j] == 'O') {
       v[i][j] = '.';
        v[i][mins-1] = 'O';
        mins = max(mins-1, j);
      }
    }
  } 
}
void solve(vector<string> &v) {
  map<int, int> m;
  for(int k = 1; k <= 205; k++) {
 int ans = 0;
 cycle(v);
 for(int i = 0; i < v.size(); i++) {
    for(int j = 0; j < v[0].size(); j++) {
      //cout << v[i][j] << " ";
      if(v[i][j] == 'O') ans += (v.size()-i);
    }
    //cout << '\n';
  }
  cout<<ans << '\n';
  
  if(m.find(ans) != m.end()) 
  cout << "same at " << m[ans] << " " << k <<'\n';
  m[ans] = k;
  }
}

int main() {
  vector<string> v;
  readline(v);
  solve(v);
  
}
