#include<bits/stdc++.h>
#define breturn return
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1}; 

void readline(vector<string> &v, vector<string> &v2) {
    string s;
    while(getline(cin, s)) {
        if(s == "") break;
        else {
            string ss = "";
            for(auto t:s) {
                if(t == '@') ss.push_back('@'), ss.push_back('.');
                else if(t == 'O') ss.push_back('['), ss.push_back(']');
                else ss.push_back(t), ss.push_back(t);
            }
            v.push_back(ss);
            
        }
    }
    while(getline(cin, s)) 
        v2.push_back(s);
    

}

bool can_mov(vector<string> &v, int x, int y, int dir) {
    if(v[x][y] == '.') return true;
    else if(v[x][y] == '#') return false;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(dir%2) return can_mov(v, nx, ny, dir);
    else {
        if(v[x][y] == '[') return can_mov(v, nx, ny, dir) && can_mov(v, nx, ny + 1, dir);
        else if(v[x][y] == ']') return can_mov(v, nx, ny - 1, dir) && can_mov(v, nx, ny, dir);
        else return can_mov(v, nx, ny, dir);
    }
}

void mov(vector<string> &v, int x, int y, int dir) {
    if(v[x][y] == '.' || v[x][y] == '#') return;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(dir%2 || v[x][y] == '@') {
        mov(v, nx, ny, dir);
        v[nx][ny] = v[x][y];
        v[x][y] = '.';
    }
    else {
        if(v[x][y] == '[') {
            v[x][y] = '.';
            mov(v, x, y + 1, dir);
            mov(v, nx, ny, dir);
            v[nx][ny] = '[';
        }
        else if(v[x][y] == ']') {
            v[x][y] = '.';
            mov(v, x, y - 1, dir);
            mov(v, nx, ny, dir);
            v[nx][ny] = ']';
        }
    }
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
        if(can_mov(v, x0, y0, dir)) {
            mov(v, x0, y0, dir);
            x0 = nx, y0 = ny;
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            if(v[i][j] == '[') sum += 100 * i + j;
        
    
    cout << sum;
}

int main() {
    vector<string> v, v2;
    readline(v, v2);
    solve(v, v2);
}