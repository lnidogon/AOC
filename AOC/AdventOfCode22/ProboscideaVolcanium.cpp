#include<bits/stdc++.h>
#define breturn return
using namespace std;
int arr[1000], dp[55][1<<15], pdp[55][1<<15], gbm, gc, kni[1000], id[1000];
vector<int> grap[1000], nd;
int num(char c1, char c2) {breturn (c1 - 'A') * 26 + (c2 - 'A');}
void rek(int x, int t, int bm) {
	int y = id[x]; 
	dp[y][bm] = -1e9;
	if(~kni[x] and (bm >> kni[x])%2) {
		int ret = pdp[y][bm - (1 << kni[x])] + (t - 1) * arr[x];
		if(ret > dp[y][bm]) dp[y][bm] = ret;
	}
	 for(auto it:grap[x]) {
	 	int ret = pdp[id[it]][bm];
	 	if(ret > dp[y][bm]) dp[y][bm] = ret;
	}
}
int main() {
	//ios::sync_with_stdio(false), cin.tie(0);
	memset(kni, -1, sizeof(kni));
	memset(dp, -1, sizeof(dp));
	memset(pdp, 0, sizeof(pdp));
	memset(id, -1, sizeof(id));
	while(true) {
		int x = 0, f = -1;
		char c1, c2, c3;
		scanf("\nValve %c%c has flow rate=%d; tunnels lead to valves", &c1, &c2, &f);
		if(f == -1) break;
		x = num(c1, c2);
		nd.push_back(x);
		arr[x] = f;	
		id[x] = gc++;
		if(f) kni[x] = gbm++; 
		while(true) {
			scanf(" %c%c%c", &c1, &c2, &c3);
			int xx = num(c1, c2);
			grap[x].push_back(xx); 
			if(c3 == '+') break;		
		}
		cout << x << ": \n";
		for(auto t:grap[x]) cout << t << "_";
		cout << '\n';
	}
	cout << gbm << " gbm\n";
	for(int i = 1; i <= 26; i++) {
		for(int j = 0; j < (1 << gbm); j++) for(auto it:nd) rek(it, i, j);				
		for(int j = 0; j < (1 << gbm); j++) for(auto it:nd) pdp[id[it]][j] = dp[id[it]][j];				
		cout << dp[id[0]][(1<<gbm)-1]<<'\n';
	}
	cout << dp[id[0]][(1 << gbm) - 1] << '\n';
	cout << id[0] << '\n';
	int ans = 0;	
	for(int i = 0; i < pow(3, gbm); i++) {
		int r1 = 0, r2 = 0;
		for(int j = gbm - 1; j >= 0; j--) {
			r1 *= 2;
			r2 *= 2;
			r1 += ((i/(int)(pow(3, j)))%3 == 0);
			r2 += ((i/(int)(pow(3, j)))%3 == 1);
		}
		ans = max(ans, dp[id[0]][r1] + dp[id[0]][r2]);
	}
	cout << ans << '\n';
	
}
