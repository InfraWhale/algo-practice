#include<bits/stdc++.h> // DFS 문제
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m, k, y, x, ret, ny, nx, t;
int a [104][104]; 
bool visited[104][104];

void dfs(int y, int x) {
	visited[y][x] = 1;
	cout << y << " : " << x <<  "\n";
	for(int i = 0; i < 4; i++) {
		ny = y +dy[i];
		nx = x +dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if(a[ny][nx] == 1 && !visited[ny][nx]) {
			dfs(ny,nx);
		}
	}
	return;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
		cin >> a[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 1 && !visited[i][j]) {
				dfs(i, j);
				ret++;
				cout << ret << " : " << "\n";
			}
		}
	}

	cout << cnt << "\n";

	return 0;
} 
