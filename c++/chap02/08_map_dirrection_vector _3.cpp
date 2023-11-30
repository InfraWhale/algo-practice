#include<bits/stdc++.h> // 맵과 방향벡터 3
using namespace std;

const int n = 3;
int a [n][n], visited[n][n];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void go(int y, int x) {
	visited[y][x] = 1;
	cout << y << " , " << x <<  "\n";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int ny = y +dy[i];
			int nx = x +dx[j];
			if(visited[ny][nx]) continue;
			cout << "->" << ny << " , " << nx << "\n";
			go(ny, nx);
		}
	}
	return;
}

int main(){

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == 0 && j == 0) a[0][0] = 1;
			else cin >> a[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] && visited[i][j] == 0) go(i, j);
		}
	}

	return 0;
} 
