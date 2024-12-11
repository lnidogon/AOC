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

void rek(ll x, ll dep, vector<ll> &v0) {
    if(dep == 25) {
        v0.push_back(x);
        return;
    }
    string strx = to_string(x);
    if(x == 0) rek(1, dep + 1, v0);
    else if(strx.size()%2 == 0) {
        rek(stoi(strx.substr(0, strx.size()/2)), dep + 1, v0);
        rek(stoi(strx.substr(strx.size()/2)), dep + 1, v0);
    } else rek(x * 2024, dep + 1, v0);
}

void solve(vector<ll> &v) {
    vector<ll> v0;
    for(ll i = 0; i < v.size(); i++) rek(v[i], 0, v0);
    cout << v0.size();
}
int main() {
    vector<ll> v;
    readline(v);
    solve(v);
}