#include <bits/stdc++.h> // �迭�� ���� memcpy 
using namespace std;
int a[5];
int temp[5];

int main(){

	for(int i = 0; i < 5; i++)
		a[i] = i;
	
	for(int i : a) 
		cout << i << ' ';	
	
	cout << "\n";
		
	memcpy(temp, a, sizeof(a)); // temp �迭�� a �迭 ���� 
	
	for(int i : temp) 
		cout << i << ' ';
	
	return 0;
}
