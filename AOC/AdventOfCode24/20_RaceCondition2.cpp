#include<bits/stdc++.h>
#define breturn return
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


void readline(vector<string> &v) {
    string s;
    while(getline(cin, s)) v.push_back(s);
}

void bfs(int (&mem)[200][200], int x0, int y0, vector<string> &v) {
    mem[x0][y0] = 0;
    int n = v.size();
    queue<pair<int, int>> q;
    q.push({x0, y0});
    while(q.size()) {
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && yy >= 0 && xx < n && yy < n && v[xx][yy] != '#' && mem[xx][yy] > mem[x][y] + 1) {
                mem[xx][yy] = mem[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
}


void solve(vector<string> &v) {
    int n = v.size();
    int memf[200][200], memb[200][200], memt[200][200];
    int x0, y0, xf, yf;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        memf[i][j] = 1e8;
        memb[i][j] = 1e8;
        memt[i][j] = 1e8;
        if(v[i][j] == 'S') x0 = i, y0 = j;
        else if(v[i][j] == 'E') xf = i, yf = j;
    }
    bfs(memf, x0, y0, v);
    bfs(memb, xf, yf, v);
    int goaldist = memb[x0][y0] - 100;
    set<pair<pair<int, int>, pair<int, int> > > ans;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(v[i][j] != '#') {
        vector<pair<int, int> > refstack;
        queue<pair<int, int> > q;
        vector<pair<int, int> > chk;
        memt[i][j] = 0;
        q.push({i, j});
        refstack.push_back({i, j});
        while(q.size()) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            for(int k = 0; k < 4; k++) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if(xx >= 0 && yy >= 0 && xx < n && yy < n && memt[xx][yy] > memt[x][y] + 1 && memt[x][y] < 20) {
                    memt[xx][yy] = memt[x][y] + 1;
                    refstack.push_back({xx, yy});
                    if(v[xx][yy] == '#') q.push({xx, yy});
                    else q.push({xx, yy}), chk.push_back({xx, yy});
                }
            }
        }
        for(auto t:chk) if(memf[i][j] + memb[t.first][t.second] + memt[t.first][t.second] <= goaldist) ans.insert({{i, j}, t});
        for(auto t:refstack) memt[t.first][t.second] = 1e8;
    }
    cout << ans.size();
    
}

int main() {
    vector<string> v;
    readline(v);
    solve(v);
}