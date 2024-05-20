#include<bits/stdc++.h> // 백준 1189 3Q 정답
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int n, m, k, visited[10][10];
char a[10][10];
string s;
int go(int y, int x) {
	if(y == 0 && x == m - 1) {
		if(k == visited[y][x]) return 1;
		return 0;
	}
	int ret = 0;
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i]; // (1) 만약 이걸 전역변수로 했다면
		int nx = x + dx[i];

		if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 'T' || visited[ny][nx]) continue;

		visited[ny][nx] = visited[y][x] + 1;
		ret += go(ny, nx);
		visited[ny][nx] = 0; // (2) 여기서 ny nx는 현재 함수가 아닌, 이전 재귀함수의 영향을 받음 -> 망함
		// 매개변수로 넘기는 경우는 지역변수로 하는게 맞다.
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}
	
	visited[n - 1][0] = 1;
	cout << go(n - 1, 0) << "\n";
}