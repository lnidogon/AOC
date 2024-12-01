#include<bits/stdc++.h>
#define breturn return
using namespace std;
int conv(const string &s){
return (s[0]-'A')*30*30 + (s[1]-'A')*30 + (s[2]-'A');
}
string s,a,b,c,z;
int graph[100000][2],x,ans;
int main() {
getline(cin,s);
getline(cin,z);
while(true) {
  if(!getline(cin,z)) break;
a = z.substr(0, 3);
b = z.substr(7,3);
c = z.substr(12,3);
graph[conv(a)][0]= conv(b);
graph[conv(a)][1]= conv(c);
}

while(x != conv("ZZZ")) {
  //cout<< x << " " << ans <<'\n';
x = graph[x][s[ans%s.size()]=='R'];
ans++;
}
cout << ans;
}
