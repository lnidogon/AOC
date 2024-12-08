#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(vector<string> &v) {
    string s;
    while(getline(cin, s)) {
        v.push_back(s);
    }
}
void solve(vector<string> &v) {
    vector<pair<int, int> > loc[300];
    set<pair<int, int> > st;
    int n = v.size();
    int m = v.back().size();
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(v[i][j] != '.') loc[v[i][j]].push_back({i, j});
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] != '.' && v[i][j] != '#') {
                st.insert({i, j});
                for(auto t:loc[v[i][j]]) {
                    int vx = i - t.first;
                    int vy = j - t.second;
                    if(vx == vy && vy == 0) continue;
                    int px1 = i + vx;
                    int py1 = j + vy;
                    int px2 = t.first - vx;
                    int py2 = t.second - vy;
                    while(px1 >= 0 && py1 >= 0 && px1 < n && py1 < m) {
                        st.insert({px1, py1});
                        px1 += vx;
                        py1 += vy;
                    }
                    while(px2 >= 0 && py2 >= 0 && px2 < n && py2 < m) {
                        st.insert({px2, py2});                  
                        px2 -= vx;
                        py2 -= vy;
                    }
                }  
            }
        }
    }
    cout << st.size();
}
int main() {
    vector<string> v;
    readline(v);
    solve(v);
}