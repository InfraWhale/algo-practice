#include <bits/stdc++.h> //scanf활용 실수타입을 정수타입으로 

using namespace std;
int a, b;
double c;

int main(){
	scanf("%d.%d", &a, &b);
	printf("\n%d %d\n", a, b);
	
	scanf("%lf", &c);
	printf("%lf\n", c);
	return 0;
}
