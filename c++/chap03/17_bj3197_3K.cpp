#include<bits/stdc++.h> // 백준 3197 (시간초과)
using namespace std;

char a[1504][1504];
int r, c, y, x, cnt;

int visited[1504][1504], visitedL[1504][1504];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> q, qq, qTemp, qqTemp;

void go() {
	while(qq.size()) {
		int b = qq.front().first;
		int d = qq.front().second;
		qq.pop();
		for(int i = 0; i < 4; i++) {
			int ny = b + dy[i];
			int nx = d + dx[i];
			if(ny < 0 || ny >= r || nx < 0 || nx >= c || visitedL[ny][nx]) continue;
			visitedL[ny][nx] = 1;
			if(a[ny][nx] == 'X') {
				qqTemp.push({ny, nx});
				continue;
			}
			if(a[ny][nx] == 'L') {
				cout << cnt << "\n"; 
				exit(0);
			}
			qq.push({ny, nx});
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	cin >> r >> c;

	for(int i=0; i < r; i++) {
		cin >> a[i];
		for(int j=0; j < c; j++){
			if(a[i][j] == '.' || a[i][j] == 'L') { // 'L' 기준으로도 탐색이 되어야 하므로
				q.push({i, j});
				visited[i][j] = 1;
			}
			if(a[i][j] == 'L') {
				y = i; x = j;
			}
		}
	}
	qq.push({y, x});
	visitedL[y][x] = 1;

	cnt = 0;
	while(true) {
		go();
		qq = qqTemp;
		qqTemp = queue<pair<int, int>>();

		cnt++;
		while(q.size()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for(int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) continue;
				visited[ny][nx] = cnt;
				if(a[ny][nx] == 'X') {
					a[ny][nx] = '.';
					qTemp.push({ny, nx});
				}
			}
		}
		q = qTemp;
		qTemp = queue<pair<int, int>>();
	}

	return 0;
}