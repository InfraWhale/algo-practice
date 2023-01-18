#include<bits/stdc++.h> //순열 주의점 

using namespace std;

int main(){
	cout << "정렬되어있지 않은 배열기반\n";
	int a[] = {1, 3, 2};
	do{
		for(int i : a) cout << i << " ";
		cout << '\n';
	}while(next_permutation(a, a + 3));
	cout << "정렬된 배열기반\n";
	int b[] = {1, 2, 3};
	do{
		for(int i : b) cout << i << " ";
		cout << '\n';
	}while(next_permutation(b, b + 3));
}
