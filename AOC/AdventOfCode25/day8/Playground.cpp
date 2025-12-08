#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<string>
#include<utility>


long long dist3d(std::pair<int, std::pair<int, int> > &p1, std::pair<int, std::pair<int, int> > &p2) {
    long long d1 = p1.first - p2.first, d2 = p1.second.first - p2.second.first, d3 = p1.second.second - p2.second.second;
    return d1 * d1 + d2 * d2 + d3 * d3;
}


int gp(int x, std::vector<int> &par) {
    if(par[x] == x) return x;
    return par[x] = gp(par[x], par);
}

bool con(int x, int y, std::vector<int> &par, std::vector<int> &siz, std::multiset<int> &ms) {
    int xx = gp(x, par), yy = gp(y, par);
    if(xx == yy) return false;
    ms.erase(ms.find(siz[yy]));
    ms.erase(ms.find(siz[xx]));
    par[yy] = xx;
    siz[xx] = siz[xx] + siz[yy];
    ms.insert(siz[xx]);
    return true;
}

void parse_input(std::vector<std::pair<int, std::pair<int, int> > > &v) {
    std::string s;
    while(std::getline(std::cin, s)) {
        int id = s.find(',');
        int id2 = s.find(',', id + 1);
        v.push_back({
            std::stoi(s.substr(0, id))
            ,{
                std::stoi(s.substr(id + 1, id2 - id - 1)),
                std::stoi(s.substr(id2 + 1, s.size() - id2 - 1))
            }}
        );
    }
}

void solve_part1(std::vector<std::pair<int, std::pair<int, int> > > &v) {
    std::multiset<int> ms;
    std::vector<int> par(v.size()), siz(v.size());
    long long ans = 1;
    int n_iter = 1000;
    if(v.size() < 1000) n_iter = 10;
    for(int i = 0; i < v.size(); i++) {
        ms.insert(1);
        par[i] = i;
        siz[i] = 1;
    }
    std::vector<std::pair<long long, std::pair<int, int> > > d;
    for(int i = 0; i < v.size(); i++) for(int j = i + 1; j < v.size(); j++) d.push_back({dist3d(v[i], v[j]),{i, j}});
    std::sort(d.begin(), d.end());
    for(int i = 0; i < n_iter; i++) con(d[i].second.first, d[i].second.second, par, siz, ms);
    auto it = ms.end();
    for(int i = 0; i < 3; i++) {
        it--;
        ans *=* it;
    }
    std::cout << ans << '\n';
}

void solve_part2(std::vector<std::pair<int, std::pair<int, int> > > &v) {
    std::multiset<int> ms;
    std::vector<int> par(v.size()), siz(v.size());
    long long ans = 1;
    int n_iter = 1000;
    if(v.size() < 1000) n_iter = 10;
    for(int i = 0; i < v.size(); i++) {
        ms.insert(1);
        par[i] = i;
        siz[i] = 1;
    }
    std::vector<std::pair<long long, std::pair<int, int> > > d;
    for(int i = 0; i < v.size(); i++) for(int j = i + 1; j < v.size(); j++) d.push_back({dist3d(v[i], v[j]),{i, j}});
    std::sort(d.begin(), d.end());
    for(int i = 0; i < d.size(); i++)  if(con(d[i].second.first, d[i].second.second, par, siz, ms)) ans = (long long) v[d[i].second.first].first * v[d[i].second.second].first;
    std::cout << ans << '\n';
}

int main() {
    std::vector<std::pair<int, std::pair<int, int> > > v;
    parse_input(v);
    solve_part1(v);
    solve_part2(v);
}