#include<bits/stdc++.h>
#define breturn return
using namespace std;

void readline(vector<string> &dic, vector<string> &v) {
    string s;
    getline(cin, s);
    int id = 0;
    s += ',';
    while(id < s.size()) {
        int nexd = s.find(',', id);
        dic.push_back(s.substr(id, nexd - id));
        id = nexd + 2;
    } 
    getline(cin, s);
    while(getline(cin, s)) v.push_back(s);
}

void solve(vector<string> &dic, vector<string> &v) {
    int ans = 0;
    for(auto t:v) {
        bool poss[v.size() + 1];
        memset(poss, false, sizeof(poss));
        poss[0] = true;
        for(int i = 0; i < t.size(); i++) if(poss[i]){
            for(auto tt:dic) {
                int n = tt.size();
                if(t.substr(i, n) == tt)poss[i + n] = true;                 
            }
        }
        if(poss[t.size()]) ans++;
    }
    cout << ans;
}


int main() {
    vector<string> dic, v;
    readline(dic, v);
    solve(dic, v);
}