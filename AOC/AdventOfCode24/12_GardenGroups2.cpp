#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;

const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, -1, 0, 1};
void readline(vector<string> &v) {
    string s;
    while(getline(cin, s)) {
        v.push_back(s);
    }
}

void dfs(ll x, ll y, ll gc, ll (&col)[200][200], vector<string> &v, ll (&sus)[200][200]) {
    col[x][y] = gc;
    for(ll i = 0; i < 4; i++) {
        ll xx = x + dx[i];
        ll yy = y + dy[i];
        if(xx < 0 || xx >= v.size() || yy < 0 || yy >= v[0].size() || v[xx][yy] != v[x][y]) continue;
        else if(!col[xx][yy]) dfs(xx, yy, gc, col, v, sus);
    }
}


void solve(vector<string> &v) {
    ll col[200][200];
    ll sus[200][200];
    pair<int, int> lop[600];
    ll ans_area[600];
    ll ans_peri[600];
    ll mem[4][200][200];
    memset(col, 0, sizeof(col));
    memset(sus, 0, sizeof(sus));
    memset(ans_area, 0, sizeof(ans_area));
    memset(ans_peri, 0, sizeof(ans_peri));
    memset(mem, 0, sizeof(mem));
    ll n = v.size();
    ll gc = 0;
    for(ll i = 0; i < n; i++) 
        for(ll j = 0; j < n; j++) 
            if(col[i][j] == 0) dfs(i, j, ++gc, col, v, sus);
    for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) {
        ans_area[col[i][j]]++;
        if(mem[2][i][j] == 0 && (i == 0 || v[i - 1][j] != v[i][j])) {
            ll x0 = i;
            ll y0 = j;
            ll lokdir = 2;
            ll movdir = 3;
            ll x = i;
            ll y = j;
            do {
                mem[lokdir][x][y] = 1;
                ll lx = x + dx[lokdir];
                ll ly = y + dy[lokdir];
                ll nx = x + dx[movdir];
                ll ny = y + dy[movdir];
                if(lx >= 0 && ly >= 0 && lx < n && ly < n && v[lx][ly] == v[x][y]) {
                    x = lx;
                    y = ly;
                    ans_peri[col[x][y]]++;
                    movdir = lokdir;
                    lokdir = (lokdir + 3)%4;
                } else if(nx < 0 || ny < 0 || nx >= n || ny >= n || v[nx][ny] != v[x][y]) {
                    ans_peri[col[x][y]]++;
                    movdir = (movdir + 1)%4;
                    lokdir = (lokdir + 1)%4;
                } else x = nx, y = ny;
            } while(x != x0 || y != y0 || movdir != 3);         
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= gc; i++) ans += ans_area[i] * ans_peri[i];
    cout << ans; 
    
}


int main() {
    vector<string> v;
    readline(v);
    solve(v);
}