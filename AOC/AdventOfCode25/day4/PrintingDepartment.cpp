#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<utility>
const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void parse_input(std::vector<std::string> &v) {
    std::string s;
    while(std::getline(std::cin, s)) v.push_back(s);
}
int no_adjacent(int i, int j, const std::vector<std::string> &v) {
    int ret = 0;
    for(int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if(x < 0 or x >= (int)v.size() or y < 0 or y > (int)v[i].size()) continue;
        if(v[x][y] == '@') ret++;
    }
    return ret;
}

void solve_part1(const std::vector<std::string> &v) {
    int ans = 0;
    for(int i = 0; i < (int)v.size(); i++)  {
        for(int j = 0; j < (int)v[i].size(); j++) {
            int sum = 0;
            if(v[i][j] != '@') continue;
            if(no_adjacent(i, j, v) < 4) ans++;
        }
    }
    std::cout << ans << '\n';
}
void solve_part2(const std::vector<std::string> &v) {
    std::vector<std::string> v_c = v;
    int n = v_c.size(), m = v_c.back().size();
    int ans = 0;
    std::vector<std::pair<int, int> > s;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(v_c[i][j] == '@' && no_adjacent(i, j, v_c) < 4) {
        s.push_back({i, j});
        v_c[i][j] = '.';
    }
    while(s.size()) {
        auto p = s.back();
        s.pop_back();
        ans++;

        for(int i = std::max(p.first - 1, 0); i <= std::min(p.first + 1, n - 1); i++) for(int j = std::max(p.second - 1, 0); j <= std::min(p.second + 1, m - 1); j++) {
            if(v_c[i][j] == '@' && no_adjacent(i, j, v_c) < 4) {
                s.push_back({i, j});
                v_c[i][j] = '.';
            }
        }
    }
    std::cout << ans << '\n';
}
int main() {
    std::vector<std::string> v;
    parse_input(v);
    solve_part1(v);
    solve_part2(v);
}