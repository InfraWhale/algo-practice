#include <bits/stdc++.h> // �پ��ִ°� �Է¹ޱ� - scanf�� �ޱ�
 
using namespace std;
int a[10][10], n, m;

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &a[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d",  a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
