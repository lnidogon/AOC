#include<bits/stdc++.h>
#define breturn return
using namespace std;
vector<int> v1, v2;
void readline(vector<int> &v1, vector<int> &v2) {
    string s;
    while(getline(cin, s)) {
        int id = s.find(' ');
        int a = stoi(s.substr(0, id + 1));
        int b = stoi(s.substr(id + 1, s.size() - id));
        v1.push_back(a);
        v2.push_back(b);
    }
}
void solve(vector<int> &v1, vector<int> &v2) {
    int ans = 0;
    sort(v1.begin(), v1.end());
    map<int, int> m;
    for(auto t:v2) m[t]++;
    for(auto t:v1) 
        ans += m[t] * t;
    cout << ans;
}
int main() {
    readline(v1, v2);
    solve(v1, v2);
}