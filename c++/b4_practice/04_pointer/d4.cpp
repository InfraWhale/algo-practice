#include<bits/stdc++.h> // �迭�� ������ 
using namespace std;

void go(int a[]){
	a[2] = 100;
}
int a[3] = {1, 2, 3};

int main(){
	go(a); // �迭 - �׳� a�� �Ѱܵ� ���� ������  
	for(int i : a) 
		cout << i << '\n';
}
