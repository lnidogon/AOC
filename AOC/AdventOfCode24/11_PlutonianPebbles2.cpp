#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;
void readline(vector<ll> &v) {
    string s;
    getline(cin, s);
    ll id = 0;
    s += " ";
    while(id < s.size()) {
        ll nx = s.find(" ", id);
        string st = s.substr(id, nx - id);
        id = nx + 1;
        v.push_back(stoi(st));
    }
}

ll rek(ll x, ll dep, map<pair<ll, ll>, ll> &mem) {
    if(dep == 75) return 1;
    if(mem.find({x, dep}) != mem.end()) return mem[{x, dep}];
    string strx = to_string(x);
    if(x == 0) return mem[{x, dep}] = rek(1, dep + 1, mem);
    else if(strx.size()%2 == 0) {
        return mem[{x, dep}] = rek(stoi(strx.substr(0, strx.size()/2)), dep + 1, mem) + rek(stoi(strx.substr(strx.size()/2)), dep + 1, mem);
    } else return mem[{x, dep}] = rek(x * 2024, dep + 1, mem);
}

void solve(vector<ll> &v) {
    vector<ll> v0;
    map<pair<ll, ll>, ll> mem;
    ll ans = 0;
    for(ll i = 0; i < v.size(); i++) ans += rek(v[i], 0, mem);
    cout << ans;
}
int main() {
    vector<ll> v;
    readline(v);
    solve(v);
}