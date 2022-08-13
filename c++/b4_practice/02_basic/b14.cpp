#include<bits/stdc++.h> // printf로 출력 
using namespace std;

typedef long long ll;
double a = 1.23456789;
int b = 2;

int main(){
	printf("%.6lf\n", a); // 소숫점 아래 6자리까지 
	printf("%04d\n", b); // 4자리로 출력하되 빈자리는 0으로 
	printf("%4d\n", b); // 4자리로 출력하되 빈자리는 공백으로 
	return 0;
}
