#include<bits/stdc++.h> // 백준 1987 정답
using namespace std;
const int max_n = 1501;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int R, C, y, x;
int visited[24][24], ca[26];
int a[24][24];
queue<pair<int, int>> q;

string s;

void go(int y, int x) {


	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = y + dx[i];
		if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || ca[ny][nx]);
	}
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

	



	return 0;
}