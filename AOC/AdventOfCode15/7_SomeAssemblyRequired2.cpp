#include<bits/stdc++.h>
#define breturn return
#define usr unsigned short
/*
#define f first
#define s second
*/
using namespace std;

void readline(vector<pair<pair<int, string>, pair<string, string> > >  &v) {
	fstream f;
	f.open("7_input.txt");
	string s;
	while(getline(f, s)) {
		s.push_back(' ');
		int id = s.find(" ");
		string s1, s2, s3, s4, s5;
		s1 = s.substr(0, id);
		int idnx = s.find(" ", ++id);
		s2 = s.substr(id, idnx - id);
		id = idnx;
		idnx = s.find(" ", ++id);
		s3 = s.substr(id, idnx - id);
		id = idnx;
		idnx = s.find(" ", ++id);
		s4 = s.substr(id, idnx - id);
		id = idnx;
		if(s1 != "NOT") {
			idnx = s.find(" ", ++id);
			s5 = s.substr(id, idnx - id);
		}
		if(s1 == "NOT") v.push_back({{0, ""},{s2, s4}});
		else if(s2 == "AND") v.push_back({{1, s1},{s3, s5}});
		else if(s2 == "OR") v.push_back({{2, s1},{s3, s5}});
		else if(s2 == "RSHIFT") v.push_back({{3, s1},{s3, s5}});
		else if(s2 == "LSHIFT") v.push_back({{4, s1},{s3, s5}});		
	}
}

usr rek(string w, map<string, pair<pair<int, string>, string > >  &dep, map<string, usr> &value, map<string, bool> &bio) {
	if(bio[w]) return value[w];
	bio[w] = 1;
	if(dep.find(w) == dep.end()) {
		return value[w];
	}
	value[w] = 0;
	auto t = dep[w];
	if(t.first.first == 0) {
		string x = t.second;
		rek(x, dep, value, bio);
		value[w] = ~value[x];
	//	cout << "Putting the complement of " << x <<"("  << m[x] << ") into "  <<y << "(";
	//	cout << m[y] << ")\n";
	} else if(t.first.first == 1) {
		string x = t.first.second;
		string y = t.second;
		rek(y, dep, value, bio);
		if(x != "1") {
			rek(x, dep, value, bio);
			value[w] = value[x] & value[y];
		} else {
			value[w] = value[y] & 1;
		}
	//	cout << "Putting the and of " << x << "(" << m[x] << ") and " << y << "(" << m[y] << ") into " << z << "(";
	//	cout << m[z] << ")\n";
	}  else if(t.first.first == 2) {
		string x = t.first.second;
		string y = t.second;
		rek(x, dep, value, bio);		
		rek(y, dep, value, bio);		
		value[w] = value[x] | value[y];
	//	cout << "Putting the or of " << x << "(" << m[x] << ") and " <<y << "(" << m[y] << ") into " << z << "(";
	//	cout << m[z] << ")\n";
	}  else if(t.first.first == 3) {
		string x = t.first.second;
		usr y = stoi(t.second);
		rek(x, dep, value, bio);		
		value[w] = (value[x] >> y);
	//	cout << "Putting the rshift of " << x << "(" << m[x] << ") and " << y << " into " << z << "(" << m[z] << ")\n";
	}   else if(t.first.first == 4) {
		string x = t.first.second;
		usr y = stoi(t.second);
		rek(x, dep, value, bio);		
		value[w] = (value[x] << y);		
	//	cout << "Putting the lshift of " << x << "(" << m[x] << ") and " << y << " into " << z << "(" << m[z] << ")\n";
	} else cout << "ERRRORROROROROROR\n\n\n";

	return value[w];
}

void solve   (vector<pair<pair<int, string>, pair<string, string> > >  &v) {	
	map<string, unsigned short> m;
	map<string, pair<pair<int, string>, string > >  dep;
	map<string, usr> value;
	map<string, bool> bio;
	value["c"] = 0;
	value["b"] = 956;
	for(auto t:v) {
		int x = t.first.first;
		string y = t.first.second;
		string z = t.second.first;
		string w = t.second.second;
		dep[w] = {{x, y}, z};
	}
	for(auto t:dep) rek(t.first, dep, value, bio);
	cout << value["lx"] << '\n';
}
int main() {
	vector<pair<pair<int, string>, pair<string, string> > > v;
	readline(v);
	solve(v);	
}
