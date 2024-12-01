#include<bits/stdc++.h>
#define breturn return
using namespace std;
const int n = 50;
char mat[6][n][n], cmat[6][n][n];
string s;
int x = 0, y = 0, z = 0, w = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char sm[] = {'>', 'V', '<', '^'};

void mov(int *x, int *y, int *z, int *w) {
	int xx = *x;
	int yy = *y + dx[*w];
	int zz = *z + dy[*w];
	if(xx == 0) {
		if(yy < 0) xx = 4, yy = n - 1;
		else if(yy == n) xx = 3, yy = 0;
		else if(zz < 0) xx = 0, zz = n - 1;
		else if(zz == n) xx = 0, zz = 0;
	} else if(xx == 1) {
		if(yy < 0) xx = 1, yy = n - 1;
		else if(yy == n) xx = 1, yy = 0;
		else if(zz < 0) xx = 3, zz = n - 1;
		else if(zz == n) xx = 2, zz = 0;
	} else if(xx == 2) {
		if(yy < 0) xx = 2, yy = n - 1;
		else if(yy == n) xx = 2, yy = 0;
		else if(zz < 0) xx = 1, zz = n - 1;
		else if(zz == n) xx = 3, zz = 0;	
	} else if(xx == 3) {
		if(yy < 0) xx = 0, yy = n - 1;
		else if(yy == n) xx = 4, yy = 0;
		else if(zz < 0) xx = 2, zz = n - 1;
		else if(zz == n) xx = 1, zz = 0;
	} else if(xx == 4) {
		if(yy < 0) xx = 3, yy = n - 1;
		else if(yy == n) xx = 0, yy = 0;
		else if(zz < 0) xx = 5, zz = n - 1;
		else if(zz == n) xx = 5, zz = 0;	
	} else if(xx == 5) {
		if(yy < 0) xx = 5, yy = n - 1;
		else if(yy == n) xx = 5, yy = 0;
		else if(zz < 0) xx = 4, zz = n - 1;
		else if(zz == n) xx = 4, zz = 0;	
	}
	if(mat[xx][yy][zz] != '#') mat[*x][*y][*z] = sm[*w], *x = xx, *y = yy, *z = zz;
	else mat[xx][yy][zz] = 'O';
}

void mov2(int *x, int *y, int *z, int *w) {
	int xx = *x;
	int yy = *y + dx[*w];
	int zz = *z + dy[*w];
	int ww = *w;
	if(xx == 0) {
		     if(yy <  0) xx = 5, ww = 0, yy = *z, zz = 0;
		else if(yy == n) xx = 2, ww = 1, yy = 0, zz = *z;
		else if(zz <  0) xx = 3, ww = 0, yy = n - 1 - *y, zz = 0;
		else if(zz == n) xx = 1, ww = 0, yy = *y, zz = 0;
	} else if(xx == 1) {
		     if(yy <  0) xx = 5, ww = 3, yy = n - 1, zz = *z;
		else if(yy == n) xx = 2, ww = 2, yy = *z, zz = n - 1;
		else if(zz <  0) xx = 0, ww = 2, yy = *y, zz = n - 1;
		else if(zz == n) xx = 4, ww = 2, yy = n - 1 - *y, zz = n - 1;
	} else if(xx == 2) {
			 if(yy <  0) xx = 0, ww = 3, yy = n - 1, zz = *z;
		else if(yy == n) xx = 4, ww = 1, yy = 0, zz = *z;
		else if(zz <  0) xx = 3, ww = 1, yy = 0, zz = *y;
		else if(zz == n) xx = 1, ww = 3, yy = n - 1, zz = *y;	
	} else if(xx == 3) {
			 if(yy <  0) xx = 2, ww = 0, yy = *z, zz = 0;
		else if(yy == n) xx = 5, ww = 1, yy = 0, zz = *z;
		else if(zz <  0) xx = 0, ww = 0, yy = n - 1 - *y, zz = 0;
		else if(zz == n) xx = 4, ww = 0, yy = *y, zz = 0;
	} else if(xx == 4) {
			 if(yy <  0) xx = 2, ww = 3, yy = n - 1, zz = *z;
		else if(yy == n) xx = 5, ww = 2, yy = *z, zz = n - 1;
		else if(zz <  0) xx = 3, ww = 2, yy = *y, zz = n - 1;
		else if(zz == n) xx = 1, ww = 2, yy = n - 1 - *y, zz = n - 1;
	} else if(xx == 5) {
			 if(yy <  0) xx = 3, ww = 3, yy = n - 1, zz = *z;
		else if(yy == n) xx = 1, ww = 1, yy = 0, zz = *z;
		else if(zz <  0) xx = 0, ww = 1, yy = 0, zz = *y;
		else if(zz == n) xx = 4, ww = 3, yy = n - 1, zz = *y;
	}
	if(yy >= n or zz >= n) cout << *x << " " << *y << " " << *z << " " << *w << '\n';
	if(mat[xx][yy][zz] != '#') mat[*x][*y][*z] = sm[*w], *x = xx, *y = yy, *z = zz, *w = ww;
}



int main() {
	fstream f;
	f.open("bruh.txt");
	/*
	for(int i = 0; i < n; i++) for(int j = 0; j < 1 * n; j++) cin >> mat[0][i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < 3 * n; j++) cin >> mat[1 + j/n][i][j%n];
	for(int i = 0; i < n; i++) for(int j = 0; j < 2 * n; j++) cin >> mat[4 + j/n][i][j%n];
	cin >> s;
	*/
	for(int i = 0; i < n; i++) for(int j = 0; j < 2 * n; j++) f >> mat[0 + j/n][i][j%n];
	for(int i = 0; i < n; i++) for(int j = 0; j < 1 * n; j++) f >> mat[2][i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < 2 * n; j++) f >> mat[3 + j/n][i][j%n];
	for(int i = 0; i < n; i++) for(int j = 0; j < 1 * n; j++) f >> mat[5][i][j];
	
	//for(int i = 0; i < 6; i++) for(int j = 0; j < n; j++) for(int k = 0; k < n; k++) mat[i][j][k] = '.';
	f >> s;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'L') {
			w = (w - 1 + 4)%4;
		} else if(s[i] == 'R'){
			w = (w + 1)%4;
		} else {
			int sum = (s[i] - '0');
			if(i + 1 < s.size() and s[i + 1] != 'L' and s[i + 1] != 'R') sum = sum * 10 + (s[++i] - '0');
			for(int i = 0; i < sum; i++) mov2(&x, &y, &z, &w);
		}
	}
	cout << x << " " << y << " " << z << " " << w << '\n';
		for(int i = 0; i < 6; i++) {
		cout << i << ": \n";
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				cout << mat[i][j][k];
			}
			cout << '\n';
		}
	}
}
