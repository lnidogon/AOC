#include<bits/stdc++.h.>
#define breturn return
#define ll long long
using namespace std;
void readline(string &s) {
    getline(cin, s);
}

ll sumft(ll x1, ll x2) {return x2 * (x2 - 1)/2 - x1 * (x1 - 1)/2; }

void solve(string &s) {
    vector<pair<ll, ll> > v;
    for(ll i = 0; i < s.size(); i++) {
        if(i%2) v.push_back({-1, s[i] - '0'});
        else v.push_back({i/2, s[i] - '0'});
    }
    ll ans = 0;
    ll x = 0;
    for(ll i = 0; i < v.size(); i++) {
        if(v[i].first >= 0) {
            ans += v[i].first * sumft(x, x + v[i].second);
            x += v[i].second;
        } else {
            for(int j = v.size() - 1; j >= i; j--) {
                if(j == i) x += v[j].second;
                else if(v[j].first < 0 || v[j].second > v[i].second) continue;
                else {
                    v[i].second -= v[j].second;
                    ans += v[j].first * sumft(x, x + v[j].second);
                    x = x + v[j].second;
                    v[j].first = -1;
                    if(v[i].second) i--;
                    break;
                }
            }
        }
    }
    cout << ans;
}
int main() {
    string s;
    readline(s);
    solve(s);
}