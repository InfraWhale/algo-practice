#include <bits/stdc++.h> // double �� int������ 

using namespace std;

int main(){
	double ret = 2.12345;
	int n = 2;
	int a = (int)round(ret / double(n)); // ������ �� ���� Ÿ�Գ��� -> int�� int���� 
	cout << a << "\n";
	
	double p = 3.33333;
	int b = (int) p * 100;
	int c = (int) 100 * p;
	cout << b << "\n";
	cout << c << "\n"; // �Ǳ� �Ǵµ�? 
	
	return 0;
}

