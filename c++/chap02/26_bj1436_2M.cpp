#include<bits/stdc++.h> // 백준 1436 2M (못품)
using namespace std;

int n, m, l;

int main(){

	cin >> n;
	m = 2;
	do {
		m++;
		l += pow(9, m-3) * (m-2); // m이 특정 자릿수일 때 나올수 있는 경우의 수
	} while (l >= n);


	

	return 0;
}
