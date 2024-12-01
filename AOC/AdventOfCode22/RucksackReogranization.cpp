#include<bits/stdc++.h>
#define breturn return
using namespace std;
string s, z1, z2;
int main() {
	int sum = 0;
	while(true) {
		cin >> s >> z1 >> z2;
		if(s == ".") break;
		set<int> st1, st2, st3;
		
		for(int i = 0; i < s.size(); i++) st1.insert(s[i]);
		for(int i = 0; i < z1.size(); i++) st2.insert(z1[i]);
		for(int i = 0; i < z2.size(); i++) st3.insert(z2[i]);
		for(int j = 'A'; j <= 'Z'; j++) if(st1.find(j) != st1.end() and st2.find(j) != st2.end() and st3.find(j) != st3.end()){
				sum += j - 'A' + 27;
			}
	
		for(int j = 'a'; j <= 'z'; j++) if(st1.find(j) != st1.end() and st2.find(j) != st2.end() and st3.find(j) != st3.end()){
			sum += j- 'a' + 1;
			}
		
	}
	cout << sum;
}
