#include<iostream>
#include<string>
#include<vector>
#include<utility>

void parse_input(std::vector<int> &v) {
    std::string s;
    while(std::getline(std::cin, s)) v.push_back({(s[0] == 'R' ? 1 : -1) * std::stoi(s.substr(1, s.size() - 1))});
}

void solve_part1(std::vector<int> &v) {
    int s = 50;
    int ans = 0;
    for(auto t : v) {
        s = (s + t%100 + 100) % 100;
        ans += !s;
    }
    std::cout << ans << '\n';
}

void solve_part2(std::vector<int> &v) {
    int s = 50;
    int ans = 0;
    for(auto t : v) {
        ans+=std::abs(t/100); 
        int os = s;
        s = s + t%100;
        if(s < 0) {
            if(os > 0) ans ++;
            s = (s + 100);
        } else if(s >= 100) {
            ans++;
            s %= 100;
        } else if(s == 0) if(os) ans++;
    }
    std::cout << ans << '\n';
}


int main() {
    std::vector<int> v;
    parse_input(v);
    solve_part1(v);
    solve_part2(v);
}