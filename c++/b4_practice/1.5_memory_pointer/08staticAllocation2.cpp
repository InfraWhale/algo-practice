#include<bits/stdc++.h> // 정적할당 2

using namespace std;
int a = 1;
const int b = 2;

int main(){
	static int c = 3;
	return 0;
}

// Data segment
// -> 전역변수, static, const로 선언된 변수 중
//		0이 아닌 값으로 초기화된 변수 
