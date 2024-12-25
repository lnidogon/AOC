#include<bits/stdc++.h>
#define breturn return
using namespace std;

void readline(vector<vector<string> > &vk, vector<vector<string> > &vl) {
    string s;
    vector<string> temp;
    while(getline(cin, s)) {
        if(s == "") {
            if(temp[0][0] == '#') vk.push_back(temp);
            else vl.push_back(temp);
            temp = {};
        } else temp.push_back(s);
    }
    if(temp[0][0] == '#') vk.push_back(temp);
    else vl.push_back(temp);
}

void solve(vector<vector<string> > &vk, vector<vector<string> > &vl) {
    vector<vector<int> > ik, il;
    for(auto t:vk) {
        vector<int> temp;
        for(int i = 0; i < 5; i++) {
            int no = 0;
            for(int j = 0; j < 7; j++) {
                no+=(t[j][i] == '#');
            }
            temp.push_back(no);
        }
        ik.push_back(temp);
    }
    for(auto t:vl) {
        vector<int> temp;
        for(int i = 0; i < 5; i++) {
            int no = 0;
            for(int j = 0; j < 7; j++) {
                no+=(t[j][i] == '#');
            }
            temp.push_back(no);
        }
        il.push_back(temp);
    }
    int ans = 0;
    for(auto tk:ik) for(auto tl:il) {
        bool good = true;
        for(int i = 0; i < 5; i++) if(tk[i] + tl[i] > 7) good = false;
        ans += good;
    }
    cout << ans;
}




int main() {
    vector<vector<string> > vk, vl;
    readline(vk, vl);
    solve(vk, vl);
}