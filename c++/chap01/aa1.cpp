#include<bits/stdc++.h> // ����1 - ���� 1 
using namespace std;
	
int n, m, a, b ;

int main(){
	
	cin >> n >> m ;
	
	int arr[n];
	
	for(int i=0; i < n; i++) {
		cin >> arr[i];
	}
	
//	cout << "--------------------\n";
//	
//	for(int i=0; i < n; i++) {
//		cout << a[i];
//	}
	
	cout << "--------------------\n";
	
	int count = 0;
	
	do {
		cin >> a >> b ;
		
		int tmp = 0;
		
		for(int i=a-1; i < b; i++) {
	
			tmp += arr[i];
		}
		
		cout << "���� : "<< tmp ;
		cout << "\n";
		
		count++;
	} while ( count != m);

	
	return 0;
} 
