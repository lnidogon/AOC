#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;

void readline(ll &a, ll &b, ll &c, vector<ll> &v) {
    string s;
    getline(cin, s);
    a = stoll(s.substr(12));
    getline(cin, s);
    b = stoll(s.substr(12));
    getline(cin, s);
    c = stoll(s.substr(12));
    getline(cin, s);
    getline(cin, s);
    s = s.substr(9);
    ll id = 0;
    while(id < s.size()) {
        v.push_back(s[id] - '0');
        id += 2;
    }
}


ll comboOperand(ll val, ll &a, ll &b, ll &c) {
    if(val <= 3) return val;
    if(val == 4) return a;
    if(val == 5) return b;
    if(val == 6) return c;
}


void solve(ll &a, ll &b, ll &c, vector<ll> &v) {
    ll pt = 0;
    vector<ll> ans;
    while(pt < v.size()) {
        if(v[pt] == 0) {
            a = a / (1 << comboOperand(v[pt + 1], a, b, c));
        } else if(v[pt] == 1) {
            b = b ^ v[pt + 1];
        } else if(v[pt] == 2) {
            b = comboOperand(v[pt + 1], a, b, c) % 8;
        } else if(v[pt] == 3) {
            if(a > 0) pt = v[pt + 1] * 2 - 2; 
        } else if(v[pt] == 4) {
            b = b ^ c;
        } else if(v[pt] == 5) {
            ans.push_back(comboOperand(v[pt + 1], a, b, c)%8);
        } else if(v[pt] == 6) {
            b = a / (1 << comboOperand(v[pt + 1], a, b, c));
        } else if(v[pt] == 7) {
            c = a / (1 << comboOperand(v[pt + 1], a, b, c));    
        }
        pt += 2;
    }
    for(auto t:ans) cout << t << ",";

}

int main() {
    ll a, b, c;
    vector<ll> v;
    readline(a, b, c, v);
    solve(a, b, c, v);

}