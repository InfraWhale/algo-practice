#include <bits/stdc++.h>
using namespace std;

int a = 1;
char s = 'a';
string str = "어벤져스";
double b = 1.223123;

int main(){
	printf("아이엠어 아이언맨 : %d\n",a); // int
	printf("아이엠어 아이언맨 : %c\n",s); // char
	printf("아이엠어 아이언맨 : %s\n",str.c_str()); // string
	// printf("아이엠어 아이언맨 : %s\n",str); // printf는 c의 함수므로, 쓰기 전에 c_str()을 써서 c 스타일 문자열(char *)로 변환	
	printf("아이엠어 아이언맨 : %lf\n",b); // double
	return 0;
}

