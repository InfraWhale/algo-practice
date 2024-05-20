#include<bits/stdc++.h> // 백준 1189 3Q
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int r, c, k, visited[10][10], ret;
char a[10][10];

void go(int y, int x, int dist) {
	if(dist == k) {
		if(y == 0 && x == (c - 1) && a[y][x] != 'T') {
			ret++;
		}
		return;
	}
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == 'T' || visited[ny][nx] == 1) continue;

		visited[ny][nx] = 1;
		go(ny, nx, dist+1);
		visited[ny][nx] = 0;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> r >> c >> k;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
	
	visited[r-1][0] = 1;
	go(r-1, 0, 1);

	cout << ret;

	return 0;
}