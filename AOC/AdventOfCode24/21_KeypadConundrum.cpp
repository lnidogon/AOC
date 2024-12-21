#include<bits/stdc++.h>
#define breturn return
#define f first
#define s second
using namespace std;

int debugarr[] = {0,1,-1,0,-1,-1,2,2,3,-1,1,-1,-1,0,3,-1,2,-1,0,1,0,-1,2,2,3,-1,1,-1,3,-1,0,1,-1,2,3,-1,0,1,0,-1,2,3,-1,2,-1,-1,1,-1,3,-1,0,1,0,-1,2,-1,2,3,-1,-1,-1,1,-1,0,3,-1,2,-1, 0,1,0,-1,2,2,3,-1,-1,-1,1,-1,3,-1,0,1,-1,0,-1,-1,2,2,3,-1,1,-1,-1,0,3,-1,2,-1,0,1,0,-1,2,-1,2,3,-1,-1,-1,1,-1,0,3,-1,2,-1,0,1,-1,2,3,-1,0,-1,2,-1};

int mem[5][5][5][11];
//left up right down

int mat[][3] = {
    {-1, 3, 4},
    {0, 1, 2}
};

int mat2[][3] = {
    {8, 9, 10},
    {5, 6, 7},
    {2, 3, 4},
    {-1, 0, 1}
};

pair<int, int> conv[] = {
    {1, 0},
    {1, 1},
    {1, 2},
    {0, 1},
    {0, 2}
};
pair<int, int> conv2[] = {
    {3, 1},
    {3, 2},
    {2, 0},
    {2, 1},
    {2, 2},
    {1, 0},
    {1, 1},
    {1, 2},
    {0, 0},
    {0, 1},
    {0, 2}
};

int outval[] = {0, 1, 2, 3, -1};
int outval2[] = {0, -1, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void readline(vector<string> &v) {
    string s;
    while(getline(cin, s)) v.push_back(s);
}


bool procinp3(int inp, int &x, int &rx1, int &rx2, int &rx3, string &s) {
    pair<int, int> pos = conv2[rx3];
    int xx = pos.f;
    int yy = pos.s;
    if(inp >= 0) {
        xx += dx[inp];
        yy += dy[inp];
        if(xx < 0 || xx > 3 || yy < 0 || yy > 2 || mat2[xx][yy] == -1) return false;
        rx3 = mat2[xx][yy];
        return true;
    } else {
        int val = outval2[rx3];
        if(val == -1 && s[x] == 'A' || s[x] - '0' == val) {
            x++;
            return true;
        }  
        return false;
    }
}


bool procinp2(int inp, int &x, int &rx1, int &rx2, int &rx3, string &s) {
    pair<int, int> pos = conv[rx2];
    int xx = pos.f;
    int yy = pos.s;
    if(inp >= 0) {
        xx += dx[inp];
        yy += dy[inp];
        if(xx < 0 || xx > 1 || yy < 0 || yy > 2 || mat[xx][yy] == -1) return false;
        rx2 = mat[xx][yy];
        return true;
    } else return procinp3(outval[rx2], x, rx1, rx2, rx3, s);  
}



bool procinp(int inp, int &x, int &rx1, int &rx2, int &rx3, string &s) {
    pair<int, int> pos = conv[rx1];
    int xx = pos.f;
    int yy = pos.s;
    if(inp >= 0) {
        xx += dx[inp];
        yy += dy[inp];
        if(xx < 0 || xx > 1 || yy < 0 || yy > 2 || mat[xx][yy] == -1) return false;
        rx1 = mat[xx][yy];
        return true;
    } else return procinp2(outval[rx1], x, rx1, rx2, rx3, s);  
}


void solve(vector<string> &v) {
    int ans = 0;
    for(auto t:v) {
        memset(mem, -1, sizeof(mem));
        queue<pair<pair<int, int>, pair<int, int> > > q;
        q.push({{0, 4}, {4, 1}}); 
        mem[0][4][4][1] = 0;
        while(q.size()) {
            auto it = q.front();
            int x = it.f.f;
            int rx1 = it.f.s;
            int rx2 = it.s.f;
            int rx3 = it.s.s;
            //cout << x<< " " <<rx1 <<" " << rx2 << " " <<rx3 << '\n';
            q.pop();
            for(int i = -1; i < 4; i++) {
               // i = debugarr[debugx++]; //debug
                //cout << i << ": \n"; // debug
                int xm = x;
                int rx1m = rx1;
                int rx2m = rx2;
                int rx3m = rx3;
                if(procinp(i, xm, rx1m, rx2m, rx3m, t)) {
                    if(mem[xm][rx1m][rx2m][rx3m] > mem[x][rx1][rx2][rx3] + 1 || mem[xm][rx1m][rx2m][rx3m] == -1) {
                        mem[xm][rx1m][rx2m][rx3m] = mem[x][rx1][rx2][rx3] + 1;
                        if(xm == 4) {
                            //cout << mem[xm][rx1m][rx2m][rx3m] <<" * " << stoi(t.substr(0, 3)) << '\n';
                            ans += mem[xm][rx1m][rx2m][rx3m] * stoi(t.substr(0, 3));
                            while(q.size()) q.pop();
                        } else q.push({{xm, rx1m}, {rx2m, rx3m}});
                    }
                }

              //  break; //debug

            }
        }
        //cout << ans << "ans \n";
    }
    cout << ans;
}

int main() {
    vector<string> v;
    readline(v);
    solve(v);

}