#include<bits/stdc++.h>
#define breturn return
using namespace std;

void readline(vector<pair<int, int> > &v) {
    string s;
    while(getline(cin, s)) {
        string s1 = s.substr(0, 2);
        string s2 = s.substr(3, 2);
        int n1 = (s1[0] - 'a') * 30 + (s1[1] - 'a');
        int n2 = (s2[0] - 'a') * 30 + (s2[1] - 'a');
        v.push_back({n1, n2});
    }
}
bool grap[1000][1000];
void solve(vector<pair<int, int> > &v) {
    for(auto t:v) 
        grap[t.first][t.second] = true, grap[t.second][t.first] = true;
    int ans = 0;
    for(int i = 0; i < 1000; i++) for(int j = i + 1; j < 1000; j++) for(int k = j + 1; k < 1000; k++) 
        ans += grap[i][j] && grap[j][k] && grap[k][i] && (i/30 == 't' - 'a' || j/30 == 't' - 'a' || k/30 == 't' - 'a');
    cout << ans;
}

int main() {
    vector<pair<int, int> > v;
    readline(v);
    solve(v);

}