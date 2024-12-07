#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;

void readline(vector<pair<ll, vector<ll> > > &v) {
    string s;
    while(getline(cin, s)) {
        int id = s.find(":");
        ll n1 = stoll(s.substr(0, id));
        id += 2;
        vector<ll> temp;
        s += " ";
        while(id < s.size()) {
            int nexid = s.find(" ", id);
            ll n2 = stoll(s.substr(id, nexid - id));
            temp.push_back(n2);
            id = nexid + 1;
        }
        v.push_back({n1, temp});
    }
}

void solve(vector<pair<ll, vector<ll> > > &v) {
    ll ans = 0;
    ll pot[20];
    for(int i = pot[0] = 1; i < 20; i++) pot[i] = pot[i - 1] * 3;
    for(auto t:v) {
        for(int i = 0; i < pot[t.second.size() - 1]; i++) {
            ll sum = t.second[0];
            for(int j = 0; j < t.second.size() - 1; j++) {
                int opt = i/pot[j]%3;
                if(opt == 0) sum *= t.second[j + 1];
                else if(opt == 1) sum += t.second[j + 1];
                else {
                    int nom = (int)log10(t.second[j + 1]) + 1;
                    for(int i = 0; i < nom; i++) {
                        sum *= 10;
                        if(sum > t.first) break;
                    }
                    sum += t.second[j + 1];
                }   
                if(sum > t.first) break;             
            }
            if(sum == t.first)  {
                ans += sum;
                break;
            }
        }
    }
    cout << ans;
}

int main() {
    vector<pair<ll, vector<ll> > > v;
    readline(v);
    solve(v);
}