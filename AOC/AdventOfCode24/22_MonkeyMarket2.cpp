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
    vector<ll> chn;
    ll xx = 0;
    map<ll, ll> m[v.size()];
    map<ll, ll> cumsum;
    for(auto t:v) {
        chn.clear();
        ll sn = t;
        ll prevail = t%10;
        for(ll i = 0; i < 2000; i++) {
            sn = (sn^(sn << 6))%MOD;
            sn = (sn^(sn >> 5))%MOD;
            sn = (sn^(sn << 11))%MOD;
            chn.push_back(sn%10 - prevail);
            if(i >= 3) {
                ll predval = chn[chn.size() - 4] * 1e6 + chn[chn.size() - 3] * 1e4 + chn[chn.size() - 2] * 1e2 + chn[chn.size() - 1];
                if(m[xx].find(predval) == m[xx].end()) m[xx][predval] = sn%10, cumsum[predval] += sn%10; 
            }
            prevail = sn%10;
        }
        xx++;
    }
    ll ans = 0;
    set<ll> allvals;
    for(int i = 0; i < v.size(); i++) for(auto t:m[i]) {
        allvals.insert(t.first);
    }
    for(auto serval:allvals) 
        ans = max(ans, cumsum[serval]);
    
    cout << ans;
}

int main() {
    vector<ll> v;
    readline(v);
    solve(v);
}