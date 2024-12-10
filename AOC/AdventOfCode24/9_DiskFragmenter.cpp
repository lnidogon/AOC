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
        if(v.back().first < 0) {
            v.pop_back();
            i--;
            continue;
        }
        //cout << v[i].first << " " << v[i].second << " " << x << "\n";
        if(v[i].first >= 0) {
            //cout << v[i].first << " * " << sumft(x, x + v[i].second) << '\n';
            ans += v[i].first * sumft(x, x + v[i].second);
            x = x + v[i].second;
        } else {
            //cout << v.back().first << " <> " << v.back().second << '\n';
            if(v.back().second > v[i].second) {
                v[v.size() - 1].second -= v[i].second;
                //cout << v.back().first << " * " << sumft(x, x + v[i].second) << '\n';
                ans += v.back().first * sumft(x, x + v[i].second);
                x = x + v[i].second;
            } else {
                auto sl = v[v.size() - 1];
                v[i].second -= sl.second;
                //cout << sl.first << " * " << sumft(x, x + sl.second) << '\n';
                ans += sl.first * sumft(x, x + sl.second);
                v.pop_back();
                x = x + sl.second;
                i--;
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