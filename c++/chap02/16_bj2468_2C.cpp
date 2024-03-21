#include<bits/stdc++.h> // 백준 2468 2C
using namespace std;

const int max_n = 101;
int a[max_n][max_n], visited[max_n][max_n], n, m, temp, ret;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void go(int y, int x) {
	visited[y][x] = 1;

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if(a[ny][nx] == 0) continue;
		if(visited[ny][nx]) continue;
		go(ny, nx);
	}
	a[y][x]--;
	return;
}

int main(){

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if(a[i][j] > m) {
				m = a[i][j]; // 주어진 높이의 최댓값을 구함 : m
			}
		}
	}

	for (int k = 0; k < m; k++) {

		temp = 0;
		fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0); // 초기화 시켜줘야 함
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++) {
				if(visited[i][j] == 0 && a[i][j] != 0){
					go(i, j);
					temp++; // 예비 최댓값
				}
			}
		}

		if (temp > ret) { // 더 큰 값이 나오면 최댓값을 업데이트
			ret = temp; 
		}
	}

	cout << ret << "\n";
	
    return 0;
}
