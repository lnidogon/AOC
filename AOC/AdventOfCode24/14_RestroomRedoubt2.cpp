#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;

void readline(vector<pair<pair<ll, ll>, pair<ll, ll> > > &v) {
    string s;
    while(getline(cin, s)) {
        ll id = 2;
        ll nid = s.find(",");
        ll x = stoi(s.substr(id, nid - id));
        id = nid + 1;
        nid = s.find(" ");
        ll y = stoi(s.substr(id, nid - id));
        id = nid + 3;
        nid = s.find(",", id);
        ll vx = stoi(s.substr(id, nid - id));
        id = nid + 1;
        nid = s.size();
        ll vy = stoi(s.substr(id, nid - id));
        v.push_back({{y, x}, {vy, vx}});
    }
}

void solve(vector<pair<pair<ll, ll>, pair<ll, ll> > > &v) {
    ll n = 103;
    ll m = 101;
    ll T = 7131;
    ll mat[n][m];
    ll minmx = 10000;
    string s;
    ll minsim = 10000000;
    while(true) {
        T++;
        //if(T%1000) cout << T << " " << minmx << '\n';
        memset(mat, 0, sizeof(mat));
        for(auto t:v) {
            ll x = t.first.first;
            ll y = t.first.second;
            ll vx = t.second.first;
            ll vy = t.second.second;
            ll fx = (x + vx * T + n * T)%n;
            ll fy = (y + vy * T + m * T)%m;
            mat[fx][fy]++;
        }
        ll mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mx = max(mx, mat[i][j]);
            }
        }
        minmx = min(mx, minmx);
        break;
    }
    cout << T << ": \n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << (mat[i][j]?"O":".") << "  ";
        }
        cout << '\n';
    }
}

int main() {
    vector<pair<pair<ll, ll>, pair<ll, ll> > > v;
    readline(v);
    solve(v); 
}