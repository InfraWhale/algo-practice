#include<bits/stdc++.h> // 백준 14442 답
using namespace std;

int n, m, k, ret, arr[1001][1001], visited[1001][1001][11];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs() {
	queue<tuple<int, int, int>> q;
	//fill(&visited[0][0], &visited[0][0] + 1001*1001, 0);

	q.push({0, 0, 0});
	visited[0][0][0] = 1;

	while (q.size()) {
		int y, x, broken;
		tie(y, x, broken) = q.front(); 
		// broken : 벽을 이 수만큼 부셨을 시의 최단거리가 visited 배열의 값으로 저장된다.
		// 0번 부셨을 때, 1번 부셨을 때가 다를 수 있음.
		q.pop();

		if (y == n-1 and x == m-1) return visited[y][x][broken];

		for (int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
				continue;
			}

			// 벽을 부수지 않고 이동
			if (arr[ny][nx] == 0 && visited[ny][nx][broken] == 0) {
				visited[ny][nx][broken] = visited[y][x][broken] + 1;
				q.push({ny, nx, broken});
			}

			// 벽을 부수고 이동
			if (arr[ny][nx] == 1 && broken < k && visited[ny][nx][broken+1] == 0) {
				visited[ny][nx][broken+1] = visited[y][x][broken] + 1;
				q.push({ny, nx, broken+1});
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}

	cout << bfs();
	
	return 0;
}