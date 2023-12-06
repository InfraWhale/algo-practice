#include<bits/stdc++.h> // 백준 2178 2A
using namespace std;

int n, m, ret;
string s;
int a[104][104]; int visited[104][104];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void go(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({y, x});
	while (q.size()) {
		pair<int, int> here = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];
			if(ny < 1 || ny > n || nx < 1 || nx > m) continue;
			if(a[ny][nx] == 0) continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx] = visited[here.first][here.second] + 1;

			// cout << ny << " : " << nx << " - " << visited[ny][nx] << "\n";

			q.push({ny,nx});
		}
	}
}

int main(){

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
		a[i][j] = s[j - 1] - '0';
		}
	}

	go(1, 1);
	
	cout << visited[n][m] << "\n";

    return 0;
} 
