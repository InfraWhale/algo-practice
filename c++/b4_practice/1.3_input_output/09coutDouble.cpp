#include<bits/stdc++.h> // cout의 실수타입 출력
 
using namespace std;
typedef long long ll;
double a = 1.23456789;

int main(){
	cout << a << "\n"; // 1.23457
	cout.precision(7); // 자릿수 정해주기 
	cout << a << "\n"; // 1.234568
	return 0;
}

