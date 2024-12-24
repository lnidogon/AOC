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

void debug(int i, map<pair<int, pair<string, string> >, string> &mp, string p) {
    string xi = string("x") + (i < 10?"0":"") + to_string(i);
    string yi = string("y") + (i < 10?"0":"") + to_string(i);
    string zi = string("z") + (i < 10?"0":"") + to_string(i);    
    string a = mp[{2, {xi, yi}}];
    string b = mp[{0, {xi, yi}}];
    string c = mp[{0, {p, a}}];
    string np = mp[{1, {b, c}}];
    cout << xi << " " << yi <<" " << zi << " " << a << " " << b << " " <<c << " " << np << '\n';
}

void solve(vector<pair<string, int> > &v1, vector<pair<pair<int, string>, pair<string, string> > > &v2) {
    map<pair<int, pair<string, string> >, string> mp;
    for(auto t:v2) {
        if(t.f.s == "shh") t.f.s = "z21";
        else if(t.f.s == "z21") t.f.s = "shh"; 
        else if(t.f.s == "vgs") t.f.s = "dtk";
        else if(t.f.s == "dtk") t.f.s = "vgs"; 
        else if(t.f.s == "dqr") t.f.s = "z33";
        else if(t.f.s == "z33") t.f.s = "dqr"; 
        else if(t.f.s == "pfw") t.f.s = "z39";
        else if(t.f.s == "z39") t.f.s = "pfw"; 
        mp[{t.f.f, t.s}] = t.f.s;
        mp[{t.f.f, {t.s.s, t.s.f}}] = t.f.s;
    }
    vector<string> ans = {"shh", "z21", "vgs", "dtk", "dqr", "z33", "pfw", "z39"};
    sort(ans.begin(), ans.end());
    for(auto t:ans) cout << t <<",";
    string pprev;
    string p = "mcg";
    for(int i = 1; i < 45; i++) {
        string xi = string("x") + (i < 10?"0":"") + to_string(i);
        string yi = string("y") + (i < 10?"0":"") + to_string(i);
        string zi = string("z") + (i < 10?"0":"") + to_string(i);
        
        string a = mp[{2, {xi, yi}}];
        string b = mp[{0, {xi, yi}}];
        string c = mp[{0, {p, a}}];
        
        if(a == "") {
            cout << "ERRORa: \n";
            cout << i << '\n';
            cout << a << ".";
        } else if (b == "") {
            cout << "ERRORb: \n";
            cout << i << '\n';
            cout << b << ".";
        } else if(c == "") {
            cout << "ERRORc: \n";
            cout << i << '\n';
            cout << c << ".";
            cout << p << " " << a << '\n';
            debug(i - 1, mp, pprev);
            return;
        }
        if(mp[{2, {p, a}}] != zi) {
            cout << "ERROR: \n";
            cout << i << '\n';
            cout << mp[{2, {p, a}}] << '\n';
        }
        pprev = p;
        p = mp[{1, {b, c}}];
    }    
}

// first iteration found the first swap -> shh / z21
// second iteration found the second swap -> dtk / vgs
// third iteration found the third swap -> dqr / z33
// fourth iteration found the fourth swap -> pfw / z39

int main() {
    vector<pair<string, int> > v1;
    vector<pair<pair<int, string>, pair<string, string> > > v2;
    readline(v1, v2);
    solve(v1, v2);
}