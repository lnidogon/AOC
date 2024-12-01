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
		for(int i = '2'; i < '2' + 13; i++) {
			int cnt = 0;
			for(int j = 0; j < val.size(); j++) {
				if(reval[j] == i) cnt++;
			}
			if(cnt) prf += cnt + '0';
		}
		sort(prf.begin(), prf.end());
		reval += prf;
		reverse(reval.begin(), reval.end());
	}
	bool operator<(const Card &other) {
		return (this->reval < other.reval);	
	}
};
vector<Card> v;
int main() {
	remap['2'] = '2';
	remap['3'] = '3';
	remap['4'] = '4';
	remap['5'] = '5';
	remap['6'] = '6';
	remap['7'] = '7';
	remap['8'] = '8';
	remap['9'] = '9';
	remap['T'] = '9' + 1;
	remap['J'] = '9' + 2;
	remap['Q'] = '9' + 3;
	remap['K'] = '9' + 4;
	remap['A'] = '9' + 5;
	while(true) {
		cin >> s;
		if(s == "break") break;
		cin >> x;
		Card *c = new Card(s, x);
		v.push_back(*c);
		
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	for(int i = 0; i < v.size(); i++) {
		cout << v[i].val<< " " << v[i].bid << "  " << v[i].reval << '\n';
		ans += (i + 1) * v[i].bid;	
	}
	cout << ans;
}
