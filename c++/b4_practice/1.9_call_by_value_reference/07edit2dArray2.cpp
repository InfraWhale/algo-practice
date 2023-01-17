#include<bits/stdc++.h> // 2차원배열 수정 - array

using namespace std;

int a[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
void go(int a[][3]){ //a[3][]이나 a[][]는 안됨 
	a[2][2] = 100;
}
void go2(int a[3][3]){
	a[2][2] = 1000;
}

int main(){
	go(a); cout << a[2][2] << '\n';
	go2(a); cout << a[2][2] << '\n';
}
