#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>


void parse_input(std::map<std::string, std::vector<std::string> > &m) {
    std::string s;
    while(std::getline(std::cin, s)) {
        int id = s.find(':');
        std::string s1 = s.substr(0, id);
        s.push_back(' ');
        id += 2;
        while(id < s.size()) {
            int id2 = s.find(' ', id);
            std::string s2 = s.substr(id, id2 - id);
            m[s1].push_back(s2);
            id = id2 + 1;
         }
    }
}

int rek(std::string s, std::map<std::string, std::vector<std::string> > &m, std::map<std::string, int> &dp) {
    if(s == "you") return 1;
    if(dp.find(s) != dp.end()) return dp[s];
    int ret = 0;
    for(auto t : m) {
        bool in = false;
        for(auto tt : m[t.first]) in |= (tt == s);
        if(in) ret += rek(t.first, m, dp);
    }
    return dp[s] = ret;
}

void solve_part1(std::map<std::string, std::vector<std::string> > &m) {
    std::map<std::string, int> dp;
    std::cout << rek("out", m, dp) << '\n';  
}

long long rek_2(std::string s, int x, std::map<std::string, std::vector<std::string> > &m, std::map<std::pair<std::string, int>, long long>  &dp) {
    if(s == "svr" and x == 3) return 1;
    if(dp.find({s, x}) != dp.end()) return dp[{s, x}];
    long long ret = 0;
    for(auto t : m) {
        bool in = false;
        for(auto tt : m[t.first]) in |= (tt == s);
        if(!in) continue; 
        int y = x;
        if(t.first == "dac") y |= 1;
        if(t.first == "fft") y |= 2; 
        ret += rek_2(t.first, y, m, dp);
    }
    return dp[{s, x}] = ret;
}

void solve_part2(std::map<std::string, std::vector<std::string> > &m) {
    std::map<std::pair<std::string, int>, long long> dp;
    std::cout << rek_2("out", 0, m, dp) << '\n';  
}

int main() {
    std::map<std::string, std::vector<std::string> > m;
    parse_input(m);
    solve_part1(m);
    solve_part2(m);
}