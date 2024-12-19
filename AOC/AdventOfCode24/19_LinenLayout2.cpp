#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;

void readline(vector<string> &dic, vector<string> &v) {
    string s;
    getline(cin, s);
    ll id = 0;
    s += ',';
    while(id < s.size()) {
        ll nexd = s.find(',', id);
        dic.push_back(s.substr(id, nexd - id));
        id = nexd + 2;
    } 
    getline(cin, s);
    while(getline(cin, s)) v.push_back(s);
}

void solve(vector<string> &dic, vector<string> &v) {
    ll ans = 0;
    for(auto t:v) {
        ll poss[v.size() + 1];
        memset(poss, 0, sizeof(poss));
        poss[0] = 1;
        for(ll i = 0; i < t.size(); i++) if(poss[i]){
            for(auto tt:dic) {
                ll n = tt.size();
                if(t.substr(i, n) == tt)poss[i + n] += poss[i];                 
            }
        }
        ans += poss[t.size()];
    }
    cout << ans;
}


int main() {
    vector<string> dic, v;
    readline(dic, v);
    solve(dic, v);
}