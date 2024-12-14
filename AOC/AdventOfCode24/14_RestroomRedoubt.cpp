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
    //n = 7, m = 11;
    const ll T = 100;
    map<pair<ll, ll>, ll> mp;
    for(auto t:v) {
        ll x = t.first.first;
        ll y = t.first.second;
        ll vx = t.second.first;
        ll vy = t.second.second;
        ll fx = (x + vx * T + n * T)%n;
        ll fy = (y + vy * T + m * T)%m;
        mp[{fx, fy}]++;
    }
    long long ans;
    ll q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    for(auto t:mp) {
        if(t.first.first > n/2) {
            if(t.first.second < m/2) q1 += t.second;
            else if(t.first.second > m/2) q4 += t.second;
        } else if(t.first.first < n/2) {
            if(t.first.second < m/2) q2 += t.second;
            else if(t.first.second > m/2) q3 += t.second;
        }
    }
    ans = q1 * q2 * q3  * q4;
    cout << ans;
}

int main() {
    vector<pair<pair<ll, ll>, pair<ll, ll> > > v;
    readline(v);
    solve(v); 
}