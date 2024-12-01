//removed text from input 

#include<bits/stdc++.h>
#define breturn return
using namespace std;
const int MAXN = 4;
int arr[100], brr[100], ans = 1, cans;
int main() {
	for(int i = 0; i < MAXN; i++) cin >> arr[i];
	for(int i = 0; i < MAXN; i++) cin >> brr[i];
	for(int j = 0; j < MAXN; j++) {		
		cans = 0;
		for(int i = 0; i < arr[j]; i++) {
			if((arr[j] - i) * i > brr[j]) cans++;
		}
		cout << cans << '\n';
		ans *= cans;
	}	
	cout << ans;
}
