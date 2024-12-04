#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<string> &v) {
    string s;
    while(getline(cin, s)) {
        v.push_back(s);
    }
}
void solve(vector<string> &v) {
    int dx[] = {-1, -1, 1, 1};
    int dy[] = {-1, 1, 1, -1};
    int ans = 0;
    int n = v.size();
    int m = v[0].size();
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < m -1 ; j++) if(v[i][j] == 'A') {
            for(int k = 0; k < 4; k++) {
                int A = k%4, B = (k + 1)%4, C = (k + 2)%4, D = (k + 3)%4;
                if(v[i + dx[A]][j + dy[A]] == 'M' && v[i + dx[B]][j + dy[B]] == 'M' && v[i + dx[C]][j + dy[C]] == 'S' && v[i + dx[D]][j + dy[D]] == 'S') {
                    ans++;                
                }
            }
        }
    }
    cout << ans;
}
int main() {
    vector<string> v;
    readline(v);
    solve(v);
}