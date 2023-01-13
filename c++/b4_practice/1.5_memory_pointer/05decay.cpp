#include<bits/stdc++.h> // 배열이름과 포인터 (decay)

using namespace std;
int a[3] = {1, 2, 3};

int main(){
	int * b = &a[0];
	int * c = a; // 첫번째 요소의 주소가 바인딩됨(decay) 
	cout << b << "\n";
	cout << c << "\n";
	return 0;
}
