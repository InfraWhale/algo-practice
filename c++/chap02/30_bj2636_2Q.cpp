#include<bits/stdc++.h> // 백준 2636 2Q (못품)
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m, cnt, ret, a[104][104], b[104][104], visited[104][104];
void dfs(int y, int x) {
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m) {
			continue;
		}
		if(a[ny][nx] == 1) {
			b[ny][nx] = 1;
		} 
		if(a[ny][nx] == 1 && !visited[ny][nx]) {
			dfs(ny,nx);
		}
	}
	return;
}
int main(){
	cin >> n >> m;
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	return 0;
}
