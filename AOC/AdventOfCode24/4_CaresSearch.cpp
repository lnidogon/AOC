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
    int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int ans = 0;
    int n = v.size();
    int m = v[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(v[i][j] == 'X') {
            for(int k = 0; k < 8; k++) {
                int mxx = i + dx[k] * 3;
                int myy = j + dy[k] * 3;
                if(mxx >= 0 && mxx < n && myy >= 0 && myy < m && v[i + dx[k]][j + dy[k]] == 'M' && v[i + dx[k] * 2][j + dy[k] * 2] == 'A' && v[mxx][myy] == 'S')
                    ans++;
                
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