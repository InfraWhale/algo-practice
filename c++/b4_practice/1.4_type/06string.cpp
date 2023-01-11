#include <bits/stdc++.h> // type : string 1

using namespace std;

int main(){
	string a = "나는야";
	cout << a[0] << "\n"; // 배열 하나당 1바이트만 할당되므로 3바이트를 못담음 
	cout << a[1] << "\n";
	cout << a[2] << "\n";
	cout << a[0] << a[1] << a[2] << '\n'; // 합쳐서 3바이트므로 '나' 한 글자 담음 
	cout << a << "\n";  
	string b = "abc";
	cout << b[0] << "\n"; // 영어는 문제없음 
	cout << b << "\n";
	return 0;
}

// 배열처럼 출력한 경우 
