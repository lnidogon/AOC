#include<bits/stdc++.h>
#define breturn return
using namespace std;
void readline(string &ss) {
    string s;
    while(getline(cin, s)) {
        ss += s;
    }
}


//neki mali dka se ovdje radi 0 - pocetno stanje, (0,m) -> 1, (1,u) -> 2, (2,l) -> 3, (3,()->4, 4,digit -> 5,
//5,digit -> 6, 6,digit -> 7, 5,, -> 8 6,, -> 8, 7,,-> 8, 8,digit -> 9, 9,digit -> 10, 10,digit->11, 9,)->F, 10,)->F, 11,)->F
bool isDigit(char c) {
    return(c >= '0' and c <= '9');
}

void solve(string &s) {
    int state = 1;
    long long sum = 0;
    int id = 0;
    while(id < s.size()) {
        int nextid3 = s.find("do()", id);
        if(nextid3 == -1) nextid3 = INT_MAX;
        int nextid4 = s.find("don't()", id);
        if(nextid4 == -1) nextid4 = INT_MAX;
        int nextid1 = s.find("mul(", id);
        if(nextid3 == min(nextid3, min(nextid4, nextid1))) {
            state = 1;
            id = nextid3 + 4;
            continue;
        } else if(nextid4 == min(nextid3, min(nextid4, nextid1))) {
            state = 0;
            id = nextid4 + 7;
            continue;
        }
        if(nextid1 < 0) break;
        int nextid2 = s.find(")", nextid1);
        int commaid = s.find(",", nextid1);
        string str1 = s.substr(nextid1 + 4, commaid - nextid1 - 4);
        string str2 = s.substr(commaid + 1, nextid2 - commaid - 1);
        bool good = (str1.size() <= 3 && str1.size() >= 1) && (str2.size() <= 3 && str2.size() >= 1);
        for(auto t:str1) good *= isDigit(t);
        for(auto t:str2) good *= isDigit(t);
        if(!good) {
            id++;
            continue;
        }
        sum += stoi(str1) * stoi(str2) * state;
        id = nextid2 + 1;        
    }
    cout << sum << '\n';
}
int main() {
    string s;
    readline(s);
    solve(s);
}