#include<bits/stdc++.h>
#define breturn return
using namespace std;
int main() {
	int sum = 0;
	while(true) {
		char a, b;
		cin >> a >> b;
		if(a == '.') break;
		if(a == 'A') {
			if(b == 'X') sum+=0 + 3;
			else if(b == 'Y') sum += 3 + 1;
			else sum += 6 + 2;
		}
		if(a == 'B') {
			if(b == 'X') sum+=0 + 1;
			else if(b == 'Y') sum += 3 + 2;
			else sum += 6 + 3;
		}
		if(a == 'C') {
			if(b == 'X') sum+=0 + 2;
			else if(b == 'Y') sum += 3 + 3;
			else sum += 6 + 1;
		}
		
	}
	cout << sum;
}
