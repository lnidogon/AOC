#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;

const ll MOD = (1<<24);


void readline(vector<ll> &v) {
    string s;
    while(getline(cin, s)) {
        v.push_back(stoi(s));
    }
}


void solve(vector<ll> &v) {
    ll ans = 0;
    for(auto t:v) {
        ll sn = t;
        for(ll i = 0; i < 2000; i++) {
            sn = (sn^(sn << 6))%MOD;
            sn = (sn^(sn >> 5))%MOD;
            sn = (sn^(sn << 11))%MOD;
        }
        ans += sn;
    }
    cout << ans;
}

int main() {
    vector<ll> v;
    readline(v);
    solve(v);
}