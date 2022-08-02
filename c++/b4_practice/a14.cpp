#include<bits/stdc++.h> // cout로 출력 

using namespace std;
typedef long long ll; // typedef : 타입에 별칭을 부여. 저렇게 하면 일일히 long long 대신 ll로 줄여쓰면 됨 
double a = 1.23456789;

int main(){
	cout << a << "\n"; // 1.23457
	cout.precision(20);
	cout << a << "\n"; // 1.234568
	return 0;
}
