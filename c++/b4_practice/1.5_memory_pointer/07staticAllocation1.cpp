#include<bits/stdc++.h> // 정적할당 1 

using namespace std;
int a;
int b = 0;
const int c = 0;

int main(){
	static int d;
	static int e = 0;
	return 0;
}

// BSS segment  
// -> 전역변수, static, const로 선언된 변수 중
//		0으로 초기화되거나 초기화가 어떠한 값으로도 되어 있지 않은 변수들 
