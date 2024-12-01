#include<bits/stdc++.h>
#define breturn return
using namespace std;
int a, b, c, d, ans;
int main() {
	while(true) {
		scanf("%d-%d,%d-%d", &a, &b, &c, &d);
		if(a == -1) break;
		if(b >= c and b <= d or d >= a and d <= b) ans++;
	}
	cout << ans;
}
