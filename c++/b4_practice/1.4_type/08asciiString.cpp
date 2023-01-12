#include <bits/stdc++.h> // 아스키코드와 문자열 

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "123"; // s[0]은 "1" -> 아스키코드에선 049 
	s[0]++; // 아스키코드 049에 1을 더해 050 -> 문자로는 "2" 
	cout << s << "\n"; // 223
	return 0;
}

// 065 -> "A"
// 097 -> "a"

