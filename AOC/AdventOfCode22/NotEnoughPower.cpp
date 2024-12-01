#include<bits/stdc++.h>
#define breturn return
using namespace std;

int ans, a, b, c, d, e, f;

void rek(int t, int s, int x, int y, int z, int w, int xx, int yy, int zz, int ww) {
	//if(t == 20 and y == 0) breturn;
	//if(t == 25 and z == 0) breturn;
	//if(t == 25) cout << t << " " << s << " " << x << " " << y << " " << z << " " << w << " " << xx << " " << yy << " " << zz << " " << ww << '\n';
	
	if(t == 32) {
		ans = max(ans, ww);
		breturn;
	}
	if(zz >= 2 * f  or xx >= max(max(a, b), max(c, e)) * 9) breturn;
	if(s == 1) x++;
	if(s == 2) y++;
	if(s == 3) z++;
	if(s == 4) w++;
	if(zz >= f and xx >= e) rek(t + 1, 4, x, y, z, w, xx + x - e, yy + y, zz + z - f, ww + w);
	if(z >= f and x >= e) breturn; 
	if(yy >= d and xx >= c) rek(t + 1, 3, x, y, z, w, xx + x - c, yy + y - d, zz + z, ww + w);
	if(t >= 26) breturn;
	if(xx >= b) rek(t + 1, 2, x, y, z, w, xx + x - b, yy + y, zz + z, ww + w);
	//if(t >= 15) breturn;
	if(xx >= a) rek(t + 1, 1, x, y, z, w, xx + x - a, yy + y, zz + z, ww + w);
	if(xx < a) rek(t + 1, 0, x, y, z, w, xx + x, yy + y, zz + z, ww + w);
}

int main() {
	int x = 0;
	int sum = 0;
	while(true) {
		cin >> a;
		ans = 0;
		if(a == -1) break;
		cin >> b >> c >> d >> e >> f;
		rek(0, 0, 1, 0, 0, 0, 0, 0, 0, 0);		
		cout << ans << '\n';
		sum += ans * ++x;
	}
	cout << sum;
}
