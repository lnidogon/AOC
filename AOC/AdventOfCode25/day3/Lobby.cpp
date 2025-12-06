#include<iostream>
#include<string>
#include<vector>

void parse_input(std::vector<std::string> &v) {
    std::string s;
    while(std::getline(std::cin, s)) v.push_back(s);
}
void solve_part1(const std::vector<std::string> &v) {
    int ans = 0;
    for(auto s : v) {
        int mp = 0, mv = 0;
        for(int i = 0; i < (int)s.size() - 1; i++) if(s[i] - '0' > mv) mv = s[i] - '0', mp = i;
        int mv2 = 0;
        for(int i = mp + 1; i < (int)s.size(); i++) if(s[i] - '0' > mv2) mv2 = s[i] - '0'; 
        ans += 10 * mv + mv2;
    }
    std::cout << ans << '\n';
}
void solve_part2(const std::vector<std::string> &v) {
    long long ans = 0;
    for(auto s : v) {
        long long cans = 0;
        int mp =0;
        for(int i = 0; i < 12; i++) {
            int mv = 0;
            for(int j = mp; j < s.size() + i - 11; j++) if(s[j] - '0' > mv) mv = s[j] - '0', mp = j;
            cans *= 10;
            cans += mv;
            mp++;
        }
        ans += cans;
    }
    std::cout << ans << '\n';
}
int main() { 
    std::vector<std::string> v;
    parse_input(v);
    solve_part1(v);
    solve_part2(v);
}