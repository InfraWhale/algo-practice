#include <bits/stdc++.h> // 숫자로 된 문자에 1 더해주기
 
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s = "923";
	s[0]++;
	cout << s << "\n"; // :23 - 아스키 코드상 9(081) 다음은 :(082) 
	return 0;
}
