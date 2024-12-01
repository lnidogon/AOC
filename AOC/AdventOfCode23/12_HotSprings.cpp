// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void readline(vector<string> &v1, vector<vector<int>> &v2) {
    fstream file;
    file.open("input.txt", ios::in);
    string s;
    for(int i = 0; getline(f, s); i++) {
        s += ',';
        vector<int> v3;
        int x = s.find(' ');
        v1.push_back(s.substr(0, x));
        int rsum = 0;
        for(int j = x+1; j < s.size(); j++) {
            if(s[j] >= '0' and s[j] <= '9') {
                rsum = 10 * rsum + s[j]-'0';
                
            } else {
                v3.push_back(rsum);
       
                rsum = 0;
            }
        }
        v2.push_back(v3);
    }
    file.close();
}
int dp[30][30];
bool been[30][30];
int rek(string &s, vector<int> &v, int x = 0, int y = 0) {
    //cout << x << " " << y << '\n';
    if(x >= s.size() and y == v.size()) return 1;
    else if(x >= s.size()) return 0;
    if(been[x][y]) return dp[x][y];
    been[x][y] = 1;
    dp[x][y] = 0;
    if(s[x] != '#') dp[x][y] += rek(s,v,x+1,y);
    if(y != v.size()) {
      bool poss = true;
        for(int i = 0; i < v[y]; i++) {
         
            if(i + x == s.size() or s[i+x] == '.') poss = false;
        }
        if(v[y] + x != s.size() and s[v[y]+x] == '#') poss = false;
        if(poss) dp[x][y] += rek(s,v,x+v[y]+1,y+1);
    }
    return dp[x][y];
}
void solve(vector<string> &v1, vector<vector<int>> &v2) {
    int ans = 0;
    for(int i = 0; i < v1.size(); i++){
        memset(been, 0, sizeof(been));
        ans += rek(v1[i], v2[i]);
        cout << dp[0][0] << " wow\n";
    }
    cout << ans << '\n';
}
int main() {
   vector<string> v1;
   vector<vector<int>> v2;
   readline(v1,v2);
   solve(v1,v2);
    return 0;
}
