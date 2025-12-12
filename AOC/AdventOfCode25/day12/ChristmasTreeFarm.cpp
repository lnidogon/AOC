#include<iostream>
#include<vector>
#include<string>

void parse_input(std::vector<int> &h, std::vector<int> &w, std::vector<std::vector<int> > &v) {
    std::string s;
    for(int i = 0; i < 5 * 6; i++) std::getline(std::cin, s);
    while(std::getline(std::cin, s)) {
        std::vector<int> temp;
        h.push_back(std::stoi(s.substr(0, 2)));
        w.push_back(std::stoi(s.substr(3, 2)));
        for(int i = 0; i < 6; i++) temp.push_back(std::stoi(s.substr(7 + i * 3, 2)));
        v.push_back(temp);
    }
}

void solve(std::vector<int> &h, std::vector<int> &w, std::vector<std::vector<int> > &v) {
    int ans = 0;
    for(int i = 0; i < v.size(); i++) {
        int s = 0;
        for(auto t : v[i]) s += t;
        if(s * 9 <= h[i] * w[i]) ans++;
    }
    std::cout << ans << '\n';
}

int main() {
    std::vector<int> h; 
    std::vector<int> w; 
    std::vector<std::vector<int> > v;
    parse_input(h, w, v);
    solve(h, w, v);
}