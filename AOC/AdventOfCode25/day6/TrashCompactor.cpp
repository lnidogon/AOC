#include<iostream>
#include<vector>
#include<string>

void parse_input(std::vector<std::vector<long long> > &v, std::vector<std::pair<bool, bool> > &o) {
    std::string s;
    std::vector<int> mi;
    while(std::getline(std::cin, s)) {
        if(s[0] != '+' and s[0] != '*') {
            std::vector<long long> temp;
            v.push_back(temp);
            bool num_active = false;
            long long sum = 0;
            for(int i = 0; i < (int)s.size(); i++) {
                if(s[i] == ' ') {
                    if(num_active) v.back().push_back(sum); 
                    num_active = false;
                    sum = 0;
                } else {
                    int x = v.back().size();
                    if(!num_active) {
                        if(mi.size() <= x) mi.push_back(i);
                        else mi[x] = std::max(mi[x], i);
                    }
                    num_active = true;
                    sum = (sum * 10 + (s[i] - '0'));
                }
            }
            if(num_active) v.back().push_back(sum);
        } else for(int i = 0; i < (int)s.size(); i++) if(s[i] != ' ') o.push_back({s[i] == '+', i == mi[(int)o.size()]});
        
    }
}

void solve_part1(const std::vector<std::vector<long long> > &v, const std::vector<std::pair<bool, bool> > &o) {
    long long ans = 0;
    for(int i = 0; i < o.size(); i++) {
        long long cans = (o[i].first ? 0 : 1);
        for(int j = 0; j < (int)v.size(); j++) {
            if(o[i].first) cans += v[j][i];
            else cans *= v[j][i];
        }
        ans += cans;
    }
    std::cout << ans << '\n';
}


void solve_part2(const std::vector<std::vector<long long> > &v, const std::vector<std::pair<bool, bool> > &o) {
    long long ans = 0;
    for(int i = 0; i < o.size(); i++) {
        long long cans = (o[i].first ? 0 : 1);
        std::vector<long long> ops, v_i;
        for(int j = 0; j < (int)v.size(); j++) v_i.push_back(v[j][i]);
        if(o[i].second) for(int j = 0; j < (int)v_i.size(); j++) while(v_i[j] < 1000) v_i[j] *= 10;
        for(long long k = 1000; k; k/=10) {
            int op = 0;
            for(int j = 0; j < (int)v.size(); j++) {
                long long d = (v_i[j] / k) % 10;
                if(!d && op) break;
                op = (op * 10 + d);
            }
            if(op) ops.push_back(op);
        } 
        for(auto op : ops) {
            if(o[i].first) cans += op;
            else cans *= op;
        }
        ans += cans;
    }
    std::cout << ans << '\n';
}

int main() {
    std::vector<std::vector<long long> > v;
    std::vector<std::pair<bool, bool> > o;
    parse_input(v, o);
    solve_part1(v, o);
    solve_part2(v, o);
}