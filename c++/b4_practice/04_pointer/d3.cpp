#include<bits/stdc++.h> // call by reference & value
using namespace std;

int idx = 2;

// call by reference
void go(int &idx){
	idx = 1;
}

// call by value
void go2(int idx){
	idx = 100;
}

int main(){
	go(idx);
	cout << idx << '\n'; // 1 : �ٲ����.
	
	go2(idx);
	cout << idx << '\n'; // 1 : �ٲ��� �ʾҴ�.
}
