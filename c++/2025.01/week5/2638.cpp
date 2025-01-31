#include<bits/stdc++.h> // 백준 2638
using namespace std;

int n, m, cnt, clear_time;
int cheese[104][104], visited[104][104];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void bfs() {
	queue<pair<int, int>> que;
	que.push({0, 0});
	visited[0][0] = 1;

	while (que.size()) {
		int y, x;
		tie(y, x) = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny, nx;
			ny = y + dy[i];
			nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (cheese[ny][nx] == 0 && visited[ny][nx] == 0) {
				visited[ny][nx] = 1;
				que.push({ny, nx});
			} else if(cheese[ny][nx] == 1 && visited[ny][nx] != 2) {
				visited[ny][nx]++;
				if(visited[ny][nx] == 2) v.push_back({ny, nx});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	cnt = 0;
	clear_time = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cheese[i][j];
			if (cheese[i][j] == 1) {
				cnt++;
			}
		}
	}

	while(cnt > 0) {
		clear_time++;
		fill(&visited[0][0], &visited[0][0] + 104*104, 0);
		v.clear();

		bfs();

		for(pair<int, int> it : v) {
			int y, x;
			tie(y, x) = it;
			cheese[y][x] = 0;
			cnt--;
		}
	}

	cout << clear_time;

	return 0;
}