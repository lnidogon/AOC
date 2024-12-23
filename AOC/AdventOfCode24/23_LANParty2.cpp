#include<bits/stdc++.h>
#define breturn return
using namespace std;

void readline(vector<pair<int, int> > &v) {
    string s;
    while(getline(cin, s)) {
        string s1 = s.substr(0, 2);
        string s2 = s.substr(3, 2);
        int n1 = (s1[0] - 'a') * 30 + (s1[1] - 'a');
        int n2 = (s2[0] - 'a') * 30 + (s2[1] - 'a');
        v.push_back({n1, n2});
    }
}
bool grap[1000][1000];
void solve(vector<pair<int, int> > &v) {
    for(auto t:v) 
        grap[t.first][t.second] = true, grap[t.second][t.first] = true;
    int msum = 0;
    for(int i = 0; i < 1000; i++) {
        int csum = 0;
        for(int j = 0; j < 1000; j++) {
            csum += grap[i][j];
        }
        msum = max(msum, csum);
    }
    vector<vector<int> > vec;
    for(int i = 0; i <= 806; i++) vec.push_back({i});
    for(int i = 0; i < msum - 1; i++) {
        vector<vector<int> > vect;
        for(auto t:vec) {
            for(int j = 0; j <= 806; j++) {
                vector<int> temp;
                bool good = true;
                for(auto tt:t) good &= grap[j][tt];
                if(good && t.back() < j) {
                    temp = t;
                    temp.push_back(j);
                    vect.push_back(temp);
                }
            }
        }
        vec = vect;
    }
    for(auto t:vec[0]) 
        cout << (char)(t/30 + 'a') << (char)(t%30 + 'a') << ",";
    
}

int main() {
    vector<pair<int, int> > v;
    readline(v);
    solve(v);

}