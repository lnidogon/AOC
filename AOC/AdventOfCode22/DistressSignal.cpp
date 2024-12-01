#include<bits/stdc++.h>
#define breturn return
using namespace std;
string s, z, sx[1000];
int ns[1000], nz[1000];
vector<int> v;
/*
0 - neodluceno
1 - dobarrrr
2 - noooo
*/
int rek(int x, int y) {
	//cout << x << " " << y << '\n';
	if(s[x] == ']' and z[y] == ']') {
		breturn 0;
	}
	if(s[x] == ',' and z[y] == ',') {
		breturn rek(x + 1, y + 1);	
	} else if(s[x] != ']' and z[y] == ']') {
		breturn 2;
	} else if(s[x] == ']' and z[y] != ']') {
		breturn 1;
	} else if(s[x] == '[' and z[y] == '[') {
		int r = rek(x + 1, y + 1);
		if(r) breturn r;
		breturn rek(ns[x] + 1, nz[y] + 1);
	} else if(s[x] != '[' and z[y] != '[') {
		if(s[x] < z[y]) breturn 1;
		else if(s[x] > z[y]) breturn 2;
		else breturn rek(x + 1, y + 1);
	} else if(s[x] != '[' and z[y] == '[') {
		if(z[y + 1] == ']') breturn 2;
		if(z[y + 1] == '[') {
			int r = rek(x, y + 1);
			if(r) breturn r;
			breturn rek(x + 1, nz[y] + 1);
		}
		if(z[y + 1] < s[x])  breturn 2;
		if(s[x] < z[y + 1]) breturn 1;
		 if(s[x] == z[y + 1]){
			if(z[y + 2] == ']') breturn rek(x + 1, y + 3);
			else breturn 1;
		}
	} else if(s[x] == '[' and z[y] != '[') {
		if(s[x + 1] == ']') breturn 1;
		if(s[x + 1] == '[') {
			int r = rek(x + 1, y);
			if(r) breturn r;
			breturn rek(ns[x] + 1, y + 1);
		}
		if(z[y] < s[x + 1])  breturn 2;
		if(s[x + 1] < z[y]) breturn 1;
		 if(s[x + 1] == z[y]){
			if(s[x + 2] == ']') breturn rek(x + 3, y + 1);
			else breturn 2;
		}
	} 
}

bool comp(string s1, string z1) {
	s = s1, z = z1;
	v.clear();
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '[') v.push_back(i);
			else if(s[i] == ']') ns[v.back()] = i, v.pop_back();
		}
		for(int i = 0; i < z.size(); i++) {
			if(z[i] == '[') v.push_back(i);
			else if(z[i] == ']') nz[v.back()] = i, v.pop_back();
		}
		int r = rek(0, 0);
		
	breturn (rek(0, 0) == 1);
}


int main() {
	int ans = 0;
	int x = 0;
	string s;
	while(true) {
		cin >> s;
		if(s == "+") break;
		string s1 = s;
		s.clear();
		for(int i = 0; i < s1.size(); i++) 
		{
			if(i < s1.size() - 1 and s1[i] == '1' and s1[i + 1] == '0') s.push_back(':'), i++;
			else s.push_back(s1[i]);
		} 
		sx[x++] = s;		
	}
	x+=2;
	sx[x - 2] = "[[2]]";
	sx[x - 1] = "[[6]]";
	for(int i = 0; i < x ; i++) cout << sx[i] << '\n';
	cout << "MEOW\n";
	sort(sx, sx + x, comp);
	for(int i = 0; i < x; i++) cout << i << ": " << sx[i] << '\n';
}
