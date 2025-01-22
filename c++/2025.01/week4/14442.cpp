#include<bits/stdc++.h> // 백준 14442
using namespace std; // 1% 시간초과
int n, m, k, ret, arr[1001][1001], visited[1001][1001];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> v;

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	fill(&visited[0][0], &visited[0][0] + 1001*1001, 0);

	q.push({y, x});
	visited[y][x] = 1;

	while (q.size()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++){
			int ny = now_y + dy[i];
			int nx = now_x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || arr[ny][nx] == 1 || visited[ny][nx] != 0) {
				continue;
			}
			visited[ny][nx] = visited[now_y][now_x] + 1;
			if (ny == n-1 and nx == m-1) return visited[ny][nx];
			q.push({ny, nx});
		}
	}

	return 987654321;
}

void bt(int now, int depth) {
	if (depth == k) {
		ret = min(ret ,bfs(0, 0));
		return;
	}

	for (int i = now; i < v.size(); i++) {
		int y = v[i].first;
		int x = v[i].second;

		arr[y][x] = 0;
		bt(i+1, depth+1);
		arr[y][x] = 1;
	}
	return;
	
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
			if (arr[i][j] == 1) v.push_back({i, j});
		}
	}

	ret = 987654321;
	bt(0, 0);
	if (ret == 987654321) {
		cout << -1;
	} else {
		cout << ret;
	}
	
	return 0;
}