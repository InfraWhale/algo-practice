#include <bits/stdc++.h> // double 을 int형으로 

using namespace std;

int main(){
	double ret = 2.12345;
	int n = 2;
	int a = (int)round(ret / double(n)); // 연산은 꼭 같은 타입끼리 -> int는 int끼리 
	cout << a << "\n";
	
	double p = 3.33333;
	int b = (int) p * 100;
	int c = (int) 100 * p;
	cout << b << "\n";
	cout << c << "\n"; // 되긴 되는데? 
	
	return 0;
}

