#include<bits/stdc++.h>
#define breturn return
using namespace std;
int hx[10], hy[10], d;
char c;
bool been[1000][1000];
int main() {
	int ans = 0;
	for(int i = 0; i < 10; i++) hx[i] = hy[i] = 690;
	while(true) {
		cin >> c >> d;
		if(c == '+') break;
		for(int j = 0; j < d; j++) {
			if(c == 'R') hy[0] += 1;
			else if(c == 'L') hy[0] -= 1;
			else if(c == 'U') hx[0] -= 1;
			else hx[0] += 1;
			for(int i = 1; i < 10; i++) {
				bool chx = 0;				
				bool chy = 0;
				if(hx[i] + 1 < hx[i - 1]) hx[i] = hx[i - 1] - 1, chx = 1;
				if(hx[i] - 1 > hx[i - 1]) hx[i] = hx[i - 1] + 1, chx = 1;
				if(hy[i] + 1 < hy[i - 1]) {
					hy[i] = hy[i - 1] - 1, chy = 1;
					if(!chx) hx[i] = hx[i - 1];
				}
				if(hy[i] - 1 > hy[i - 1]) {
					hy[i] = hy[i - 1] + 1, chy = 1;
					if(!chx) hx[i] = hx[i - 1];
				}
				if(!chy and chx) hy[i] = hy[i - 1];
			}
			ans += !(been[hx[9]][hy[9]]++);
		}	
	}
	cout << ans;
}
