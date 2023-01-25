#include<bits/stdc++.h> // scanf
using namespace std;
char a[10][10];
int main(){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			scanf(" %c", &a[i][j]); // c로 받으면 특수문자, 엔터를 문자취급 -> 띄워쓰기 꼭 넣어주기 
		}
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

// 어지간하면 cin, cout 사용 
