#include <bits/stdc++.h> // 2차원 배열 

using namespace std;
const int mxy = 3;
const int mxx = 4;
int a[mxy][mxx];

int main(){
	for(int i = 0; i < mxy; i++){
		for(int j = 0; j < mxx; j++){
			a[i][j] = (i + j);
		}
	}
	//good -> 캐시를 첫번째 차원 기준으로 함 : 성능을 위해 이 순서 추천 
	for(int i = 0; i < mxy; i++){
		for(int j = 0; j < mxx; j++){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	
	//bad
	for(int i = 0; i < mxx; i++){
		for(int j = 0; j < mxy; j++){
			cout << a[j][i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

