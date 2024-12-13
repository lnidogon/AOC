#include<bits/stdc++.h>
#define breturn return
#define ll long long
using namespace std;

pair<ll, ll> extr(string &s) {
    ll ix = s.find('X');
    ix +=2;
    ll iy = s.find('Y');
    iy+=2;
    ll X = stoi(s.substr(ix, iy - ix - 4));
    ll Y = stoi(s.substr(iy, s.size() - iy));
    return {X, Y};
}


void readline(vector<vector<ll>> &v) {
    string s;
    while(getline(cin, s)) {
        vector<ll> temp;
        pair<ll, ll> t = extr(s);
        temp.push_back(t.first);
        temp.push_back(t.second);
        getline(cin, s);
        t = extr(s);
        temp.push_back(t.first);
        temp.push_back(t.second);
        getline(cin, s);
        t = extr(s);
        temp.push_back(t.first);
        temp.push_back(t.second);
        getline(cin, s);
        v.push_back(temp);
    }
}

void solve(vector<vector<ll>> &v) {
    ll sum = 0;
    for(auto t:v) {
        ll csum = LLONG_MAX;
        ll X1 = t[0], Y1 = t[1], X2 = t[2], Y2 = t[3], SX = t[4], SY = t[5];
        for(ll k = 0; k <= 100; k++) 
            if((SX - X1 * k)%X2 == 0 && (SY - Y1 * k)%Y2 == 0 && (SX - X1 * k)/X2 == (SY - Y1 * k)/Y2) 
                csum = min(csum, k * 3 + (SX - X1 * k)/X2);
        if(csum != LLONG_MAX)
            sum += csum;
    }
    cout << sum;
}

int main() {
    vector<vector<ll>> v;
    readline(v);
    solve(v);
}