//MOBITEL

#include<bits/stdc++.h>
using namespace std;
int a,b,ans;
set<int> s;
int main() {
int x;
for(int i = 0; i < 202; i++){
if(!scanf("Card: %d", &x)) break;
for(int i = 0; i < 10; i++) cin >> a, s.insert(a);
scanf("|");
for(int i = x = 0; i < 25; i++) cin >> a, x += (s.find(a) != s.end());
if(x)ans += (1<<(x-1));
}
cout << ans;
}
