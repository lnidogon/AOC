#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#define ll long long
void parse_input(std::vector<std::pair<ll, ll> > &v) {
    std::string s;
    std::getline(std::cin, s);
    s.push_back(',');
    int id = 0;
    while(id < s.size() - 1) {
        int nid1 = s.find('-', id);
        int nid2 = s.find(',', id);
        ll x = std::stoll(s.substr(id, nid1 - id));
        ll y = std::stoll(s.substr(nid1 + 1, nid2 - nid1 - 1));
        v.push_back({x, y});
        id = nid2 + 1;
    }
}

ll log10(ll x) {
    int ans = 0;
    for(;x;x/=10) ans++;
    return ans;
}

ll pow10(ll x) {
    ll ans = 1;
    for(int i = 0; i < x; i++) ans *= 10;
    return ans;
}

void solve_part1(std::vector<std::pair<ll, ll> > &v) {
    long long ans = 0;
    for(ll i = 1; i < 1000000; i++) {
        ll p10 = pow10(log10(i));
        ll dn = i * p10 + i;
        for(auto t : v) if(dn >= t.first and dn <= t.second) {
            ans += dn;
            break;
        }
    }
    std::cout << ans << '\n';
}
void solve_part2(std::vector<std::pair<ll, ll> > &v) {
    long long ans = 0;
    std::set<ll> s;
    for(ll i = 1; i < 1000000; i++) {
        ll p10 = pow10(log10(i));
        for(ll dn = i * p10 + i; log10(dn) < 12; dn = (dn * p10) + i) {
            if(s.find(dn) != s.end()) continue;
            for(auto t : v) if(dn >= t.first and dn <= t.second) {
                ans += dn;
                s.insert(dn);
                break;
            }
        }
    }
    std::cout << ans << '\n';
}
int main() { 
    std::vector<std::pair<ll, ll> > v;
    parse_input(v);
    solve_part1(v);
    solve_part2(v);
}
