#include <bits/stdc++.h> // 입력이 여러줄인 경우 - scanf로 받기 
using namespace std;
int a[10][10], n, m;
int main(){
	cin >> n >> m; //n에 값 입력 후 m에 값 입력 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &a[i][j]);
		}
	}
return 0;
}
