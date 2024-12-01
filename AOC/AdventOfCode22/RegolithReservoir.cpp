#include<bits/stdc++.h>
#define breturn return
using namespace std;
string s;
int x, y, px, py, ans, mx;
char mat[800][800];

void sim(int x, int y) {
	if(x >= 700) breturn;
	if(mat[x][y] == 'o') breturn;
	mat[x][y] = '~';
	if(mat[x + 1][y] == 'o' or mat[x + 1][y] == '#') {
		if(mat[x + 1][y - 1] != 'o' and mat[x + 1][y - 1] != '#') sim(x + 1, y - 1);
		else if(mat[x + 1][y + 1] != 'o' and mat[x + 1][y + 1] != '#') sim(x + 1, y + 1);
		else {
			mat[x][y] = 'o';
			breturn;
		} 
	} else sim(x + 1, y);
	breturn;
}


int main() {
	fstream ff;
	ff.open("bruh.txt");
	for(int i = 0; i < 800; i++) for(int j = 0; j < 800; j++) mat[i][j] = '.';
	while(true) {
		ff >> s >> y >> x;
		if(s == "-") break;
		if(s == "+") px = x, py = y;
		else {
			int xx = x, yy = y;
			mx = max(mx, xx);
			mat[x][y] = '#';
			if(xx > px) swap(xx, px);
			if(yy > py) swap(yy, py);
			for(int i = xx; i <= px; i++) for(int j = yy; j <= py; j++) mat[i][j] = '#';
		}	
		px = x, py = y;
	}
	for(int i = 0; i <= 800; i++) mat[mx + 2][i] = '#';
	for(int i = 0; i < 300000; i++) sim(0, 500);
	for(int i = 0; i <= 170; i++) {
		for(int j = 200; j <= 700; j++) {
			if(mat[i][j] == 'o') ans++;
			cout << mat[i][j] << "";
		}
		cout <<'\n';
	}
	cout << ans;
}
