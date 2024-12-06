#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(bool (&mat)[101][101], vector<vector<int>> &v) {
    string s;
    while(getline(cin, s)) {
        if(s == "") break;
        string str1 = s.substr(0, 2);
        string str2 = s.substr(3, 2);
        mat[stoi(str1)][stoi(str2)] = 1;
    }
    while(getline(cin, s)) {
        int id = 0;
        s += ',';
        vector<int> temp;
        while(id < s.size()) {
            int nexid = s.find(",", id);
            string str1 = s.substr(id, nexid - id);
            temp.push_back(stoi(str1));
            id = nexid + 1;
        }
        v.push_back(temp);
    }
}
void solve(bool (&mat)[101][101], vector<vector<int>> &v) {
    int ans = 0;
    for(auto t:v) {
        bool good = true;
        int n = t.size();
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < i; j++) 
                good *= !mat[t[i]][t[j]];                    
        if(good) ans += t[n/2];
    }
    cout << ans;
}
int main() {
    bool mat[101][101];
    memset(mat, 0, sizeof(mat));
    vector<vector<int>> v;
    readline(mat, v);
    solve(mat, v);
}