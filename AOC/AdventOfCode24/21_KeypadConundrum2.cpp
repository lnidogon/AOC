#include<bits/stdc++.h>
#define breturn return
#define ll long long
#define f first
#define s second
using namespace std;

ll mat[][3] = {
    {-1, 3, 4},
    {0, 1, 2}
};

ll mat2[][3] = {
    {8, 9, 10},
    {5, 6, 7},
    {2, 3, 4},
    {-1, 0, 1}
};

pair<ll, ll> conv[] = {
    {1, 0},
    {1, 1},
    {1, 2},
    {0, 1},
    {0, 2}
};
pair<ll, ll> conv2[] = {
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

ll outval[] = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10};

ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};

void readline(vector<string> &v) {
    string s;
    while(getline(cin, s)) v.push_back(s);
}




void solve(vector<string> &v) {
    ll cost[][5] = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };
    ll ncost[5][5];
    for(ll it = 0; it < 25; it++) {
        for(ll i = 0; i < 5; i++) for(ll j = 0; j < 5; j++) {
            ll memc[5][5];
            set<pair<ll, pair<ll, ll>> > st;
            memset(memc, -1, sizeof(memc));
            memc[4][i] = 0;
            st.insert({0, {4, i}});
            while(st.size()) {
                auto it = *(st.begin());
                auto pp = it.s;
                ll x = conv[pp.s].f;
                ll y = conv[pp.s].s;
                st.erase(it);
                for(ll k = 0; k < 4; k++) {
                    ll xx = x + dx[k];
                    ll yy = y + dy[k];
                    if(xx < 0 || yy < 0 || xx > 1 || yy > 2) continue; 
                    ll nv = mat[xx][yy];
                    if(mat[xx][yy] == -1) continue;
                    if(memc[k][nv] > memc[pp.f][pp.s] + cost[pp.f][k] || memc[k][nv] == -1) {
                        auto it = st.find({memc[k][nv], {k, nv}});
                        if(it != st.end()) st.erase(it);
                        memc[k][nv] = memc[pp.f][pp.s] + cost[pp.f][k];
                        st.insert({memc[k][nv], {k, nv}});
                    }
                }
            }
            ncost[i][j] = 1e17;
            for(ll k = 0; k <= 4; k++) {
                if(memc[k][j] >= 0) ncost[i][j] = min(ncost[i][j], memc[k][j] + cost[k][4]);
            }
        }
        for(ll i = 0; i < 5; i++) 
            for(ll j = 0; j < 5; j++) 
            cost[i][j] = ncost[i][j];
    }
    // for(ll i = 0; i < 5; i++) {
    //     for(ll j = 0; j < 5; j++) {
    //         cout << cost[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    ll acost[11][11];
    for(ll i = 0; i < 11; i++) for(ll j = 0; j < 11; j++) {
        ll memc[5][11];
        set<pair<ll, pair<ll, ll>> > st;
        memset(memc, -1, sizeof(memc));
        memc[4][i] = 0;
        st.insert({0, {4, i}});
        while(st.size()) {
            auto it = *(st.begin());
            auto pp = it.s;
            ll x = conv2[pp.s].f;
            ll y = conv2[pp.s].s;
            st.erase(it);
            for(ll k = 0; k < 4; k++) {
                ll xx = x + dx[k];
                ll yy = y + dy[k];
                if(xx < 0 || yy < 0 || xx > 3 || yy > 2) continue; 
                ll nv = mat2[xx][yy];
                if(mat2[xx][yy] == -1) continue;
                if(memc[k][nv] > memc[pp.f][pp.s] + cost[pp.f][k] || memc[k][nv] == -1) {
                    auto it = st.find({memc[k][nv], {k, nv}});
                    if(it != st.end()) st.erase(it);
                    memc[k][nv] = memc[pp.f][pp.s] + cost[pp.f][k];
                    st.insert({memc[k][nv], {k, nv}});
                }
            }
        }
        acost[i][j] = 1e17;
        for(ll k = 0; k <= 4; k++) {
            if(memc[k][j] >= 0) acost[i][j] = min(acost[i][j], memc[k][j] + cost[k][4]);
        }
    }
    //for(int i = 0; i < 11; i++, cout << '\n') for(int j = 0; j < 11; j++) cout << acost[i][j] << " ";   
    ll ans = 0;
    for(auto t:v) {
        ll prevs = 1;
        ll ccost = 0;
        for(int i = 0; i < t.size(); i++) {
            ll vx = (t[i] - '0' > 9?1:outval[t[i] - '0']);
            ccost += acost[prevs][vx];
            prevs = vx;
        }
        ll numval = stoll(t.substr(0, 4));
        ans += ccost * numval;
    }
    cout << ans;
}

int main() {
    vector<string> v;
    readline(v);
    solve(v);

}