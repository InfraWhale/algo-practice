#include<bits/stdc++.h> // 백준 1987 3L
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int R, C, cnt, ret;
int visited[24][24], ca[26];
int a[24][24];
queue<pair<int, int>> q;

string s;

void go (int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || ca[a[ny][nx]]) continue;
		
		visited[ny][nx] = 1;
		cnt++;
		ca[a[ny][nx]] = 1;
		ret = max(cnt, ret);


		// cout << "a[ny][nx] : cnt / " << a[ny][nx] << " : " << cnt << "\n";
		go(ny, nx);

		visited[ny][nx] = 0;
		cnt--;
		ca[a[ny][nx]] = 0;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	cin >> R >> C;

	for(int i=0; i < R; i++) {
		cin >> s;
		for(int j=0; j < C; j++){
			a[i][j] = s[j] - 'A';
		}
	}

	ca[a[0][0]] = 1;
	ret = 1;
	cnt = 1;

	go(0, 0);

	cout << ret << "\n";

	return 0;
}