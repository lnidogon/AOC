#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;

const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, 1, 0, -1};

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
        if(xx < 0 || xx >= v.size() || yy < 0 || yy >= v[0].size() || v[xx][yy] != v[x][y]) sus[x][y]++;
        else if(!col[xx][yy]) dfs(xx, yy, gc, col, v, sus);

    }
}

void solve(vector<string> &v) {
    ll col[200][200];
    ll sus[200][200];
    ll ans_area[600];
    ll ans_peri[600];
    memset(col, 0, sizeof(col));
    memset(sus, 0, sizeof(sus));
    memset(ans_area, 0, sizeof(ans_area));
    memset(ans_peri, 0, sizeof(ans_peri));
    ll n = v.size();
    ll gc = 0;
    for(ll i = 0; i < n; i++) 
        for(ll j = 0; j < n; j++) 
            if(col[i][j] == 0) dfs(i, j, ++gc, col, v, sus);
    for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) {
        ans_area[col[i][j]]++;
        ans_peri[col[i][j]]+=sus[i][j];
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