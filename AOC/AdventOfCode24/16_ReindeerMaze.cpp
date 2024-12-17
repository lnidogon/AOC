#include<bits/stdc++.h>
#define breturn return
#define f first
#define s second
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void readline(vector<string> &v) {
    string s;
    while(getline(cin, s)) v.push_back(s);
}

void solve(vector<string> &v) {
    int n = v.size();
    int m = v[0].size();
    int mem[4][n][m];
    int x0,y0,xf,yf;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'S') x0 = i, y0 = j;
            else if(v[i][j] == 'E') xf = i, yf = j;
            for(int k = 0; k < 4; k++) mem[k][i][j] = INT_MAX;
        }
    }
    set<pair<int, pair<int, pair<int, int> > > > s;
    s.insert({0, {0, {x0, y0}}});
    mem[0][x0][y0] = 0;
    bool been[4][n][m];
    memset(been, 0, sizeof(been));
    while(s.size()) {
        auto t = *(s.begin());
        s.erase(s.begin());
        int dir = t.s.f;
        int x = t.s.s.f;
        int y = t.s.s.s;
        int val = t.f; 
        if(been[dir][x][y]) continue;
        been[dir][x][y] = 1;
        if(x == xf && y == yf) {
            cout << val;
            s.clear();
            continue;
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx >= 0 && ny >= 0 && nx < n && nx < m && v[nx][ny] != '#' && mem[dir][nx][ny] > val + 1) {
            auto it = s.find({mem[dir][nx][ny], {dir, {nx, ny}}});
            if(it != s.end()) s.erase(it);
            mem[dir][nx][ny] = val + 1;
            s.insert({mem[dir][nx][ny], {dir, {nx, ny}}});
        }
        int dirl = (dir + 3)%4;
        int dirr = (dir + 1)%4;
        if(mem[dirl][x][y] > val + 1000) {
            auto it = s.find({mem[dirl][x][y], {dirl, {x, y}}});
            if(it != s.end()) s.erase(it);
            mem[dirl][x][y] = val + 1000;
            s.insert({mem[dirl][x][y], {dirl, {x, y}}}); 
        } 
        if(mem[dirr][x][y] > val + 1000) {
            auto it = s.find({mem[dirr][x][y], {dirr, {x, y}}});
            if(it != s.end()) s.erase(it);
            mem[dirr][x][y] = val + 1000;
            s.insert({mem[dirr][x][y], {dirr, {x, y}}}); 
        }
    }
} 

int main() {
    vector<string> v;
    readline(v);
    solve(v);
}