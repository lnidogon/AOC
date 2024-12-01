//added break string at the end
#include<bits/stdc++.h>
#define breturn return
using namespace std;
string s;
int x;
map<char, char> remap;
map<string, int> hand_val;
struct Card {
	string val;
	string prf;
	string reval;
	int bid;
	Card(string val, int bid) : val(val), bid(bid) {
		reval = prf = "";
		for(int i = val.size() - 1; i >= 0; i--) reval += remap[val[i]];
		int ccnt = 5;
		for(int i = '2'; i < '2' + 12; i++) {
			int cnt = 0;
			for(int j = 0; j < val.size(); j++) {
				if(reval[j] == i) cnt++, ccnt--;
			}
			if(cnt) prf += cnt + '0';
		}
		if(prf == "") prf = "0";
		sort(prf.begin(), prf.end());
		prf[prf.size()-1] += ccnt;
		reval += prf;
		reverse(reval.begin(), reval.end());
		cout << val << "  " << prf << " " << reval << '\n';
	}
	bool operator<(const Card &other) {
		return (this->reval < other.reval);	
	}
};
vector<Card> v;
int main() {
	remap['J'] = '1';
	remap['2'] = '2';
	remap['3'] = '3';
	remap['4'] = '4';
	remap['5'] = '5';
	remap['6'] = '6';
	remap['7'] = '7';
	remap['8'] = '8';
	remap['9'] = '9';
	remap['T'] = '9' + 1;
	remap['Q'] = '9' + 2;
	remap['K'] = '9' + 3;
	remap['A'] = '9' + 4;
	while(true) {
		cin >> s;
		if(s == "break") break;
		cin >> x;
		Card *c = new Card(s, x);
		v.push_back(*c);
		
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	for(int i = 0; i < v.size(); i++) 
		ans += (i + 1) * v[i].bid;		
	cout << ans;
}
