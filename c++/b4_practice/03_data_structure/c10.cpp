#include <bits/stdc++.h> // 배열의 복사 memcpy 
using namespace std;
int a[5];
int temp[5];

int main(){

	for(int i = 0; i < 5; i++)
		a[i] = i;
	
	for(int i : a) 
		cout << i << ' ';	
	
	cout << "\n";
		
	memcpy(temp, a, sizeof(a)); // temp 배열에 a 배열 복사 
	
	for(int i : temp) 
		cout << i << ' ';
	
	return 0;
}
