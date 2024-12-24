#include<bits/stdc++.h>
#define breturn return
#define f first 
#define s second
using namespace std;

void readline(vector<pair<string, int> > &v1, vector<pair<pair<int, string>, pair<string, string> > > &v2) {
    string st;
    while(getline(cin, st)) {
        if(st == "") break;
        v1.push_back({st.substr(0, 3), st[5] - '0'});
    }
    while(getline(cin, st)) {
        string ss = st.substr(4, 3);
        int opt = -1, del = 0;
        if(ss == "AND") opt = 0;
        else if(ss == "OR ") opt = del = 1;
        else if(ss == "XOR") opt = 2; 
        v2.push_back({{opt, st.substr(15 - del, 3)},{st.substr(0, 3), st.substr(8 - del, 3)}});
    }
}

void solve(vector<pair<string, int> > &v1, vector<pair<pair<int, string>, pair<string, string> > > &v2) {
    map<string, pair<int, pair<string, string> > > grap;
    map<string, set<string> > gras; 
    map<string, vector<string> > graz;
    map<string, int> val;
    for(auto t:v2) {
        grap[t.f.s] = {t.f.f, t.s};
        gras[t.f.s].insert(t.s.f);
        gras[t.f.s].insert(t.s.s);
        graz[t.s.f].push_back(t.f.s);
        graz[t.s.s].push_back(t.f.s);
    }
    queue<string> q;
    for(auto t:v1) {
        val[t.f] = t.s;
        q.push(t.f);
    }

    while(q.size()) {
        string nod = q.front();
        q.pop();
        for(auto t:graz[nod]) {
            gras[t].erase(nod);
            if(!gras[t].size()) q.push(t);
        }
        if(nod[0] == 'x' || nod[0] == 'y') continue;
        auto edg = grap[nod];
        if(edg.f == 0) val[nod] = val[edg.s.f] and val[edg.s.s];
        else if(edg.f == 1) val[nod] = val[edg.s.f] or val[edg.s.s];
        else if(edg.f == 2) val[nod] = val[edg.s.f] xor val[edg.s.s];
    }
    long long ans = 0;
    for(int i = 45; i >= 0; i--) {
        string ff = string("z") + (i < 10?"0":"") + to_string(i);
        if(val.find(ff) == val.end()) continue;
        ans = ans * 2;
        ans += val[ff];
    }
    cout << ans;
    
}



int main() {
    vector<pair<string, int> > v1;
    vector<pair<pair<int, string>, pair<string, string> > > v2;
    readline(v1, v2);
    solve(v1, v2);
}