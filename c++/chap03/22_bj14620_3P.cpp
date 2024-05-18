#include<bits/stdc++.h> // 백준 14620 3P
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int n, a[14][14], visited[14][14], f[3], ret = 987654321;

bool check(int y, int x) {
	if(visited[y][x]) return false;
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny > n || nx < 0 || nx > n) return false;
		if(visited[ny][nx]) return false;
	}
	return true;
}

void go(int cnt, int y, int x) {
	if(cnt == 3) {
		ret = min(ret, f[0] + f[1] + f[2]);
	}

	for(int i = y; i < n - 1; i++) {
		if(i != y) { // 다음 행으로 넘어가면, 열이 x가 아니라 1부터 시작하도록
			x = 1;
		}
		for(int j = x; j < n - 1; j++) {
			if(!check(i, j)) continue;

			visited[i][j] = 1;
			visited[i-1][j] = 1;
			visited[i+1][j] = 1;
			visited[i][j-1] = 1;
			visited[i][j+1] = 1;
			f[cnt] = a[i][j] + a[i-1][j] + a[i+1][j] + a[i][j-1] + a[i][j+1];
			
			go(cnt + 1, i, j);

			visited[i][j] = 0;
			visited[i-1][j] = 0;
			visited[i+1][j] = 0;
			visited[i][j-1] = 0;
			visited[i][j+1] = 0;
			f[cnt] = 0;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	go(0, 1, 1);

	cout << ret;

	return 0;
}