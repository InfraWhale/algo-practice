#include<bits/stdc++.h> // ��ø for���� �̿��� ���� 2
using namespace std;

int n = 5;
int k = 3;
int a[5] = {11, 22, 33, 44, 55};
int main() {
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			for(int k = 0; k < j; k++){
				cout << a[i] << " " << a[j] << " " << a[k] << '\n';
			}
		}
	}
	return 0;
}
