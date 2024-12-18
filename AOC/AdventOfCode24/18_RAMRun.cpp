#include<bits/stdc++.h>
#define breturn return
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

void readline(vector<pair<int, int> > &v) {
    string s;
    while(getline(cin, s)) {
        int id = s.find(',');
        int x = stoi(s.substr(0, id));
        int y = stoi(s.substr(id + 1));
        v.push_back({x, y});
    }
}

void solve(vector<pair<int, int> > &v) {
    const int n = 71;
    const int lim = 1024;
    int mat[n][n];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) mat[i][j] = 1e8;
    for(int i = 0; i < lim; i++) {
        mat[v[i].first][v[i].second] = -1;
    }
    mat[0][0] = 0; 
    queue<pair<int, int> > q;
    q.push({0, 0});
    while(q.size()) {
        auto it = q.front();
        int x = it.first;
        int y = it.second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && yy >= 0 && xx < n && yy < n && mat[xx][yy] > mat[x][y] + 1) {
                mat[xx][yy] = mat[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
    cout << mat[n - 1][n - 1];
}

int main() {
    vector<pair<int, int> > v;
    readline(v);
    solve(v);
}