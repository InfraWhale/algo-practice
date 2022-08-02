#include<bits/stdc++.h> // pair & tuple - tie 안쓸경우 
using namespace std;

pair<int, int> pi;
tuple<int, int, int> ti;
int a, b, c;

int main(){
	pi = {1, 2};
	a = pi.first;
	b = pi.second;
	cout << a << " : " << b << "\n";
	ti = make_tuple(1, 2, 3);
	a = get<0>(ti);
	b = get<1>(ti);
	c = get<2>(ti);
	cout << a << " : " << b << " : "<< c << "\n";
	return 0;
}

