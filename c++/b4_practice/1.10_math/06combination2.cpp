#include <cstdio> // 조합 - 중첩 for문 이용 
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
int n = 5;
int k = 3;
int a[5] = {1, 2, 3, 4, 5};

int main() {
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = j + 1; k < n; k++){
				cout << i << " " << j << " " << k << '\n';
			}
		}
	}
	return 0;
}
