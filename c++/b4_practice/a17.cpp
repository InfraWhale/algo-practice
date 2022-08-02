#include <bits/stdc++.h> // double에서 int로 형변환 
using namespace std;
int main(){
	double ret = 2.12345;
	int n = 2;
	int a = (int)round(ret / double(n)); // round() : 반올림 함수 
	cout << a << "\n";
	return 0;
}
