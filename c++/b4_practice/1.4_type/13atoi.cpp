#include <bits/stdc++.h> // atoi

using namespace std;

int main(){
	string s = "500";
	string s2 = "amumu";
	cout << atoi(s.c_str()) << '\n'; // 문자열이 숫자면면 값 그대로 반환 
	cout << atoi(s2.c_str()) << '\n'; // 문자열이 문자면 0 반환 
	return 0;
}

