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
    int n = v.size();
    bool been[n +1][n + 1];
    memset(been, 0, sizeof(been));
    int px, py, dir = 0;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == '^') px = i, py = j;
        }
    }
    while(px < n && py < n && px >= 0 && py >= 0) {
        been[px][py] = true;
        int nx = px + dx[dir];
        int ny = py + dy[dir];
        if(nx < n && ny < n && nx >= 0 && ny >= 0 && v[nx][ny] == '#') dir = (dir + 1)%4;
        else px = nx, py = ny;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans += been[i][j];
    cout << ans;
}

int main() {
    vector<string> v;
    readline(v);
    solve(v);
}