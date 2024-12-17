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
            for(int k = 0; k < 4; k++) mem[k][i][j] = 1e9;
        }
    }
    set<pair<int, pair<int, pair<int, int> > > > s;
    s.insert({0, {0, {x0, y0}}});
    mem[0][x0][y0] = 0;
    bool been[4][n][m];
    memset(been, 0, sizeof(been));
    int ans = 0;
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
            ans = val;
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
    set<pair<int, int> > st;
    queue<pair<int, pair<int, int> > > q;
    memset(been, 0, sizeof(been));
    for(int i = 0; i < 4; i++) if(mem[i][xf][yf] == ans) q.push({i, {xf, yf}});
    while(q.size()) {
        auto fr = q.front();
        int dir = fr.f;
        int x = fr.s.f;
        int y = fr.s.s;
        st.insert({x, y});
        q.pop();
        int nx = x - dx[dir];
        int ny = y - dy[dir];
        int dirr = (dir + 3)%4;
        int dirl = (dir + 1)%4;
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && v[nx][ny] != '#' && mem[dir][nx][ny] + 1 == mem[dir][x][y] && !been[dir][nx][ny]) {
            q.push({dir, {nx, ny}});
            been[dir][nx][ny] = true;
        }
        
        if(mem[dirr][x][y] + 1000 == mem[dir][x][y] && !been[dirr][x][y]) {
            q.push({dirr, {x, y}});
            been[dirr][x][y] = true;
        }
        if(mem[dirl][x][y] + 1000 == mem[dir][x][y] && !been[dirl][x][y]) {
            q.push({dirl, {x, y}});
            been[dirl][x][y] = true;
        }
    }
    cout << st.size();
} 

int main() {
    vector<string> v;
    readline(v);
    solve(v);
}