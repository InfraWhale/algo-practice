#include<bits/stdc++.h> // 구현
using namespace std;   

string dopa = "abcde";

int main() {
	// 3개출력
	cout << dopa.substr(0, 3) << '\n'; 
	// 거꾸로 출력
	reverse(dopa.begin(), dopa.end());
	cout << dopa << '\n'; 
	// 엄준식 추가 출력
	dopa += "umzunsic";
	cout << dopa << '\n';
	
	return 0;
}
