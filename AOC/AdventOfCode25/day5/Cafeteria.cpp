#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<algorithm>
#define ll long long

void parse_input(std::vector<std::pair<ll, ll> > &r, std::vector<ll> &q) {
    std::string s;
    while(true) {
        std::getline(std::cin, s);
        if(s == "") break;
        int id = s.find('-');
        r.push_back({std::stoll(s.substr(0, id)), std::stoll(s.substr(id + 1, (int)s.size() - id - 1))});
    }
    while(std::getline(std::cin, s)) {q.push_back(std::stoll(s));}
}

void solve_part1(const std::vector<std::pair<ll, ll> > &r, const std::vector<ll> &q) {
    std::set<std::pair<ll, ll> > s, a;
    for(auto t : r) s.insert(t);
    std::sort(q.begin(), q.end());
    int ans = 0;    
    for(auto t : q) {
        while(s.size() && s.begin()->first <= t) {
            a.insert({s.begin()->second, s.begin()->first});
            s.erase(s.begin());
        } 
        while(a.size() && a.begin()->first < t) a.erase(a.begin());
        ans += !!a.size();
    }
    std::cout << ans << '\n';
}

void solve_part2(const std::vector<std::pair<ll, ll> > &r) {
    std::set<std::pair<ll, ll> > s, a;
    ll ans = 0;
    for(auto t : r) s.insert(t);
    ll x = 0;
    while(true) {
        while(s.size() && s.begin()->first <= x) {
            a.insert({s.begin()->second, s.begin()->first});
            s.erase(s.begin());
        }
        while(a.size() && a.begin()->first < x) a.erase(a.begin());
        if(!a.size() && !s.size()) break;
        if(a.size()) {
            ans += a.begin()->first - x + 1;
            x = a.begin()->first + 1;
        } else x = s.begin()->first;
    }
    std::cout << ans << '\n';
}

int main() {
    std::vector<std::pair<ll, ll> > r;
    std::vector<ll> q;
    parse_input(r, q);
    solve_part1(r, q);
    solve_part2(r);
}