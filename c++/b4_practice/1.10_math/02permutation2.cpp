#include<bits/stdc++.h> //���� ������ 

using namespace std;

int main(){
	cout << "���ĵǾ����� ���� �迭���\n";
	int a[] = {1, 3, 2};
	do{
		for(int i : a) cout << i << " ";
		cout << '\n';
	}while(next_permutation(a, a + 3));
	cout << "���ĵ� �迭���\n";
	int b[] = {1, 2, 3};
	do{
		for(int i : b) cout << i << " ";
		cout << '\n';
	}while(next_permutation(b, b + 3));
}
