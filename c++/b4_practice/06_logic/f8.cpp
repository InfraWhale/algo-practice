#include <cstdio> // 함수 인자로 전달해서 변수 수정하기 

void b(int a){
	a = 2;
}
void b2(int & a){
	a = 2;
}
void b3(int * a){
	*a = 3;
}
int main() {
	int a = 1;
	
	b(a);
	printf("%d\n", a); // 1
	
	b2(a);
	printf("%d\n", a); // 2
	
	b3(&a);
	printf("%d\n", a); // 3
	
	return 0;
}
