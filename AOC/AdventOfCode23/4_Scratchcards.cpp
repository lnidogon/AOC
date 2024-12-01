#include<bits/stdc++.h>
using namespace std;
int a,b,ans;
set<int> s;
vector<int> v;
int val[300];
int main() {
int x, y;
for(int j = 0; j < 202; j++) {
val[j+1]++;
scanf("Card %3d:", &y);
s.clear();
for(int i = 0; i < 10; i++) cin >> a, s.insert(a);
scanf(" |");
//for(auto t:s) cout << t << "_";
for(int i = x = 0; i < 25; i++) {
  
  cin >> a, x += (s.find(a) != s.end());
  }
for(int i = 0; i < x; i++) val[y+i+1] += val[y];
ans+=val[y];
scanf("\n");
}
cout << ans;
}
