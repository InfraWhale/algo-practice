#include<bits/stdc++.h> // 배열이름과 포인터 (decay) 2

using namespace std;
int a[3] = {1, 2, 3};

int main(){
	int * b = &a[0];
	int * c = a;
	int * d = (a + 1);
	cout << b << "\n";
	cout << c << "\n";
	cout << d << '\n';
	cout << &a[1] << '\n';
	return 0;
}

