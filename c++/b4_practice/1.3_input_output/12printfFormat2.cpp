#include <bits/stdc++.h> // printf 형식 지정 2

using namespace std;
int a = 1;
char s = 'a';
string str = "어벤져스";
double b = 1.223123;

int main(){
	printf("아이엠어 아이언맨 : %d\n",a);
	printf("아이엠어 아이언맨 : %c\n",s);
	printf("아이엠어 아이언맨 : %s\n",str.c_str()); //string은 그냥 출력 안되고 문자열에 대한 포인터 타입으로 바꿔줘야 함(char *), cout 쓰는게 편함 
	printf("아이엠어 아이언맨 : %lf\n",b);
	return 0;
}

