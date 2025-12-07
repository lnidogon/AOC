#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<set>

void parse_input(std::vector<std::string> &v) {
    std::string s;
    while(std::getline(std::cin, s)) v.push_back(s);
}

void solve_part1(std::vector<std::string> &v) {
    int x = 0, y = v.back().size() / 2, ans = 0;
    std::set<int> s = {y};
    while(x < v.size()) {
        std::set<int> s_temp = s;
        for(auto t : s_temp) {
            if(v[x][t] == '^') {
                s.erase(s.find(t));
                if(t + 1 < v.back().size()) s.insert(t + 1);
                if(t - 1 >= 0) s.insert(t - 1);
                ans++;
            }
        }
        x++;
    }
    std::cout << ans << '\n';
}


void solve_part2(std::vector<std::string> &v) {
    long long ans = 0;
    std::vector<long long> dp(v.back().size(), 0);
    dp[v.back().size() / 2] = 1;
    for(int x = 0; x < v.size(); x++) for(int y = 0; y < dp.size(); y++) if(v[x][y] == '^') {
        if(y + 1 < dp.size()) dp[y + 1] += dp[y];
        if(y - 1 >= 0) dp[y - 1] += dp[y];
        dp[y] = 0;
    }
    for(int i = 0; i < dp.size(); i++) ans += dp[i];
    std::cout << ans << '\n';
}


int main() {
    std::vector<std::string> v;
    parse_input(v);
    solve_part1(v);
    solve_part2(v);
}
