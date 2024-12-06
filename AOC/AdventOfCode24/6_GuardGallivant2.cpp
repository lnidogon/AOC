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

bool isLoop(set<pair<int, pair<int, int> > > &pat, vector<string> &v, int dir, int x, int y)  {
    int n = v.size();
    if(pat.find({dir, {x, y}}) != pat.end()) {
        return true;
    }
    pat.insert({dir, {x, y}});
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    bool ret = false;
    if(nx < n && ny < n && nx >= 0 && ny >= 0) {
        if(v[nx][ny] == '#') ret = isLoop(pat, v, (dir + 1)%4, x, y);        
        else ret = isLoop(pat, v, dir, nx, ny);         
    } 
    pat.erase({dir, {x, y}});
    return ret;
}


void solve(vector<string> &v) {
    int n = v.size();
    int px, py, dir = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == '^') px = i, py = j;
        }
    }
    set<pair<int, pair<int, int> > > pat;
    set<pair<int, int> > ans;
    while(px < n && py < n && px >= 0 && py >= 0) {
        pat.insert({dir, {px, py}});
        int nx = px + dx[dir];
        int ny = py + dy[dir];
        if(nx < n && ny < n && nx >= 0 && ny >= 0) {
            if(v[nx][ny] == '#') dir = (dir + 1)%4;
            else {
                v[nx][ny] = '#';
                bool isOnPath = false;
                for(int i = 0; i < 4; i++) isOnPath += (pat.find({i, {nx, ny}}) != pat.end());
                if(!isOnPath && isLoop(pat, v, (dir + 1)%4, px, py)) {
                    ans.insert({nx, ny});
                }
                v[nx][ny] = '.';
                px = nx, py = ny;
            }
        } else break;
    }
    cout << ans.size();
}

int main() {
    vector<string> v;
    readline(v);
    solve(v);
}