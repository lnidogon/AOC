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

ll rek(ll mask, ll x, ll (&dp)[(1<<7)][16], bool (&been)[(1<<7)][16], pair<ll, ll> (&par)[(1 << 7)][16], string &s) {
    if(x == 16) return 0;
    if(been[mask][x]) return dp[mask][x];
    dp[mask][x] = 1e18;
    been[mask][x] = true;
    for(ll i = 0; i < 8; i++) {
        ll b = i;
        b = b^6;
        ll enchMask = mask * 8 + i;
        ll c = (enchMask / (1 << b))%8;
        b = b ^ c ^ 4;
        ll rekval = rek(enchMask%(1<<7), x + 1, dp, been, par, s);
        if(b == (s[x] - '0') && rekval + (1LL << (16 - x)) * i < dp[mask][x]) {
            dp[mask][x] = rekval;
            par[mask][x] = {enchMask%(1<<7), x + 1};
        }
    }
    return dp[mask][x];
}


void solve(ll &a, ll &b, ll &c, vector<ll> &v) {
    ll dp[(1<<7)][16];
    bool been[(1<<7)][16];
    pair<ll, ll> par[(1<<7)][16];
    memset(been, 0, sizeof(been));
    string s;
    for(auto t:v) s += (t + '0');
    reverse(s.begin(), s.end());
    rek(0, 0, dp, been, par, s);
    pair<ll, ll> p0 = {0, 0};
    long long ans = 0;
    while(p0.second != 16) {
        p0 = par[p0.first][p0.second];
        ans *= 8;
        ans += p0.first%8;
    }
    cout <<  ans;
}

int main() {
    ll a, b, c;
    vector<ll> v;
    readline(a, b, c, v);
    solve(a, b, c, v);

}