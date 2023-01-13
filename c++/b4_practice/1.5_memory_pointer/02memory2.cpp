#include<bits/stdc++.h> // 메모리 2
using namespace std;
int i;

int main(){
	cout << &i << '\n';
	i = 0;
	cout << &i << '\n'; // 변수에 값 할당해도 주소는 변하지 않음 
	return 0;
}

