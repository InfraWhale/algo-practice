#include<bits/stdc++.h> // 배열과 포인터 
using namespace std;

void go(int a[]){
	a[2] = 100;
}
int a[3] = {1, 2, 3};

int main(){
	go(a); // 배열 - 그냥 a를 넘겨도 값이 수정됨  
	for(int i : a) 
		cout << i << '\n';
}
