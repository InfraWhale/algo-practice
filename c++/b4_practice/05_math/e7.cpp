#include<bits/stdc++.h> // �ִ������� �ּҰ���� 
using namespace std;

int gcd(int a, int b){ // �ִ����� 
	if(a == 0) return b;
	return gcd(b % a, a);
}
int lcm(int a, int b){ // �ּҰ���� 
	return (a * b) / gcd(a, b);
}
int main(){
	int a = 10, b = 12;
	
	cout << "gcd : "<< gcd(a, b) << '\n';
	
	cout << "lcm : "<< lcm(a, b) << '\n';
	return 0;
}
