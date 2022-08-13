#include <cstdio> // 중첩 for문을 이용한 조합 
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int n = 5;
int k = 3;
int a[5] = {11, 22, 33, 44, 55};

int main() {
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = j + 1; k < n; k++){
				cout << a[i] << " " <<  a[j] << " " <<  a[k] << '\n';
			}
		}
	}
	return 0;
}
