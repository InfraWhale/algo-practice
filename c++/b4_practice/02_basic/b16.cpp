#include <bits/stdc++.h> // double���� int�� ����ȯ 
using namespace std;
int main(){
	double ret = 2.12345;
	int n = 2;
	int a = (int)round(ret / double(n)); // round() : �ݿø� �Լ� 
	cout << a << "\n";
	return 0;
}
