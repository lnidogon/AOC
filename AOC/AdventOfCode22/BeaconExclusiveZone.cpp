#include<bits/stdc++.h>
#define breturn return
#define f first
#define s second
using namespace std;
int arr[20000000], x1, x2, y1, y2, yans = 4000000;
vector<pair<pair<int, int>, pair<int, int> > > v;


int fun(int x) {
	vector<pair<int, int> > cv;
	for(auto t:v) {
		int d = abs(t.f.f - t.s.f) + abs(t.f.s - t.s.s);
		int r = abs(x - t.f.s);
		d = max(d - r, -1);
		if(d == -1) continue;
		cv.push_back({t.f.f - d, t.f.f + d});
	}
	//for(auto t:cv) cout << t.f << ":/ " << t.s << '\n';
	for(int i = 0; i < cv.size(); i++) {
		bool le = false, re = false;
		for(int j = 0; j < cv.size();++j)if(j != i) {
			if(cv[j].f < cv[i].f and cv[j].s >= cv[i].f - 1) le = true;
			if(cv[j].s > cv[i].s and cv[j].f <= cv[i].s + 1) re = true;
		}
		if(!le and cv[i].f-1 >= 0) breturn cv[i].f-1;
		if(!re and cv[i].s+1 <= yans) breturn cv[i].s+1;
	}
	breturn -1;
}

int main() {
	while(true) {
		x1 = -69;
		scanf("Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d\n", &x1, &y1, &x2, &y2);
		cout << x1 << '\n';
		if(x1 == -69) break;
		/*
		if(y2 == yans) arr[x2] = -1e9;
		int d = abs(x1 - x2) + abs(y1 - y2);
		int r = abs(yans - y1);
		d = max(d - r, -1);
		for(int i = 0; i <= d; i++) arr[x1 + i]++, arr[x1 - i]++;
		
		cout << x1 - d << " " << x1 + d << '\n';
		*/
		v.push_back({{x1,y1},{x2,y2}});
	}
	int n = v.size(); 
	for(int i = 0; i <= yans; i++) {
		int ret = fun(i);
		//cout << i << " " << ret << '\n';
		//if(~ret) cout << i << ": " << ret << "\n ret";
		if(~ret) breturn cout << 1LL * ret * 4000000 + i, 0;		
	}	
}
