#include<bits/stdc++.h> // 백준 3197 (시간초과)
using namespace std;
#define y1 xoxo
char a[1504][1504];
int r, c, y, x, cnt;
typedef pair<int, int> pii;
int visited[304][304], visitedL[304][304];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> q; 

void go(int y, int x) {
	visitedL[y][x] = 1;

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= r || nx < 0 || nx >= c || visitedL[ny][nx]) continue;
		if(a[ny][nx] == 'X') continue;
		if(a[ny][nx] == 'L') {
			cout << cnt << "\n";
			exit(0);
		}
		go(ny, nx);
	}
	return;
}

int main() {
	cin >> r >> c;

	for(int i=0; i < r; i++) {
		cin >> a[i];
		for(int j=0; j < c; j++){
			if(a[i][j] == '.') {
				q.push({i, j});
				visited[i][j] = 1;
			}
			if(a[i][j] == 'L') {
				y = i; x = j;
			}
		}
	}

	cnt = 0;
	fill(&visitedL[0][0], &visitedL[0][0] + 304*304, 0);
	go(y, x);
	while(true) {
		cnt++;
		queue<pair<int, int>> temp;
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
					temp.push({ny, nx});
				}
			}
		}
		fill(&visitedL[0][0], &visitedL[0][0] + 304*304, 0);
		go(y, x);
		q = temp;
	}

	return 0;
}