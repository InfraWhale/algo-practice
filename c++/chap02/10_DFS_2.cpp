#include<bits/stdc++.h> // DFS 문제
using namespace std;

int n, m, cnt;
int a [104][104], visited[104][104];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void go(int y, int x) {
	visited[y][x] = 1;
	cout << y << " : " << x <<  "\n";
	for(int i = 0; i < 4; i++) {
			int ny = y +dy[i];
			int nx = x +dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if(a[ny][nx] == 0) continue;
			if(visited[ny][nx]) continue;
			cout << "->" << ny << " , " << nx << "\n";
			go(ny, nx);
	}
	return;
}

int main(){

	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
		cin >> a[i][j];
		}
	}



	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] && visited[i][j] == 0) {
				cnt ++;
				go(i, j);
			}
		}
	}

	cout << cnt << "\n";

	return 0;
} 
