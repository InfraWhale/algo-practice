#include<bits/stdc++.h> // pair, tuple

using namespace std;

pair<int, int> pi;
tuple<int, int, int> tl;
int a, b, c;

int main(){
	pi = {1, 2}; //  {a, b} 또는 make_pair(a, b}
	tl = make_tuple(1, 2, 3);
	tie(a, b) = pi; // 변수 a, b에 페어안에 있는 두 수를 순서대로 넣어줌 
	cout << a << " : " << b << "\n";
	tie(a, b, c) = tl;
	cout << a << " : " << b << " : "<< c << "\n";
	return 0;
}

