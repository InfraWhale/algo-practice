#include<bits/stdc++.h> // �迭�̸��� ������ (decay)

using namespace std;
int a[3] = {1, 2, 3};

int main(){
	int * b = &a[0];
	int * c = a; // ù��° ����� �ּҰ� ���ε���(decay) 
	cout << b << "\n";
	cout << c << "\n";
	return 0;
}
