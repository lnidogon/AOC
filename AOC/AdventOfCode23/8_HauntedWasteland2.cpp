#include<bits/stdc++.h>
#define breturn return
using namespace std;
int conv(string s){
return (s[0]-'A')*30*30 + (s[1]-'A')*30 + (s[2]-'A');
}
string s,a,b,c,z;
long long graph[100000][2],x,ans, gcans;
vector<int> v, vs;
int main() {
  getline(cin, z);
getline(cin, s);
while(getline(cin, s)) {
a = s.substr(0, 3);
if(conv(a)%30==0) v.push_back(conv(a));
b = s.substr(7,3);
c = s.substr(12,3);
graph[conv(a)][0]= conv(b);
graph[conv(a)][1]= conv(c);
}

for(int i = 0; i < v.size(); i++) {
  x = v[i];
  ans = 0;
  while(x%30 != 'Z'-'A') {
x = graph[x][z[ans%z.size()]=='R'];
ans++;
}
if(gcans) {
  gcans = gcans * ans / __gcd(gcans, ans);
} else gcans = ans;
}
cout << gcans;
}
