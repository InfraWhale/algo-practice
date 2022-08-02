#include <bits/stdc++.h> // 문자를 숫자로 
using namespace std;
int main(){
	char a = 'a';
	cout << (int)a - 97 << "\n";
	cout << a - 97 << "\n"; 

	cout << 97 - a << "\n";  
	cout << 97 - 'a' << "\n";
	
	cout << (int)a - 'a' << "\n"; // 연산에 쓰이면 'a'는 문자가 아니라 아스키코드 97로 쓰임 
	
	char b = 'b';
	cout << (int)b - 97 << "\n";
	return 0;
}
