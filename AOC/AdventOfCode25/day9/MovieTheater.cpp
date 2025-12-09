#include<iostream>
#include<string>
#include<vector>
#include<utility>

void parse_input(std::vector<std::pair<int, int> > &v) {
    std::string s;
    while(std::getline(std::cin, s)) {
        int id = s.find(',');
        v.push_back({std::stoi(s.substr(0, id)), std::stoi(s.substr(id + 1, s.size() - id - 1))});
    }
}

void solve_part1(std::vector<std::pair<int, int> > &v) {
    long long ans = 0;
    for(int i = 0; i < v.size(); i++) for(int j = i + 1; j < v.size(); j++) ans = std::max(ans, (std::abs(v[i].first - v[j].first) + 1LL) * (std::abs(v[i].second - v[j].second) + 1LL));
    std::cout << ans << '\n';
}

void solve_part2(std::vector<std::pair<int, int> > &v) {
    int n = v.size();
    long long ans = 0;
    std::vector<std::pair<int, std::pair<int, int> > > h_e, v_e;
    for(int i = 0; i < n - 1; i++) {
        int m1 = std::min(v[i].first, v[i + 1].first), m2 = std::max(v[i].first, v[i + 1].first), m3 = std::min(v[i].second, v[i + 1].second), m4 = std::max(v[i].second, v[i + 1].second);
        if(v[i].first == v[i + 1].first) h_e.push_back({v[i].first, {m3, m4}});
        else v_e.push_back({v[i].second, {m1, m2}});
    }
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
        auto p = v[i], q = v[j];
        std::pair<int, int> p1 = {std::min(p.first, q.first), std::min(p.second, q.second)}, p2 = {std::max(p.first, q.first), std::max(p.second, q.second)};
        bool good = true;
        for(auto t : h_e) { 
            if(
                (t.first < p2.first && t.first > p1.first)
                 && (
                    (t.second.first > p1.second && t.second.first < p2.second) 
                    || 
                    (t.second.second > p1.second && t.second.second < p2.second)
                    ||
                    (t.second.first <= p1.second && t.second.second >= p2.second)
                )
            ) good = false; 
        }
        for(auto t : v_e) { 
            if(
                (t.first < p2.second && t.first > p1.second) 
                && 
                (
                    (t.second.first > p1.first && t.second.first < p2.first) 
                    || 
                    (t.second.second > p1.first && t.second.second < p2.first)
                    ||
                    (t.second.first <= p1.first && t.second.second >= p2.first)
                )
            ) good = false; 
        }
        if((p2.first - p1.first + 1LL) * (p2.second - p1.second + 1LL) == 4647960552) std::cout << p.first << " " << p.second << " " << q.first << " " <<  q.second << '\n';
        if(good) ans = std::max(ans, (p2.first - p1.first + 1LL) * (p2.second - p1.second + 1LL));
    }
    std::cout << ans << '\n';
}

int main() {
    std::vector<std::pair<int, int> > v;
    parse_input(v);
    solve_part1(v);
    solve_part2(v);
}

// 2322483616 -> too high
// 2222483616 -> too high
// 172439520 -> too low
// 404439061 -> ???