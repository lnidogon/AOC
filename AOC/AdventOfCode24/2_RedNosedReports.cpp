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
        int lst = -1;
        bool dir = (t[1] < t[0]);
        for(auto tt:t) {
            if(lst == -1 || (dir && tt <= lst - 1 && tt >= lst - 3) || (!dir && tt >= lst + 1 && tt <= lst + 3)) 
                lst = tt;
            else {
                ans--;
                break;
            }
        }
        ans++;
    }
    cout << ans;
}
int main() {
    vector<vector<int>> v;
    readline(v);
    solve(v);

}