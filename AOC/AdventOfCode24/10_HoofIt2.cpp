#include<bits/stdc++.h>
#define breturn return
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void readline(vector<string> &v) {
    string s;
    while(getline(cin, s)) {
        v.push_back(s);
    }
}

int rek(bool (&been)[60][60], int (&dp)[60][60], vector<string> &v, int x, int y) {
    if(been[x][y]) return dp[x][y];
    been[x][y] = 1;
    if(v[x][y] == '9') return dp[x][y] = 1;
    dp[x][y] = 0;
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if(nx >= 0 && ny >= 0 && nx < v.size() && ny < v[0].size() && v[nx][ny] - v[x][y] == 1) 
            dp[x][y] += rek(been, dp, v, nx, ny);        
    }
    return dp[x][y];
} 


void solve(vector<string> &v) {
    bool been[60][60];
    int dp[60][60];
    int ans = 0;
    memset(been, 0, sizeof(been));
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) {
            if(v[i][j] == '0') ans += rek(been, dp, v, i, j);
        }
    }
    cout << ans;
}

int main() {
    vector<string> v;
    readline(v);
    solve(v);
}