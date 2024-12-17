#include<bits/stdc++.h>
#define breturn return
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1}; 

void readline(vector<string> &v, vector<string> &v2) {
    string s;
    while(getline(cin, s)) {
        if(s == "") break;
        else v.push_back(s);
    }
    while(getline(cin, s)) 
        v2.push_back(s);
    

}

bool mov(vector<string> &v, int x, int y, int dir) {
    if(v[x][y] == '.') return true;
    else if(v[x][y] == '#') return false;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(mov(v, nx, ny, dir)) {
        v[nx][ny] = v[x][y];
        v[x][y] = '.';
        return true;
    } else return false;
}

void outmat(vector<string> &v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) {
            cout << v[i][j];
        }
        cout << '\n';
    }
}


void solve(vector<string> &v, vector<string> &v2) {
    int n = v.size();    
    int m = v[0].size();
    int x0, y0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            if(v[i][j] == '@') x0 = i, y0 = j;
    for(auto tt:v2) for(auto t:tt) {
        int dir;
        if(t == '^') dir = 0;
        else if(t == '>') dir = 1;
        else if(t == '<') dir = 3;
        else dir = 2;
        int nx = x0 + dx[dir];
        int ny = y0 + dy[dir];
        if(mov(v, x0, y0, dir)) x0 = nx, y0 = ny;
    }
    int sum = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            if(v[i][j] == 'O') sum += 100 * i + j;
        
    
    cout << sum;
}

int main() {
    vector<string> v, v2;
    readline(v, v2);
    solve(v, v2);
}