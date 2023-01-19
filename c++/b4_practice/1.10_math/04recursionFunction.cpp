#include <bits/stdc++.h> // 재귀함수
 
using namespace std;

int fact(int n){
	if(n == 1 || n == 0) return 1; // 기저사례  
	return n * fact(n - 1);
}

int fact1(int n){
	int ret = 1;
	for(int i = 1; i <= n; i++){ // 반복문 가능하면 반복문으로 -> 코스트 적게 듬 
		ret *= i;
	}
	return ret;
}

int fibo(int n){
	cout << "fibo : " << n << '\n';
	if(n == 0 || n == 1) return n;
	return fibo(n - 1) + fibo(n - 2);
}

int n = 4;

int main() {
	cout << fibo(n) << '\n';
	return 0;
}
