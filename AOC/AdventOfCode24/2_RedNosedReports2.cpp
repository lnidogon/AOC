#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<vector<int>> &v) {
    string s;
    while(getline(cin, s)) {
        vector<int> temp;
        int id = 0, nextid = -1;
        s += ' ';        
        while(id < s.size()) {
            nextid = s.find(' ', id);
            string numstr = s.substr(id, nextid - id);
            temp.push_back(stoi(numstr));
            id = nextid + 1;
        }
        v.push_back(temp);
    }
}
void solve(vector<vector<int>> &v) {
    int ans = 0;
    for(auto t:v) {
        for(int i = 0; i < t.size(); i++) {
            int lst = -1;
            bool good = true;
            bool dir = (i > 1?t[1] < t[0]:(i == 1?t[2] < t[0]:t[2] < t[1]));
            for(int j = 0; j < t.size(); j++) {
                if(j == i) continue;
                auto tt = t[j];
                if(lst == -1 || (dir && tt <= lst - 1 && tt >= lst - 3) || (!dir && tt >= lst + 1 && tt <= lst + 3)) 
                    lst = tt;
                else {
                    good = false;
                    break;
                }
            }
            if(good) {
                ans++;
                break;
            }
        }
    }
    cout << ans;
}
int main() {
    vector<vector<int>> v;
    readline(v);
    solve(v);

}